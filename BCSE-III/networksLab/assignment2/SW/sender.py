import socket
import time
import common as co
import random
import errorchecker as err

timeoutTime=5
frame_size=4


# Check if ack is valid using crc
def isValid(ack,sn):

	if(ack[0]!=str((sn+1)%2)):
		return False
	# Now check CRC
	if(int(err.modulo2div(ack,err.generator_poly),2)!=0):
		return False
	return True

# Function to send all the frames
def send_all(list_of_frames):
	sockSend=co.createSocket(co.portSenderSend) # sender socket to send data to channel
	c, addr=co.allowConn(sockSend)

	sockRec=co.createConn(co.portSenderReceive)	# Socket to receive data from channel
	sockRec.settimeout(timeoutTime)

	print('Connected to channel')
	# implementing stop and wait arq
	sn=0
	i=0
	while(i<(len(list_of_frames))): # While there are frames send
		print(15*'-')
		canSend=True
		sn=(i)%2
		stored_frame=list_of_frames[i]
		if(stored_frame!='#'):
			stored_frame=co.prepare_frame(list_of_frames[i],sn)
		print('Sending frame '+str(i)+' '+stored_frame)
		co.send_frame(stored_frame, c)		
		canSend=False
		
		try:
			ack=sockRec.recv(1024).decode()
		except Exception as e:
			# Resend so repeat this iteration of loop
			print('Timeout.. Resending')
			continue
		
		if(ack=='#'):
			break
		print('Ack received '+ack)
		if(ack and isValid(ack,sn)): # Wrong acknowledgement 
			print('Correct ack received')
			canSend=True
			i=i+1
		elif(not isValid(ack,sn)):
			# invalid ack so resend
			print('Wrong ack.. resending')

		print(15*'-')

	# Close the sockets
	sockSend.close()
	sockRec.close()

print('Demonstrating STOP AND WAIT ARQ')
list_of_frames=co.readfile('input.txt', frame_size)
list_of_frames.append('#')
print(list_of_frames)
send_all(list_of_frames)
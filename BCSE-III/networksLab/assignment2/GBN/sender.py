import socket
import time
import common as co
import random
import errorchecker as err
import threading

# Check if ack is valid using crc
def isValid(ack):
	# Now check CRC
	if(int(err.modulo2div(ack,err.generator_poly),2)!=0):
		return False
	return True

# Function to send list of frames
def sendFrame(list_of_frames):
	global sn
	global stored_buffer
	global sw
	i=0
	while True:
		# Store_frame(sn)
		stored_frame=list_of_frames[i]
		print('sn: '+str(sn)+' sf: '+str(sf)+' sw: '+str(sw))
		if(stored_frame!='#'):
			stored_frame=co.prepare_frame_gbn(list_of_frames[i],(i%(co.window_size+1)))
		# Else send the blank frame
		# If window size reached wait
		if((sn-sf)<sw):
			# Sendframe(sn)
			stored_buffer[sn%sw]=stored_frame
			print('Sending frame '+str(i)+' '+stored_frame)
			co.send_frame(stored_frame, sender)
			sn=(sn+1)

			if (i<len(list_of_frames)-1):
				i=i+1
		else:
			print('Window Size full')
		print(stored_buffer)
		time.sleep(5)

# Function to receive ack
def receiveFrame():
	global sf
	global sn
	global sw
	global stored_buffer

	while True:

		try:
			ack=sockRec.recv(1024).decode()
		except Exception as e:
			# Resend so repeat this iteration of loop
			print('Timeout.. Resending')
			resendThread=threading.Thread(target=resendFrameAfterTimeout, args=(stored_buffer,)) # create the resending thread
			resendThread.start()
			resendThread.join()
			continue

		print('Ack received '+str((ack[0:3])))
		if(ack !='#' and isValid(ack)): # Correct acknowledgement 
			print('Correct ack received')
			ackno=int(ack[0:3],2)
			print('Ackno '+str(ackno))
			# Purge required frames
			if(sn%(sw+1)<sf%(sw+1) and ackno<sf%(sw+1)):
				while((sf%(sw+1))>ackno):
					print('Deleting frame '+str(sf%sw))
					stored_buffer[sf%sw]=''
					sf=(sf+1)
				stored_buffer[sf%sw]=''

			if(ackno>=(sf%(sw+1)) and ackno<=(sn%(sw+1))):
				while((sf%(sw+1))<ackno):
					print('Deleting frame '+str(sf%sw))
					stored_buffer[sf%sw]=''
					sf=(sf+1)
				sf=sf+1

		elif(ack !='#' and not isValid(ack)): # Wrong ack
			# invalid ack so resend
			print('Wrong ack.. resending')

# Function to resend frame after timeout
def resendFrameAfterTimeout(list_of_frames):
	global sn
	global sf
	global stored_buffer

	# Resend frame
	temp=sf
	print('Resending '+str(sf))
	while(temp<sn):
		if(stored_buffer[temp%sw]!=''):
			print('Resending frame '+str(temp%(sw))+' '+stored_buffer[temp%sw])
			co.send_frame(stored_buffer[temp%sw], sender)
			time.sleep(5)
		temp=(temp+1)

# Function to send all the frames
def send_all(list_of_frames):
	
	sendThread=threading.Thread(target=sendFrame, args=(list_of_frames,)) # create the sending thread
	receiveThread=threading.Thread(target=receiveFrame) # create the receiving thread

	sendThread.start()
	receiveThread.start()


	sendThread.join()
	print('Send thread end')
	receiveThread.join()

	# Close the sockets
	sockSend.close()
	sockRec.close()

timeoutTime=17
frame_size=4
sw=co.window_size
sf=0
sn=0
# stored_buffer=[ '' for i in range(sw)]
stored_buffer={i:'' for i in range(sw)}

print('Demonstrating Go Back N ARQ')
list_of_frames=co.readfile('input.txt', frame_size)
print(list_of_frames)
list_of_frames.append('#') # Attach a blank frame

sockSend=co.createSocket(co.portSenderSend) # sender socket to send data to channel
sender, addr=co.allowConn(sockSend)

sockRec=co.createConn(co.portSenderReceive)	# Socket to receive data from channel
sockRec.settimeout(timeoutTime)

print('Connected to channel')

send_all(list_of_frames)
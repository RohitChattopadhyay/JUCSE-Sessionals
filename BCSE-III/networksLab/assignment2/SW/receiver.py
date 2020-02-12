import socket
import common as co
import time
import random
import errorchecker as err


# Function to check if frame is valid
def isValid(frame, rn):
	if(frame[0]!=str(rn)):
		return 0
	# Now check CRC
	if(int(err.modulo2div(frame,err.generator_poly),2)!=0):
		return 1
	return 2

def receive():
	# Establish connection
	sockRec=co.createSocket(co.portReceiverSend)
	c, addr=co.allowConn(sockRec)

	sockSend=co.createConn(co.portReceiverReceive)
	print('Connected to channel')
	
	# Connection established
	rn=0
	while True:
		# Wait till frame received
		print(15*'-')
		frame=sockSend.recv(1024).decode()
		
		print('Frame received '+frame)

		if(frame=='#'):
			ack='#'
		else:
			if(isValid(frame, rn)==0): # wrong frame no received send ack for prev
				print('Invalid frame')
				print('Sending ack for previous frame')
				ackno=(rn)%2

			elif(isValid(frame, rn)==1):
				print('Error in frame')
				continue

			else: # Valid frame
				ackno=(rn+1)%2

			# For valid data frame
			rn=(rn+1)%2
			# Send an acknowledgement
			ack=co.generateAck(ackno)
		# Send the ack
		print('Sending ack '+ack)
		co.send_frame(ack,c)

		if(frame=='#'): # Means end frame
			break
		print(15*'-')

	# Close the sockets
	sockSend.close()
	sockRec.close()

print('Demonstrating STOP AND WAIT ARQ')
receive()
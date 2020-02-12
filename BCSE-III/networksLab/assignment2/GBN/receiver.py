import socket
import common as co
import time
import random
import errorchecker as err


# Function to check if frame is valid
def isValid(frame, rn):
	if(int(err.modulo2div(frame,err.generator_poly),2)!=0):
		return False
	elif(int(frame[0:3],2)%(co.window_size+1)!=rn):
		return False
	return True

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
		print('Expecting: '+str(rn))
		print('Frame received '+frame)

		if(frame!='#' and not isValid(frame, rn)): # wrong frame no received send ack for prev
			print('Invalid frame..Not sending ack')
		elif(frame!='#'):
			ackno=frame[0:3]
			# Send an acknowledgement
			ack=co.generateAck_gbn(ackno)
			time.sleep(5)
			# Send the ack
			print('Sending ack '+ack)
			co.send_frame(ack,c)
			rn=(rn+1)%(co.window_size+1)
		else:
			# For valid frame
			ack='#'
			time.sleep(5)
			# Send the ack
			print('Sending ack '+ack)
			co.send_frame(ack,c)
			
		

		print(15*'-')	

	# Close the sockets
	sockSend.close()
	sockRec.close()

print('Demonstrating Go Back N ARQ')
receive()
import common as co
import socket

sockReceive=co.createConn(co.portReceiverSend)	# Socket to send data to channel
print('Connected to channel')

# Function to receive a frame
def receive_frame():

	while(True):
		# Receive the frame
		frame=sockReceive.recv(1024).decode()
		print('Frame received '+frame)

receive_frame()


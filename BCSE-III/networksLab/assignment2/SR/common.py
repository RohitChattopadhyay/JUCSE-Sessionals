import socket
import errorchecker as err

portSenderReceive=11001
portSenderSend=11002
portReceiverReceive=11003
portReceiverSend=11004
frame_size=4
m=2
window_size=2**m-1

# Function to introduce error
def ins_error(frame, list_of_bit):

	new=list(frame)

	# Inserting error in the given bit position here
	for i in range(len(list_of_bit)):		
		if(new[list_of_bit[i]]=='0'):
			new[list_of_bit[i]]='1'
		elif (new[list_of_bit[i]]=='1'):
			new[list_of_bit[i]]='0'
	new=''.join(new)
	return new

# Function to read the file and split into frames
def readfile(filename, frame_size):
	# Open the file for reading
	f=open(filename,'r')
	data=f.read()

	# Now split the data into frames
	list_of_frames=[data[i:i+frame_size] for i in range(0, len(data), frame_size)]
	return list_of_frames

# Function to prepare a frame
def prepare_frame(frame,sn):
	frame=str(sn)+frame
	# CRC application
	crcframe=err.crc([frame], err.generator_poly, frame_size)
	return crcframe[0]

def prepare_frame_gbn(frame,sn):
	sn=sn%(window_size+1)
	sn=bin(sn)
	sn=sn[2:].zfill(3)
	frame=str(sn)+frame
	# CRC application
	crcframe=err.crc([frame], err.generator_poly, frame_size)
	return crcframe[0]

# Function to generate ack
def generateAck(rn):
	# Generate crc appended code
	ack=bin(rn)[2:]
	crcframe=err.crc([ack], err.generator_poly, frame_size)
	return crcframe[0]

# Function to generate ack
def generateAck_gbn(ackno):
	# Generate crc appended code
	crcframe=err.crc([ackno], err.generator_poly, frame_size)
	return crcframe[0]

# Function to create a socket and bind it to a port
def createSocket(port):
	s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
	print("PORT",port)
	s.bind(('', port))
	return s

# Function to receive a connection
def allowConn(s):
	s.listen(5)
	c, addr=s.accept()
	return c, addr

# Function to create a socket and connect to it
def createConn(port):
	sock=socket.socket()
	sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
	sock.connect(('',port))
	return sock

# Function to send a frame
def send_frame(frame, c):
	# Send the frame to the other process
	c.send(frame.encode())

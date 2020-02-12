import socket
import common as co
import time
import random
import errorchecker as err

# Function to check if frame is valid
print("RECEIVER")
buffer = co.window_size*['']
bufferStatus = co.window_size*[0]
gCounter = 1
maxLen = len(buffer)
def isValid(frame, rn):
    global bufferStatus
    global maxLen
    try:        
        if(int(err.modulo2div(frame, err.generator_poly), 2) != 0):
            return False
        elif(int(frame[0:3], 2) >= maxLen):
            return False
        return True
    except:
        return False


def receive():
    # Establish connection
    global buffer
    global bufferStatus
    global maxLen
    global gCounter
    sockRec = co.createSocket(co.portReceiverSend)
    c, addr = co.allowConn(sockRec)

    sockSend = co.createConn(co.portReceiverReceive)
    print('Connected to channel')

    # Connection established
    rn = 0
    while True:
        # Wait till frame received
        print(15*'-')
        frame = sockSend.recv(1024).decode()
        print('Frame received '+frame)

        if(frame != '#' and not isValid(frame, rn)):  # wrong frame no received send ack for prev
            print('Invalid frame.Not sending ack')
        elif(frame != '#'):
            ackno = frame[0:3]
            ackNo = int(ackno, 2)
            buffer[ackNo] = frame[3:7]
            bufferStatus[ackNo] = gCounter
            # Send an acknowledgement
            ack = co.generateAck_gbn(ackno)
            time.sleep(5)	
            # Send the ack
            print('Sending ack '+ack)
            co.send_frame(ack, c)
            print("DEBUG:",sum(bufferStatus),maxLen*gCounter)
            if(sum(bufferStatus)>=maxLen*gCounter):
                file = open("output.txt","a")
                print("".join(buffer),end='',file=file)
                file.close()
                rn = (rn+1) % (co.window_size+1)
                buffer = co.window_size*['']
                gCounter = gCounter + 1
        else:
            # For valid frame
            maxLen = maxLen - 1
            ack = '#'
            time.sleep(5)
            # Send the ack
            print('Sending ack '+ack)
            co.send_frame(ack, c)
        print(str(bufferStatus))
        print(str(buffer))
        print(15*'-')

    # Close the sockets
    sockSend.close()
    sockRec.close()


print('Demonstrating Selective Repeat ARQ')
receive()

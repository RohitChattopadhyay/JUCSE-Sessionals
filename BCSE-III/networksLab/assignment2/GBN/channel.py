# This is the channel process
# First create the required sockets
import common as co
import random
import time
import threading

probas=10
randSendF=2 # Random probability of sending frame or not
randSendAck=2
randErrF=-1
randErrAck=-1

# **************** SENDER *****************************
sockSenderReceive=co.createConn(co.portSenderSend) # Socket to receive data from sender

sockSenderSend=co.createSocket(co.portSenderReceive)	# Socket to send data to sender
senderSend, addr=co.allowConn(sockSenderSend)
print('Channel connected to sender')
#*******************************************************

#****************** RECEIVER **************************
sockReceiverReceive=co.createConn(co.portReceiverSend) # Socket to receive data from receiver
# sockReceiverReceive.settimeout(11)

sockReceiverSend=co.createSocket(co.portReceiverReceive)	# Socket to send data to receiver
receiverSend, addr=co.allowConn(sockReceiverSend)
print('Channel connected to receiver')
#*******************************************************

def receiveFromSender():

    while True:
        print(15*'-')
        # Receive the frame from the sender
        stored_frame=sockSenderReceive.recv(1024).decode()
        print('Frame received from sender '+stored_frame)
        # Insert error and other stuffs here

        # Send frame with a probability p
        p=random.randint(0,probas)
        if(p>=randSendF or len(stored_frame)<8): # Ending marker should always be sent
            # Introduce error here with a probability
            p2=random.randint(0,probas)
            if(p2<=randErrF and len(stored_frame)>=8):
                print("Introducing error")
                stored_frame=co.ins_error(stored_frame,[1])
            
            # Send the frame to the receiver
            print('Sending frame to receiver '+stored_frame)
            # Add sleep here
            # time.sleep(7)
            co.send_frame(stored_frame, receiverSend)
            print('Sent frame '+stored_frame)
            if(stored_frame=='#'):
                break
        # Dont Send the frame
        else:
            print('Not sending frame')
        print(15*'-')

def receiveAckFromReceiver():

    while True:
        print(15*'=')
        # Wait ack from receiver
        ack=sockReceiverReceive.recv(1024).decode()
        print('Ack received from receiver '+ack)

        if(ack=='#'):
            break
        # Insert error and other stuffs here
    
        # send the frame with a probability
        p=random.randint(0,probas)
        if(p>=randSendAck):
            # Introduce error here with a probability
            p2=random.randint(0,probas)
            if(p2<=randErrAck):
                print("Introducing error")
                ack=co.ins_error(ack,[1])

            print('Sending ack to sender '+ack)
            # Add sleep here
            # time.sleep(7)
            # Send the ack to the sender
            co.send_frame(ack, senderSend)
        else:
            print('Not sending acknowledgement')
        print(15*'=')		

def mainChannel():

    sendThread=threading.Thread(target=receiveFromSender) # create the sending thread
    receiveThread=threading.Thread(target=receiveAckFromReceiver) # create the receiving thread

    receiveThread.start()
    sendThread.start()

    sendThread.join()
    receiveThread.join()

mainChannel()

sockSenderReceive.close()
sockSenderSend.close()
sockReceiverReceive.close()
sockReceiverSend.close()

import random,os
from math import log,ceil
os.system("rm *.txt")
class Station: # Class for denoting every station
	
	def __init__(self, stn_num, num_data, cdma_code, frames):
		self.stn_num=stn_num
		self.num_data=num_data
		self.cdma_code=cdma_code
		self.frames=frames

	# Send data corresponding to index of frame list
	def sendData(self,index):

		if(self.frames[index]=='_'): # Meaning idle
			data=0
		elif(self.frames[index]=='0'):
			data=-1
		else:
			data=1

		codeword=[data*self.cdma_code[i] for i in range(len(self.cdma_code))]
		print("[SENDING] Station {}:\t{}".format(self.stn_num,"\t".join(map(str, codeword))))
		return codeword

# Function to create walsh tables
def createWalsh(r):
	global walsh
	walsh=[[int(bin(x&y),13)%2 or -1 for x in range(r)]for y in range(r)]


# Decode dataword for every station
def decode_cdma(codeword, num_stn, max_num_stn):
	for i in range(num_stn):
		data=[codeword[j]*walsh[i][j] for j in range(len(walsh[i]))]
		data=sum(data)
		data=int(data/max_num_stn)
		with open("op_station_{}.txt".format(chr(65+i)), 'a') as opfile:			
			if(data==-1):
				data=0
				opfile.write(str(data))
			elif(data==0):
				opfile.write("_")
			else:
				opfile.write(str(data))


def simulate():
	num_stn = input('Enter number of stations:\t')
	num_stn=int(num_stn)

	max_num_stn=2**(ceil(log(num_stn,2)))

	num_data = input('Enter binary string length:\t')
	num_data=int(num_data)

	createWalsh(max_num_stn)
	with open("op_walsh.txt", 'w') as opfile:
		for x in walsh:
			print(*x, sep='\t',file=opfile)

	stns=[]

	for i in range(num_stn):
		frames = input('Station {} | Enter a binary string of length {}:\t'.format(i,num_data))
		frames=list(frames)

		# Now create the station object
		tempstn=Station(chr(65+i),num_data,walsh[i],frames)
		stns.append(tempstn)
	print("\nTransmitting")
	for i in range(num_stn,max_num_stn):
		frames=num_data*'_'
		frames=list(frames)
		tempstn=Station(i,num_data,walsh[i],frames)
		stns.append(tempstn)


	# Send data for every data
	for i in range(num_data):
		code=[0 for i in range(max_num_stn)]
		# Send for every station
		for j in range(max_num_stn):
			code = [x+y for x,y in zip(code, stns[j].sendData(i))]
		print("SENT BIT {}\n".format(1+i))
		with open("channel.txt", 'a') as opfile:
			print("\t".join(map(str,code)),file=opfile)

		decode_cdma(code,num_stn,max_num_stn)

walsh=[]
simulate()
print("\nTransmission Complete")

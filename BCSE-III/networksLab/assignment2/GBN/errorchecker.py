# Customisable parameters
generator_poly='1001'
no_of_bits=len(generator_poly)

# Function to find checksum of a number of frames
def checksum(list_of_frames, no_of_bits):
	chksum=0

	for frame in list_of_frames:
		chksum=chksum+int(frame,2) # Computing the sum
	# Wrapping the sum
	csum=bin(chksum)
	csum=csum[2:]

	while(len(csum)>no_of_bits):
		first=csum[0:len(csum)-no_of_bits]
		second=csum[len(csum)-no_of_bits:]
		s=int(first,2)+int(second,2)
		csum=bin(s)
		csum=csum[2:]

	# Perform 1s complement
	while(len(csum)<no_of_bits):
		csum='0'+csum
	chksum=''
	for i in range(len(csum)):
		if(csum[i]=='0'):
			chksum+='1'
		else:
			chksum+='0'
		
	return chksum

# Function to generate the LRC code for a list of frames
def lrc(list_of_frames, no_of_bits):
	lsum=0

	for frame in list_of_frames:
		lsum=lsum^int(frame,2)
	lsum=bin(lsum)[2:]
	
	# Stuffing
	while(len(lsum)<no_of_bits):
		lsum='0'+lsum
	return lsum

# Returns codeword for each dataword using vrc
def vrc(list_of_frames):

	codewords=[]
	for i in range(len(list_of_frames)):
		# For every frame check if the parity in even or odd
		dataword=list_of_frames[i]
		if(dataword.count('1')%2==0):
			dataword+='0'
		else:
			dataword+='1'
		codewords.append(dataword)

	return codewords

# Function ot xor two binary strings
def xor(a,b):
	a=int(a,2)
	b=int(b,2)
	a=a^b
	a=bin(a)[2:]
	return a

# Function to perform modulo 2 division
def modulo2div(dataword, generator):

	# Number of bits to be XORed a time
	l_xor=len(generator)
	tmp=dataword[0:l_xor]

	while (l_xor<len(dataword)):
		if(tmp[0]=='1'):
			# If leftmost bit is 1 simply xor and bring the next bit down
			tmp=xor(generator,tmp)+dataword[l_xor]
		else:
			# If leftmost bit is 0 then use all 0 divisor
			tmp=xor('0'*len(generator),tmp)+dataword[l_xor]
		tmp='0'*(len(generator)-len(tmp))+tmp

		l_xor+=1

	# For the last bit
	if(tmp[0]=='1'):
		tmp=xor(generator,tmp)
	else:
		tmp=xor('0'*len(generator),tmp)
	tmp='0'*(len(generator)-len(tmp)-1)+tmp
	checkword=tmp
	return checkword


# Return the codeword for crc
def crc(list_of_frames, generator, no_of_bits):

	codewords=[]
	for i in range(len(list_of_frames)):
		# For every dataword perform crc division
		dataword=list_of_frames[i]
		# Append length of generator-1 bits to dataword
		aug_dataword=dataword+'0'*(len(generator)-1)

		# Now perform the modulo 2 division
		checkword=modulo2div(aug_dataword,generator)
		# Append the remainder
		codeword=dataword+checkword
		codewords.append(codeword)

	return codewords
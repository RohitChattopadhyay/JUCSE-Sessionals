polynomial = "10001"
def make_frame(i,o):
	f1=open(i,'r')
	f2=open(o,'w')
	s=f1.read()
	# n=int(input('Enter frame size: '))
	n=8
	l=[s[i:min(i+n,len(s))] for i in range(0, len(s), n)]
	f2.write('\n'.join(l)[:-1])
	f1.close()
	f2.close()

def vrc_frame(i,o):
	f1=open(i,'r')
	f2=open(o,'w')
	l=f1.readlines()
	for d in l:
		dt=d[:-1]
		r=0
		for a in dt:
			r=int(a)^r
		dt+=str(r)
		f2.write(dt+'\n')
	f1.close()
	f2.close()
	
def introduce_error(i,o,e=1):
	f1=open(i,'r')
	f2=open(o,'w')
	l=f1.readlines()
	import random
	for d in l:
		dt=d[:-1]
		# r=random.choice([0,1])
		# if r==0 or e==2:
		# 	f2.write(dt+'\n')
		# 	continue
		tmp=''
		i=0
		for a in dt:
			r=random.choice([0,1])
			if i!=2 and i!=3 and i!=5:
				tmp+=a
			else:
				tmp+=str(1-int(a))
			i = i+1
		f2.write(tmp+'\n')
	f1.close()
	f2.close()
	
def chk_vrc_frame(i,o):
	f1=open(i,'r')
	f2=open(o,'w')
	l=f1.readlines()
	for d in l:
		dt=d[:-1]
		r=0
		for a in dt:
			r=int(a)^r
		if r==0:
			f2.write(dt+';PASS\n')
		else:
			f2.write(dt+';FAIL\n')
	f1.close()
	f2.close()
	
def lrc_frame(i,o):
	f1=open(i,'r')
	f2=open(o,'w')
	l=f1.readlines()
	lrb=''
	for i in range(len(l[0])-1):
		r=0
		for d in l:
			r=int(d[i])^r
		lrb+=str(r)
	f2.write(''.join(l)+lrb+'\n')
	f1.close()
	f2.close()
	
def chk_lrc_frame(i,o):
	f1=open(i,'r')
	f2=open(o,'w')
	l=f1.readlines()
	rslt='PASS'
	for i in range(len(l[0])-1):
		r=0
		for d in l:
			r=int(d[i])^r
		if r!=0:
			rslt='FAIL'
			break
	f2.write(rslt+'\n'+''.join(l))
	f1.close()
	f2.close()
	
def make_checksum(i):
	f1=open(i,'r')
	l=f1.readlines()
	n=len(l[0])-1
	while len(l)>1:
		s=0
		for d in l:
			s+=eval('0b'+d[:-1])
		s=str(bin(s))[2:]
		l=[]
		while len(s)>n:
			l.append(s[len(s)-n:len(s)]+'\n')
			s=s[:len(s)-n]
		l.append(s+'\n')
	s=str(bin(eval('0b'+n*'1')-eval('0b'+(n-len(s))*'0'+s)))[2:]
	f1.close()
	return s

def checksum_frame(i,o):
	s=make_checksum(i)
	f1=open(i,'r')
	f2=open(o,'w')
	l=f1.readlines()
	f2.write(''.join(l)+s+'\n')
	f1.close()
	f2.close()
	
def chk_checksum_frame(i,o):
	s=make_checksum(i)
	f1=open(i,'r')
	f2=open(o,'w')
	l=f1.readlines()
	rslt='PASS'
	if int(s)!=0:
		rslt='FAIL'
	f2.write(rslt+'\n'+''.join(l))
	f1.close()
	f2.close()

def make_crc(s,px):
	for i in range(len(s)-len(px)+1):
		if s[i]=='0':
			tmp='0'*len(px)
		else:
			tmp=px
		for j in range(len(px)):
			if s[i+j]==tmp[j]:
				s=s[:i+j]+'0'+s[i+j+1:]
			else:
				s=s[:i+j]+'1'+s[i+j+1:]
	return s[-len(px)+1:]

def crc_frame(i,o):
	f1=open(i,'r')
	f2=open(o,'w')
	# px=input('Enter the generator function (using 0 and 1, 1st co-eff. must be 1): ')
	px = polynomial
	l=f1.readlines()
	for d in l:
		dt=d[:-1]+(len(px)-1)*'0'
		f2.write(d[:-1]+make_crc(dt,px)+'\n')
	f1.close()
	f2.close()
	
def chk_crc_frame(i,o):
	f1=open(i,'r')
	f2=open(o,'w')
	# px=input('Enter the generator function (using 0 and 1, 1st co-eff. must be 1): ')
	px = polynomial
	l=f1.readlines()
	for d in l:
		crc=make_crc(d[:-1],px)
		rslt='PASS'
		if int(crc)!=0:
			rslt='FAIL'
		f2.write(d[:-1]+';'+rslt+'\n')
	f1.close()
	f2.close()

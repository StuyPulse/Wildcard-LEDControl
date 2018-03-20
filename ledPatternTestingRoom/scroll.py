#!usr/bin/python

LEDlist = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

def move1():
	i = 0
	while i<len(LEDlist):
		if (LEDlist[i]):
			if (i+1>=len(LEDlist)):
				LEDlist[0] = 1
			else:
				LEDlist[i+1] = 1
			LEDlist[i] = 0
			i+=2
		else:
			i+=1
	print LEDlist

for i in range(0,len(LEDlist)):
	if (not(i%3)):
		LEDlist[i] = 1
print LEDlist
move1()
move1()
move1()
move1()
move1()
move1()


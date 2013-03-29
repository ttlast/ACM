import math
testt = raw_input().split()

r1 = -1;
for i in xrange(1,len(testt)):
	v = int(testt[i])
	if(v > r1): r1 = v

testt = raw_input().split()
p1 = -1
for i in xrange(1,len(testt)):
	v = int(testt[i])
	if(v > p1): p1 = v

testt = raw_input().split()
p2 = 5000
for i in xrange(1,len(testt)):
	v = int(testt[i])
	if(v < p2): p2 = v

test = raw_input().split()
a,b = (int(x) for x in test)

r2 = b*p1*r1*r1*1.0/(a*p2+b*p1)
print math.sqrt(r2)


n = int(raw_input())
seta = []
dd = raw_input().split();
for i in dd:
	ta = int(i)
	seta.append(ta);

m = int(raw_input())
setb = []
dd = raw_input().split();
for i in dd:
	tb = int(i)
	setb.append(tb)

nummax = 0
sum = 0
for i in xrange(n):
	for j in xrange(m):
		if(setb[j] % seta[i] == 0):
			if(setb[j]/seta[i] > nummax):
				nummax = setb[j]/seta[i];
				sum = 1;
			elif(setb[j]/seta[i] == nummax):
				sum += 1;
print sum


n,m = (int(x) for x in raw_input().split())

ret = 0;

for i in xrange(n):
	t,T,x,cost = (int(x) for x in raw_input().split())
	if t >= T:
		s = cost + m*x
	else:
		s = min(cost + m*x, m/(t-T)*-cost)
	ret += s

print ret

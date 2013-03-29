#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
typedef __int64 LL;

int main()
{
	LL n,k,ans,l,r,mid,v,tmp;
	scanf("%I64d%I64d",&n,&k);
	l = 1,r = n;
	while(l <= r)
	{
		mid = (l+r)>>1;
		v = mid;
		tmp = 0;
		while(v > 0)
		{
			tmp += v;
			v /= k;
		}
		if(tmp >= n) r = mid - 1;
		else l = mid + 1;
	}
	printf("%I64d\n",l);
	return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
typedef long long LL;
inline LL check(LL x)
{
	LL t = 0;
	LL u;
	u = x;
	do
	{
		if(u%2)
			u = u*3+1;
		else
			u /= 2;
		t ++;
	}while(u > 1);
	return t;
}
int main()
{
	LL i,l,r,ans,s,d,tmp,tm;
	while(scanf("%lld%lld",&l,&r),l|r)
	{
		s = l;
		d = r;
		if(s > d)
		{
			tm = s;
			s = d;
			d = tm;
		}
		ans = tm = 0;
		for(i = s;i <= d;i ++)
		{
			tmp = check(i);
			if(tmp > ans)
				ans = tmp,tm = i;
		}
		printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",s,d,tm,ans);
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
typedef long long LL;
inline LL check(LL x,LL limit)
{
	LL t = 1;
	LL u;
	u = x;
	while(u > 1)
	{
		if(u%2)
			u = u*3+1;
		else
			u /= 2;
		if(u > limit)
			break;
		t ++;
	}
	return t;
}
int main()
{
	LL l,r,ans;
	int ncase = 0;
	while(scanf("%lld%lld",&l,&r),(l+1)|(r+1))
	{
		ans = 0;
		ans = check(l,r);
		ncase ++;
		printf("Case %d: A = %lld, limit = %lld, number of terms = %lld\n",ncase,l,r,ans);
	}
	return 0;
}
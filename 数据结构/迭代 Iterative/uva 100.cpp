#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
typedef long long LL;
const int maxn = 1000000;

int dp[maxn];

void check(int x)
{
	int t = 0;
	LL u;
	u = x;
	dp[x] = 1;
	while(u > 1)
	{
		if(u%2)
			u = u*3+1;
		else
			u /= 2;
		t ++;
		if(x > u)
		{
			dp[x] = t + dp[u];
			break;
		}
	}
}
int main()
{
	int i,l,r,ans,s,d,tm;
	for(i = 1;i < maxn;i ++)
		check(i);
	while(scanf("%d%d",&l,&r)!=EOF)
	{
		s = l;
		d = r;
		if(s > d)
		{
			tm = s;
			s = d;
			d = tm;
		}
		ans = dp[s];
		for(i = s+1;i <= d;i ++)
			ans = max(ans,dp[i]);
		printf("%d %d %d\n",l,r,ans);
	}
	return 0;
}
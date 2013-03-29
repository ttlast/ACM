#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 32;

LL num[maxn],n,k,ans;

LL gcd(LL a,LL b)
{
	if(b == 0)
		return a;
	return gcd(b,a%b);
}

LL dfs(LL val,int s,int e)
{
	int i;
	LL ans = 0;
	if(val > n)
		return 0;
	if(e == 0)
	{
		return n/val;
	}else{
		if(s >= k) return 0;
		ans += dfs(val*num[s]/gcd(val,num[s]),s+1,e-1);
		ans += dfs(val,s+1,e);
	}
	return ans;
}

void check()
{
	int i,j;
	for(i = 1;i <= k;i ++)
	{
		if(i&1)
			ans -= dfs(1,0,i);
		else
			ans += dfs(1,0,i);
	}
}
int main()
{
	int i,j;
	while(scanf("%lld%lld",&n,&k)!=EOF)
	{
		ans = n;
		for(i = 0;i < k;i ++)
			scanf("%lld",&num[i]);
		check();
		printf("%lld\n",ans);
	}
	return 0;
}
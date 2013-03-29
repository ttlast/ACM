#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
typedef long long LL;

LL F(LL x)
{
	while(x%10 == 0 && x > 0)
				x /= 10;
	return x%10;
}

LL ans,p,q;
void dfs(LL x,LL y)
{
	LL i;
	if(y - x <= 10)
	{
		for(i = x;i <= y;i ++)
		{
			ans += F(i);
		}
		return ;
	}
	
	while(x%10)
	{
		ans += F(x);
		x ++;
	}
	while(y%10)
	{
		ans += F(y);
		y --;
	}
	x /= 10;
	y /= 10;

	ans += (y-x)*45;
	dfs(x,y);
}

void solve()
{
	ans = 0;
	dfs(p,q);
	printf("%lld\n",ans);
}
int main()
{
	
	while(scanf("%lld%lld",&p,&q),(p+1)|(q+1))
	{
		solve();
	}
	return 0;
}
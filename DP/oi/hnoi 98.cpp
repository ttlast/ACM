#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
//系统可靠性  ， 一维背包
const int maxn = 10000;
int p[maxn],c[maxn];
int dp[maxn];
int main()
{
	int n,m,i,j;
	while(scanf("%d%d",&n,&m)!= EOF)  //n 费用总数 ， m 部件总数 ,每个部件可以买无数个。
	{
		for(i = 0;i < m;i ++)
		{
			scanf("%d%d",&c[i],&p[i]);
		}
		memset(dp,0,sizeof(dp));
		for(i = 0;i < m;i ++)
		{
			for(j = c[i];j <= n;j ++)
			{
				dp[j] = max(dp[j],dp[j-c[i]] + p[i]);
			}
		}
		// dp 中最大的那个就是啦，
	}
	return 0;
}
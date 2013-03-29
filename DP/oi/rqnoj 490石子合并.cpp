#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 500;
const int inf = 1000000000;
int q[maxn];
int dp[maxn][maxn],mind,dpm[maxn][maxn],maxd;
int main()
{
	int n,i,j,k,m;
	while(scanf("%d",&n)!=EOF)
	{
		for(i = 0;i < n;i ++)
		{
		  scanf("%d",&q[i]);
		  if(i > 0) q[i] += q[i-1];
		}
		for(j = 0;j < n-1;j ++,i ++)
		{
			q[i] = q[n-1] + q[j];
		}
		m = n*2 - 1;
		memset(dp,0,sizeof(dp));
		memset(dpm,0,sizeof(dpm));
		for(i = 1;i < n;i ++)
		{
			for(j = 0;j < m - i;j ++)
			{
				dp[j][j+i] = inf;
				for(k = j;k <= j+i;k ++)
				{
					dp[j][j+i] = min(dp[j][j+i],dp[j][k] + dp[k+1][j+i]);
					dpm[j][j+i] = max(dpm[j][j+i],dpm[j][k] + dpm[k+1][j+i]);
				}
				if(j > 0) 	dp[j][j+i] += q[j+i] - q[j-1],dpm[j][j+i] += q[j+i] - q[j-1];
				else dp[j][j+i] += q[j+i],dpm[j][j+i] += q[j+i];
			}
		}
		mind = inf;maxd = 0;
		for(i = 0;i < n;i ++) 
		{
			if(dp[i][i+n-1] < mind) mind = dp[i][i+n-1];
			if(dpm[i][i+n-1] > maxd) maxd = dpm[i][i+n-1];
		}
		printf("%d\n%d\n",mind,maxd);
	}
	return 0;
}
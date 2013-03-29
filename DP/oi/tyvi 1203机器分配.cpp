#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 105;
int main()
{
	int i,j,k;
	int  lr[maxn][maxn],dp[maxn][maxn],maxd;
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i = 1;i <= n;i ++)
		   for(j = 1;j <= m;j ++)
			   scanf("%d",&lr[i][j]);
		maxd = -1000000000;
		for(i = 1;i <= m;i ++) dp[1][i] = lr[1][i];
		for(i = 2;i <= n;i ++)
			for(j = 1;j <= m;j ++)
			{
				dp[i][j] = dp[i-1][j];
				for(k = 1;k <= j;k ++)
				{
				    dp[i][j] = max(dp[i][j],dp[i-1][j-k] + lr[i][k]);
				}
				if(dp[i][j] > maxd) maxd = dp[i][j];
			}
		printf("%d\n",maxd);
	}

	return 0;
}
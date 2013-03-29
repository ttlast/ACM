#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 10000000;
const int maxn = 1005;
int dp[30][90];
struct Node{
	int t,a,w;
};
Node mat[maxn];
int main()
{
	int i,j,k;
	int n,t,a,c;
	scanf("%d",&c);
	while(c --)
	{
		scanf("%d%d",&t,&a);
		scanf("%d",&n);
		for(i = 0;i < n;i ++)
			scanf("%d%d%d",&mat[i].t,&mat[i].a,&mat[i].w);
		for(i = 0;i <= t+1;i ++)
			for(j = 0;j <= a+1;j ++)
				dp[i][j] = inf;
		dp[0][0] = 0;
		for(i = 0;i < n;i ++)
		{
			for(j = t;j >= mat[i].t;j --)
				for(k = a;k >= mat[i].a;k --)
					dp[j][k] = min(dp[j][k],dp[j-mat[i].t][k-mat[i].a] + mat[i].w);
			for(j = t;j >= 0;j --)
				for(k = a;k >= 0;k --)
					dp[j][k] = min(dp[j][k],min(dp[j+1][k],dp[j][k+1]));
		}
		printf("%d\n",dp[t][a]);
	}
	return 0;
}
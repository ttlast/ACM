#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
const int maxn = 44;
int mat[maxn][maxn];
int dp[88][88],dp1[88][88];
int getId(int v,int n)
{
	return v >= n ? (v - n):v;
}
int main()
{
	int n,t,i,j,l,len;
	int v,u,m;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d",&n);
		for(i = 0;i < n;i ++)
			for(j = 0;j < n;j  ++)
				scanf("%d",&mat[i][j]);
		memset(dp,0,sizeof(dp));
		memset(dp1,0,sizeof(dp1));
		len = n * 2 - 1;
		//能否成环
		//dp[i][j]  i  ~ j-1 能成环
		for(i = 0;i <= len;i ++) dp[i][i+1] = 1;
		for(l = 2;l <= n;l ++)
		{
			for(i = 0;i < len;i ++)
			{
			  u = getId(i,n);
			  m = getId(i+l,n);
			  for(j = i+1;j < i+l;j ++)
			  {
				 v = getId(j,n);
				 if(dp[i][j]&&dp[j][i+l])
				 {
					 if(mat[u][v]||mat[m][v])
					 {
						 dp[i][i+l] = 1;
						 break;
					 }
				 }
			  }
			}
		}
		for(i = 0;i < n;i ++)
				if(dp[i][i+n]) printf("1\n");
				else printf("0\n");
			printf("\n");

	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
int mat[3],n;
ll dp[2][3];
int main()
{
	int i,j,ncase = 1;
	while(scanf("%d",&n)!=EOF)
	{
		if(n == 0) break;
		scanf("%d%d%d",&mat[0],&mat[1],&mat[2]);
		dp[0][0] = 0;dp[0][1] = mat[1];
		dp[0][2] = mat[1] + mat[2];
		for(i = 1;i < n;i ++)
		{
			scanf("%d%d%d",&mat[0],&mat[1],&mat[2]);
			if(i == 1)
			{
			   dp[1][0] = mat[0] + dp[0][1];
			   dp[1][1] = mat[1] + min(dp[1][0],min(dp[0][1],dp[0][2]));
			   dp[1][2] = mat[2] + min(dp[1][1],min(dp[0][1],dp[0][2]));
			}else
			{
			   dp[1][0] = mat[0] + min(dp[0][0],dp[0][1]);
			   dp[1][1] = mat[1] + min(dp[1][0],min(dp[0][2],min(dp[0][0],dp[0][1])));
			   dp[1][2] = mat[2] + min(dp[1][1],min(dp[0][1],dp[0][2]));
			}
			dp[0][0] = dp[1][0];dp[0][1] = dp[1][1];dp[0][2] = dp[1][2];
		}
		printf("%d. %lld\n",ncase ++,dp[1][1]);
	}
	return 0;
}
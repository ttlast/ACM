#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
LL M = 1000000000000000000LL;
int a[81];
LL dp[81][81][3];
int main()
{
	int n,m;
	LL ans1[3],ans2[3];
	bool sign = true;
	LL ans[3];
	int i,j,k;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		ans[0] = ans[1] = ans[2] = 0;
		if(sign) sign = false;
		else printf("\n");
		for(i = 0;i < n;i ++)
		{
			for(j = 0;j < m;j ++)
			{
				scanf("%d",&a[j]);
			}
			for(j = 0;j < m;j ++)
				for(k = 0;k < m;k ++)
					dp[j][k][0] = dp[j][k][1] = dp[j][k][2] = 0;
			for(j = 0;j < m;j ++)
				dp[j][j][0] = a[j]*2;
			for(k = 1;k < m;k ++)
			{
				for(j = 0;j < m - k;j ++)
				{
					ans1[0] = ans1[1] = ans1[2] = 0;
					ans2[0] = ans2[1] = ans2[2] = 0;
					//1
					ans1[0] = dp[j][j+k-1][0]*2 + a[j+k]*2;
					ans1[1] = dp[j][j+k-1][1]*2 + ans1[0]/M;
					ans1[0] %= M;
					ans1[2] = dp[j][j+k-1][2]*2 + ans1[1]/M;
					ans1[1] %= M;
					//2
					ans2[0] = dp[j+1][j+k][0]*2 + a[j]*2;
					ans2[1] = dp[j+1][j+k][1]*2 + ans2[0]/M;
					ans2[0] %= M;
					ans2[2] = dp[j+1][j+k][2]*2 + ans2[1]/M;
					ans2[1] %= M;
					if(ans2[2] > ans1[2])
					{
						dp[j][j+k][0] = ans2[0];
						dp[j][j+k][1] = ans2[1];
						dp[j][j+k][2] = ans2[2];
					}else if(ans2[2] < ans1[2])
					{
						dp[j][j+k][0] = ans1[0];
						dp[j][j+k][1] = ans1[1];
						dp[j][j+k][2] = ans1[2];
					}else if(ans2[2] == ans1[2])
					{
						if(ans2[1] > ans1[1])
						{
							dp[j][j+k][0] = ans2[0];
							dp[j][j+k][1] = ans2[1];
							dp[j][j+k][2] = ans2[2];
						}else if(ans2[1] < ans1[1])
						{
							dp[j][j+k][0] = ans1[0];
							dp[j][j+k][1] = ans1[1];
							dp[j][j+k][2] = ans1[2];
						}else if(ans2[1] == ans1[1])
						{
							if(ans2[0] > ans1[0])
							{
								dp[j][j+k][0] = ans2[0];
								dp[j][j+k][1] = ans2[1];
								dp[j][j+k][2] = ans2[2];
							}else if(ans2[0] < ans1[0])
							{
								dp[j][j+k][0] = ans1[0];
								dp[j][j+k][1] = ans1[1];
								dp[j][j+k][2] = ans1[2];
							}else if(ans2[0] == ans1[0])
							{
								dp[j][j+k][0] = ans1[0];
								dp[j][j+k][1] = ans1[1];
								dp[j][j+k][2] = ans1[2];
							}
						}
					}
				}
			}
			ans[0] = ans[0] + dp[0][m-1][0];
			ans[1] = ans[1] + dp[0][m-1][1] + ans[0]/M;
			ans[0] %= M;
			ans[2] = ans[2] + dp[0][m-1][2] + ans[1]/M;
			ans[1] %= M;
		}
		if(ans[2] > 0)
		{
			printf("%lld%lld%018lld\n",ans[2],ans[1],ans[0]);
		}else if(ans[1] > 0)
		{
			printf("%lld%018lld\n",ans[1],ans[0]);
		}else printf("%lld\n",ans[0]);
	}
	return 0;
}
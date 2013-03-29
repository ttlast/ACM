#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
//#define Debug
using namespace std;
const int maxn = 1005;
char a[maxn],b[maxn];
int n,m,k;
int l[maxn][maxn],dp[maxn][maxn];
int main()
{
	int i,j,ln;
	while(scanf("%d",&k))
	{
		if(k == 0) break;
		gets(a);
		gets(a);
		gets(b);
		n = strlen(a);
		m = strlen(b);
		/*
		for(i = 1;i <= n;i ++)
			for(j = 1;j <= m;j ++)
			{
				dp[i][j] = 0;
				l[i][j] = max(l[i][j-1],l[i-1][j]);
				if(a[i-1] == b[j-1])
				{
					dp[i][j] = dp[i-1][j-1] + 1;
					if(dp[i][j] >= k)
					{
						for(ln = k;ln <= dp[i][j];ln ++)
							l[i][j] = max(l[i][j],l[i-ln][j-ln]+ln);
					}
				}
			}
		*/
		memset(l,0,sizeof(l));
		memset(dp,0,sizeof(dp));
		for(i = 1;i <= n;i ++)
			for(j = 1;j <= m;j ++)
			{
				if(a[i-1] == b[j-1])
				{
					l[i][j] = l[i-1][j-1] + 1;
				}else l[i][j] = 0;
			}
#ifdef Debug
		for(i = 1;i <= n;i ++)
		{
			for(j = 1;j <= m;j ++)
				printf("%d ",l[i][j]);
			printf("\n");
		}
#endif
		for(i = k;i <= n;i ++)
			for(j = k;j <= m;j ++)
			{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
				if(l[i][j] >= k)
				{
					for(ln = k;ln <= l[i][j];ln ++)
					{
					   dp[i][j] = max(dp[i][j],dp[i-ln][j-ln]+ln);
					}
				}
			}
		printf("%d\n",dp[n][m]);
	}
	return 0;
}
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn = 105;
typedef long long LL;
const int P = 100;
int n,a[maxn];
LL dp[maxn][maxn];
int cc[maxn][maxn];
int main()
{
	int i,j,k;
	while(scanf("%d",&n)!=EOF)
	{
		for(i = 0;i < n;i ++)
			scanf("%d",&a[i]);
		for(i = 0;i < n;i ++)
		{
			dp[i][i] = 0;
			cc[i][i] = a[i]%P;
		}
		for(k = 1;k < n;k ++)
		{
			for(i = 0;i < n - k;i ++)
			{
				dp[i][i+k] = dp[i][i+k-1] + cc[i][i+k-1]*cc[i+k][i+k] + dp[i+k][i+k];
				cc[i][i+k] = (cc[i][i+k-1] + cc[i+k][i+k])%P;
				for(j = i;j < i+k;j ++)
				{
					if(dp[i][j] + cc[i][j]*cc[j+1][i+k] + dp[j+1][i+k] < dp[i][i+k])
					{
						dp[i][i+k] = dp[i][j] + cc[i][j]*cc[j+1][i+k] + dp[j+1][i+k];
						//cc[i][i+k] = (cc[i][j] + cc[j+1][i+k])%P;
					}
				}
			}
		}
		printf("%ld\n",dp[0][n-1]);
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <ctime>
#include <queue>
#include <cstring>
using namespace std;
typedef int LL;
const int maxn = 10000004;
const int mod = 1000000007;

LL dp[maxn][4];
int main()
{
	LL tmp;
	int n,i;
	scanf("%d",&n);
	dp[0][0] = 1;
	dp[1][0] = 0;
	dp[1][1] = dp[1][2] = dp[1][3] = 1;
	for(i = 2;i <= n;i ++)
	{
		dp[i][0] = ((dp[i-1][1] + dp[i-1][2])%mod + dp[i-1][3])%mod;
		dp[i][1] = ((dp[i-1][0] + dp[i-1][2])%mod + dp[i-1][3])%mod;
		dp[i][2] = ((dp[i-1][1] + dp[i-1][0])%mod + dp[i-1][3])%mod;
		dp[i][3] = ((dp[i-1][1] + dp[i-1][2])%mod + dp[i-1][0])%mod;
	}
	printf("%d\n",dp[n][0]);
	return 0;
}
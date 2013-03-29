#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 1005;
const int bit[12] = {1,2,4,8,16,32,64,128,256,512,1024};
int dp[maxn];
int main()
{
	int t,n,ans,i,j;
	dp[0] = 1;
	for(i = 1;i < maxn;i ++)
	{
		dp[i] = 1;
		for(j = 0;j <= 10 && i >= bit[j];j ++)
			if(dp[i-bit[j]] == 1) dp[i] = 0;
	}
	while(scanf("%d",&n)!=EOF)
	{
		if(dp[n]) printf("Cici\n");
		else printf("Kiki\n");
	}
	return 0;
}
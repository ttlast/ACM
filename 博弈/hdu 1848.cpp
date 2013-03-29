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
const int bit[16] = {1,2,3,5,8,13,21,34,55,89,144,233,377,610,987};
int dp[maxn],h[16];
int main()
{
	int t,n,m,p,ans,i,j;
	dp[0] = 0;dp[1] = 1;
	for(i = 2;i < maxn;i ++)
	{
		for(j = 0;j < 16;j ++) h[j] = 0;
		for(j = 0;j < 15&&i >= bit[j];j ++)
			h[dp[i-bit[j]]] = 1;
		for(j = 0;j < 16;j ++) 
			if(!h[j]) break;
		dp[i] = j;
	}
	while(scanf("%d%d%d",&m,&n,&p)!=EOF)
	{
		if(m == 0 && n == 0 && p == 0) break;
		ans = dp[m]^dp[n]^dp[p];
		if(ans) printf("Fibo\n");
		else printf("Nacci\n");
	}
	return 0;
}
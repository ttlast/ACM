#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 2205;
int dp[maxn];
int main()
{
	int n,m,i,j;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		for(i = m;i < m+n;i ++)
			dp[i] = 0;  //±Ø°Ü
		for(i = m-1;i >= 1;i --)
		{
			dp[i] = 0;
			for(j = 1;j <= n;j ++)
				if(dp[i+j] == 0) dp[i] = 1;
		}
		for(i = 1;i <= n;i ++)
			if(dp[i] == 0) break;
		if(i > n) printf("none\n");
		else{
			printf("%d",i);
			for(i = i+1;i <= n;i ++)
				if(dp[i] == 0) printf(" %d",i);
			printf("\n");
		}
	}
	return 0;
}

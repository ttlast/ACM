#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10000;
const int maxm = 20001;
const int inf = 1000000000;
bool np[maxm] = {0};
int num[maxn],len,n;
int dp[maxm],flag[maxm];
void init()
{
	num[0] = 2;len = 1;
	int i,j;
	for(i = 4;i < maxm;i += 2) np[i] = true;
	for(i = 3;i < maxm;i += 2)
	{
		if(!np[i])
		{
			for(j = i+i;j < maxm;j += i)
				np[j] = true;
			num[len++] = i;
		}
	}
}
int main()
{
	init();
	scanf("%d",&n);
	int i,j,tmp,k,sl;
	flag[0] = flag[1] = 0;
	dp[0] = dp[1] = 0;
	for(i = 2,k = 0;i < maxm;i ++)
	{
		if(i >= num[k] && k < len) k ++;
		dp[i] = inf;
		sl = 0;
		for(j = 0;j < k;j ++)
		{
			if(flag[i - num[j]] == 0)
			{
				sl = 1;
				dp[i] = min(dp[i],dp[i-num[j]]+1);
			}
		}
		if(sl) flag[i] = 1;
		else flag[i] = 0;
		if(sl == 0)
		{
			dp[i] = 0;
			for(j = 0;j < k;j ++)
				dp[i] = max(dp[i],dp[i-num[j]]+1);
		}
	}
	for(i = 0;i < n;i ++)
	{
		scanf("%d",&tmp);
		if(flag[tmp] == 0) printf("-1\n");
		else printf("%d\n",dp[tmp]);
	}
	return 0;
}
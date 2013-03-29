#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
const int maxe = 1005;
const int maxn = 105;

struct Node{
	int w,v;
};
Node bone[maxn];
int n,vol,k;
int dp[maxe][35];
int a[35],b[35];

void package(int s)
{
	int i,j,al,bl;
	
	for(i = vol;i >= bone[s].v;i --)
	{
		for(j = 0;j < k;j ++) //有序，大 --- >小
		{
			a[j] = dp[i][j];
			b[j] = dp[i-bone[s].v][j] + bone[s].w;  //有序
		}
		a[k] = b[k] = -1;

		for(j = 0,al = bl = 0;j < k && (al < k || bl < k);)
		{
			if(a[al] > b[bl])
			{
				dp[i][j] = a[al];
				al ++;
			}else
			{
				dp[i][j] = b[bl];
				bl ++;
			}
			if(j == 0 || dp[i][j] != dp[i][j-1])
				j ++;
		}
	}
}

int main()
{
	int t,i,j;
	scanf("%d",&t);
	while(t --)
	{
		memset(dp,0,sizeof(dp));
		scanf("%d%d%d",&n,&vol,&k);
		for(i = 0;i < n;i ++)
			scanf("%d",&bone[i].w);
		for(i = 0;i < n;i ++)
			scanf("%d",&bone[i].v);

		for(i = 0;i < n;i ++)
			package(i);

		printf("%d\n",dp[vol][k-1]);

	}
	return 0;
}
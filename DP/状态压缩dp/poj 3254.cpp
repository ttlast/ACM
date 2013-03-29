#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 13;
const int N = 1<<13;
const int maxe = 700;
const int P = 1000000000;
const int np[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192};
int n,m;
int map[maxn][maxn];
struct Node{
	int status;
};
Node leg[maxe];
int dp[maxn][maxe];
int nl;
void getLeg()
{
	int i,tmp;
	nl = 0;
	leg[nl].status = 0;
	nl ++;
	for(i = 1;i < N;i ++)
	{
		tmp = i;
		if(tmp & (tmp<<1)) continue;
		leg[nl].status = i;
		nl ++;
	}
}
int gra[maxn];
int getL(int x)
{
	int l,r,best,mid;
	l = best = 0;r = nl;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(leg[mid].status > x)
			r = mid -1,best = mid;
		else l = mid + 1;
	}
	return best;
}
int main()
{
	int i,j,l,k;
	getLeg();
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i = 0;i < n;i ++)
		{
			gra[i] = 0;
			for(j = 0;j < m;j ++)
			{
				scanf("%d",&map[i][j]);
				if(map[i][j] == 1) gra[i] = gra[i]*2 + 0;
				else if(map[i][j] == 0) gra[i] = gra[i]*2 + 1;
			}
		}
		memset(dp,0,sizeof(dp));
		l = getL(np[m]-1);
		for(i = 0;i < l;i ++)
		{
			if(leg[i].status&gra[0]) continue;
			dp[0][i] = 1;
			dp[0][i] %= P;
		}
		for(i = 1;i < n;i ++)
		{
			for(j = 0;j < l;j ++)
			{
				if(leg[j].status & gra[i]) continue;
				for(k = 0;k < l;k ++)
				{
					if((leg[j].status & leg[k].status) == 0)  dp[i][j] += dp[i-1][k];
					dp[i][j] %= P;
				}
			}
		}
		int ans = 0;
		for(i = 0;i < l;i ++)
		{
			ans += dp[n-1][i];
			ans %= P;
		}
		printf("%d\n",ans);
	}
	return 0;
}
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1<<11;
const int maxn = 105;
const int np[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096};
int n,m;
struct Node{
	int army,status;
};
Node leg[90];
int legnum;
int dp[maxn][90][90];
void getLen()
{
	int i,tmp;
	legnum = 0;
	leg[legnum].army = 0;
	leg[legnum++].status = 0;
	for(i = 1;i < N;i ++)
	{
		tmp = i;
		if(((tmp<<1)&tmp)||((tmp<<2)&tmp)) continue;
		leg[legnum].army = 0;
		leg[legnum].status = i;
		tmp = i;
		while(tmp)
		{
			if(tmp&1) leg[legnum].army ++;
			tmp >>= 1;
		}
		legnum ++;
	}
}
int graph[maxn],l;
int getId(int x)
{
	int l,r,best,mid;
	l = 0;r = legnum;best = 0;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(leg[mid].status > x)
			best = mid, r = mid - 1;
		else l = mid + 1;
	}
	return best;
}
char c[15];
void OutputAns(int l)
{
	int i,j,ans;
	ans = 0;
	for(i = 0;i < l;i ++)
		for(j = 0;j < l;j ++)
			if(dp[n-1][i][j] > ans) ans = dp[n-1][i][j];
	printf("%d\n",ans);
}
int main()
{
	int i,j,cur,pre1,pre2;
	getLen();
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i = 0;i < n;i ++)
		{
			scanf("%s",c);
			graph[i] = 0;
			for(j = 0;j < m;j ++)
			{
				if(c[j] == 'P') graph[i] = graph[i]*2 + 0;
				else if(c[j] == 'H') graph[i] = graph[i]*2 + 1;
			}
		}
		l = getId(np[m]-1);
		memset(dp,0,sizeof(dp));
		if(n == 0)
		{
			printf("0\n");
			continue;
		}
		for(i = 0;i < l;i ++)
			if((leg[i].status & graph[0]) == 0) dp[0][i][0] = leg[i].army;
		if(n == 1)
		{
			OutputAns(l);
			continue;
		}
		for(i = 0;i < l;i ++)
			if((leg[i].status & graph[1]) == 0)
			{
				for(j = 0;j < l;j ++)
				{
					if((leg[i].status & leg[j].status) == 0)
					{
						dp[1][i][j] = max(dp[1][i][j],dp[0][j][0]+leg[i].army);
					}
				}
			}
		for(i = 2;i < n;i ++)
		{
			for(cur = 0;cur < l;cur ++)
				if((leg[cur].status & graph[i]) == 0)
				{
					for(pre1 = 0;pre1 < l;pre1 ++)
					{
						if((leg[cur].status & leg[pre1].status) == 0)
						{
							for(pre2 = 0;pre2 < l;pre2 ++)
							{
								if((leg[cur].status & leg[pre2].status) == 0)
									dp[i][cur][pre1] = max(dp[i][cur][pre1],dp[i-1][pre1][pre2] + leg[cur].army);
							}
						}
					}
				}
		}
		OutputAns(l);
	}
	return 0;
}
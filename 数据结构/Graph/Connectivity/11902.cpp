#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 105;

int g[maxn][maxn],n,dom[maxn][maxn];

int dfn[maxn],low[maxn],ntn,mask,sign[maxn];
void dfs(int u,int fu)
{
	sign[u] = 1;
	if(mask == u) return ;
	dfn[u] = low[u] = ntn ++;
	int i,j,v;
	for(i = 0;i < n;i ++)
	{
		if(!g[u][i]) continue;
		if(dfn[i] == -1)
		{
			dfs(i,u);
			low[u] = min(low[u],low[i]);
		}else low[u] = min(low[u],dfn[i]);
	}
}

int main()
{
	int t,i,j,ncase = 0;

	scanf("%d",&t);
	while(t --)
	{
		scanf("%d",&n);
		for(i = 0;i < n;i ++)
			for(j = 0;j < n;j ++)
				scanf("%d",&g[i][j]);

		for(j = 0;j < n;j ++)
			dfn[j] = -1,sign[j] = 0;
		mask = -1;
		dfs(0,0);

		for(i = 0;i < n;i ++)
		{
			mask = i;
			ntn = 0;
			for(j = 0;j < n;j ++)
				dfn[j] = -1;
			dfs(0,0);
			for(j = 0;j < n;j ++)
				if(dfn[j] == -1 && sign[j])
					dom[i][j] = 1;
				else dom[i][j] = 0;
		}
		ncase ++;
		printf("Case %d:\n",ncase);
		for(j = 0;j < n;j ++)
		{
			printf("+");
			for(i = 1;i < 2*n;i ++)
				printf("-");
			printf("+\n");
			for(i = 0;i < n;i ++)
				if(dom[j][i]) printf("|Y");
				else printf("|N");
				printf("|\n");
		}
		printf("+");
		for(i = 1;i < 2*n;i ++)
			printf("-");
		printf("+\n");
		
	}
	return 0;
}
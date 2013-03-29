#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 105;

struct Node{
	char c[33];
};
Node city[maxn];
int n,m;
int g[maxn][maxn];

bool comp(const Node & t1,const Node & t2)
{
	return strcmp(t1.c,t2.c) < 0;
}

int check(char *c)
{
	int i;
	for(i = 0;i < n;i ++)
		if(strcmp(city[i].c,c) == 0) return i;
}

int dfn[maxn],low[maxn],ntm,cut[maxn],ans,st;
void dfs(int u,int fu)
{
	int i,j,sz = 0;
	bool ss = false;
	dfn[u] = low[u] = ntm ++;
	for(i = 0;i < n;i ++)
	{
		if(!g[u][i]) continue;
		if(i == fu) continue;
		
		if(dfn[i] == -1)
		{
			sz ++;
			dfs(i,u);
			low[u] = min(low[u],low[i]);
			if(low[i] >= dfn[u]) ss = true;
		}else low[u] = min(low[u],dfn[i]);
	}
	if(u == st)
	{
		if(sz > 1) ans ++,cut[u] = 1;
	}else{
		if(ss) ans ++,cut[u] = 1;
	}
}

int main()
{
	int i,j,p1,p2,ncase = 0;
	char c1[33],c2[33];
	while(scanf("%d",&n),n)
	{
		for(i = 0;i < n;i ++)
		{
			scanf("%s",city[i].c);
		}
		sort(city,city+n,comp);
		scanf("%d",&m);
		memset(g,0,sizeof(g));
		for(i = 0;i < m;i ++)
		{
			scanf("%s%s",c1,c2);
			p1 = check(c1);
			p2 = check(c2);
			g[p1][p2] = g[p2][p1] = 1;
		}
		memset(dfn,-1,sizeof(dfn));
		memset(cut,0,sizeof(cut));
		ntm = 1;
		ans = 0;
		for(i = 0;i < n;i ++)
			if(dfn[i] == -1)
			{
				st = i;
				dfs(i,i);
			}
		if(ncase) printf("\n");
		ncase ++;
		printf("City map #%d: %d camera(s) found\n",ncase,ans);
		for(i = 0;i < n;i ++)
			if(cut[i]) printf("%s\n",city[i].c);
	}
	return 0;
}
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 250;

struct Node{
	int v,next;
};
Node mat[maxn*maxn];
int bg[maxn][maxn];
int eda[maxn],em;
int n;
void add(int u,int v)
{
	mat[em].v = v; mat[em].next = eda[u];
	eda[u] = em ++;
}
int low[maxn],dfn[maxn],nt,ans;

void dfs(int u,int fu)
{
	low[u] = dfn[u] = nt ++;
	int i,v;
	for(i = eda[u];i != -1;i = mat[i].next)
	{
		v = mat[i].v;
		if(v == fu) continue;
		if(dfn[v] == -1)
		{
			dfs(v,u);
			low[u] = min(low[u],low[v]);
			if(low[v] > dfn[u])
				bg[u][v] = bg[v][u] = 1,ans ++;
		}else low[u] = min(low[u],dfn[v]);
	}
}

int main()
{
	int i,j,k,u,v,d;
	while(scanf("%d",&n)!=EOF)
	{
		memset(bg,0,sizeof(bg));
		em = 0;
		for(i = 0;i < n;i ++)
			eda[i] = -1;
		for(i = 0;i < n;i ++)
		{
			scanf("%d (%d)",&u,&k);
			for(j = 0;j < k;j ++)
			{
				scanf("%d",&v);
				add(u,v);
			}
		}
		ans = 0;
		nt = 0;
		memset(dfn,-1,sizeof(dfn));
		for(i = 0;i < n;i ++)
			if(dfn[i] == -1)
				dfs(i,i);
		printf("%d critical links\n",ans);
		for(i = 0;i < n;i ++)
			for(j = i+1;j < n;j ++)
				if(bg[i][j]) printf("%d - %d\n",i,j);
		printf("\n");
	}
	return 0;
}
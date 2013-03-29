#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1005;

struct CNode{
	int u,v;
};
CNode cmat[maxn*maxn];
int cem;
struct Node{
	int v,next;
};
Node mat[maxn*maxn];
int bg[maxn][maxn];
bool g[maxn][maxn];
int eda[maxn],em;
int n,m;
void addc(int u,int v)
{
	g[u][v] = true;
	cmat[cem].u = u;cmat[cem].v = v;
	cem ++;
}
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
			addc(u,v);
			dfs(v,u);
			low[u] = min(low[u],low[v]);
			if(low[v] > dfn[u])
			{
				addc(v,u);
			}
		}else{
			if(!(g[u][v] | g[v][u]))
				addc(u,v);
			low[u] = min(low[u],dfn[v]);
		}
	}
	if(u == fu)  return ;
}

int main()
{
	int i,j,u,v,ncase = 0;
	while(scanf("%d%d",&n,&m),n|m)
	{
		for(i = 1;i <= n;i ++)
			eda[i] = -1;
		em = 0;
		for(i = 0;i < m;i ++)
		{
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		nt = 0;
		ncase ++;
		printf("%d\n\n",ncase);
		cem = 0;
		memset(g,false,sizeof(g));
		memset(dfn,-1,sizeof(dfn));
		dfs(1,1);
		for(i = 0;i < cem;i ++)
			printf("%d %d\n",cmat[i].u,cmat[i].v);
		printf("#\n");
	}
	return 0;
}
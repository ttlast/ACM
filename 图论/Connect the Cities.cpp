#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define typec int
const int inf  = 0x7FFFFFFF;
const int maxn = 505;
int fa[maxn];
int find(int u)
{
	if(fa[u] != u) fa[u] = find(fa[u]);
	else return fa[u];
}
void unit(int u,int v)
{
	u = find(u); v = find(v);
	if(u > v)  fa[u] = v;
	else  fa[v] = u;
}
struct Road{
	int u,v,d;
};
Road road[25500];
int n,m,k;
int mat[maxn][maxn],nroad[maxn],hash[maxn],em;
void init()
{
	int i;
	em = 0;
	for(i = 0;i <= n;i ++) fa[i] = i;
}
int vis[maxn],lowc[maxn];
typec prim(typec cost[][maxn], int n) // vertex: 0 ~ n-1
{
	int i, j, p;
	typec minc, res = 0;
	memset(vis, 0, sizeof(vis));
	vis[0] = 1;
	for (i=1; i<n; i++) lowc[i] = cost[0][i];
	for (i=1; i<n; i++) {
		minc = inf; p = -1;
		for (j=0; j<n; j++)
			if (0 == vis[j] && minc > lowc[j]) {
				minc = lowc[j]; p = j;
			}
			if (inf == minc) return -1; // 原图不连通
			res += minc; vis[p] = 1;
			for (j=0; j<n; j++)
				if (0 == vis[j] && lowc[j] > cost[p][j])
					lowc[j] = cost[p][j];
	}
	return res;
}
int main()
{
	int t,i,j,tm,ret;
	int u,v,d;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		init();
		for(i = 0;i < m;i ++)
		{
			scanf("%d%d%d",&u,&v,&d);
			road[i].u = u;road[i].v = v;road[i].d = d;
		}
		for(i = 0;i < k;i ++)
		{
			scanf("%d",&tm);
			scanf("%d",&u);
			for(j = 1;j < tm;j ++)
			{
				scanf("%d",&v);
				unit(u,v);
			}
		}
		for(i = 1;i <= n;i ++) if(fa[i] == i) nroad[em++] = i;
		for(i = 0;i < em;i ++) hash[nroad[i]] = i;
		for(i = 0;i < em;i ++)
			for(j = 0;j < em;j ++)
				mat[i][j] = inf;
		for(i = 0;i < m;i ++) //构造新图
		{
			u = road[i].u;v = road[i].v;
			u  = find(u); v = find(v);
			if(u != v)
			{
				if(mat[hash[u]][hash[v]] > road[i].d)
					mat[hash[u]][hash[v]] = mat[hash[v]][hash[u]] = road[i].d; 
			}
		}
		ret = prim(mat,em);
		printf("%d\n",ret);	
	}
	return 0;
}
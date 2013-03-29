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
int n,m,k;
int mat[maxn][maxn],nroad[maxn],hash[maxn],em,mat2[maxn][maxn];
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
	int i,j,a,b,ret;
	while(scanf("%d",&n)!=EOF)
	{
		init();
		for(i = 0;i < n;i ++)
			for(j = 0;j < n;j ++)
				scanf("%d",&mat2[i][j]);
		scanf("%d",&k);
		for(i = 0;i < k;i ++)
		{
			scanf("%d%d",&a,&b);
			a --;b --;
			unit(a,b);
		}
		for(i = 0;i < n;i ++) if(fa[i] == i) nroad[em++] = i;
		for(i = 0;i < em;i ++) hash[nroad[i]] = i;
		for(i = 0;i < em;i ++)
			for(j = 0;j < em;j ++) mat[i][j] = inf;
		for(i = 0;i < n;i ++)
			for(j = 0;j < n;j ++)
			{
				a = find(i); b = find(j);
				if(mat2[i][j] < mat[hash[a]][hash[b]]) mat[hash[a]][hash[b]] = mat[hash[b]][hash[a]] = mat2[i][j];
			}
		ret = prim(mat,em);
		printf("%d\n",ret);
	}
	return 0;
}
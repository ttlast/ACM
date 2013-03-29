#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;
#define _min(a,b) (a) > (b) ? (b):(a)
const int maxn = 10005;

struct Node{
	int v,next;
};
Node mat[maxn*2];
int eda[maxn],em;
void add(int u,int v)
{
	mat[em].v = v; mat[em].next = eda[u];
	eda[u] = em ++;
}
int n,m,co;
int dfn[maxn],low[maxn],nt,sign[maxn];
bool dfs(int u,int fu)
{
	int i,v,c = 0;
	co ++;
	dfn[u] = low[u] = nt++;
	for(i = eda[u];i != -1;i = mat[i].next)
	{
		v = mat[i].v;
		if(dfn[v] == -1)
		{
			if(!dfs(v,u))
				return false;
			if(low[v] < dfn[u]) 
				if(++c > 1) return false;
			low[u] = _min(low[u],low[v]);
		}else{
			if(sign[v]) return false;
			if(dfn[v] < low[u]) 
				if(++c > 1) return false;
			if(dfn[v] > low[u])
				return false;
			low[u] = _min(low[u],dfn[v]);
		}
	}
	sign[u] = 1;
	if(u == 0)
		return true;
	else if(c == 1) return true;
	return false;
}
int main()
{
	int t,i,j,u,v;
	scanf("%d",&t);
	while(t --)
	{
		em = 0;
		scanf("%d%d",&n,&m);
		for(i = 0;i < n;i ++)
			eda[i] = dfn[i] = -1,sign[i] = 0;
		for(i = 0;i < m;i ++)
		{
			scanf("%d%d",&u,&v);
			add(u,v);
		}
		co = nt = 0;
		if(dfs(0,0))
		{
			if(co >= n) printf("YES\n");
			else printf("NO\n");
		}else printf("NO\n");
	}
	return 0;
}
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 50005;
const int P = 321555123;
struct Node{
	int v,w,next;
};
Node mat[maxn*2];
int em,n,m,ans;
int eda[maxn];
int dp[maxn][104];
void addEda(int u,int v,int w)
{
	mat[em].v = v;mat[em].w = w;
	mat[em].next = eda[u];
	eda[u] = em ++;
	swap(u,v);
	mat[em].v = v;mat[em].w = w;
	mat[em].next = eda[u];
	eda[u] = em ++;
}
void dfs(int u,int fa)
{
	int v,i,j;
	dp[u][0] = 1;
	for(i = eda[u];i != -1; i = mat[i].next)
	{
		v = mat[i].v;
		if(v == fa) continue;
		dfs(v,u);
		for(j = 0;j <= m - mat[i].w;j ++)
		{
			ans = ans + dp[v][j]*dp[u][m-j-mat[i].w];
			if(ans >= P) ans -= P;
		}
		for(j = 0;j <= m - mat[i].w;j ++)
		{
			dp[u][j+mat[i].w] += dp[v][j];
			if(dp[u][j+mat[i].w] >= P) dp[u][j+mat[i].w] -= P;
		}
	}
}
int main()
{
	int i,j,u,v,w;
	scanf("%d%d",&n,&m);
	em = 0;
	for(i = 1;i <= n;i ++) eda[i] = -1;
	for(i = 1;i < n;i ++)
	{
		scanf("%d%d%d",&u,&v,&w);
		addEda(u,v,w);
	}
	memset(dp,0,sizeof(dp));
	ans = 0;
	dfs(1,-1);
	printf("%d\n",ans);
	return 0;
}


#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100006;
struct Node{
	int v,next;
};
Node mat[maxn*2];
int eda[maxn],em,n;
int dp[maxn][2];
void add(int u,int v)
{
	mat[em].v = v; mat[em].next = eda[u];
	eda[u] = em ++;
	swap(u,v);
	mat[em].v = v; mat[em].next = eda[u];
	eda[u] = em ++;
}
void dfs(int u,int fa)
{
	int i,v;
	dp[u][0] = 0;dp[u][1] = 1;
	for(i = eda[u];i != -1;i = mat[i].next)
	{
		v = mat[i].v;
		if(v == fa) continue;
		dfs(v,u);
		dp[u][1] += min(dp[v][0],dp[v][1]);
		dp[u][0] += dp[v][1];
	}
}
int main()
{
	int i,j,u,v;
	scanf("%d",&n);
	em = 0;
	for(i = 1;i <= n;i ++) eda[i] = -1;
	for(i = 1;i < n;i ++)
	{
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	dfs(1,-1);
	printf("%d\n",min(dp[1][0],dp[1][1]));
	return 0;
}
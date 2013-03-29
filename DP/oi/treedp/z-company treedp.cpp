#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long LL;
const int maxn = 100006;
struct Node{
	int v,next;
};
int eda[maxn],em;
Node mat[maxn*2];
void add(int u,int v)
{
	mat[em].v = v;  mat[em].next = eda[u];
	eda[u] = em ++;
	swap(u,v);
	mat[em].v = v;  mat[em].next = eda[u];
	eda[u] = em ++;
	swap(u,v);
}
int val[maxn],n;
LL dp[maxn][2];
void dfs(int u,int fa)
{
	dp[u][0] = 0;  dp[u][1] = val[u];
	int i,v;
	for(i = eda[u];i != -1;i = mat[i].next)
	{
		v = mat[i].v;
		if(v == fa) continue;
		dfs(v,u);
		dp[u][0] += max(dp[v][0],dp[v][1]);
		dp[u][1] += dp[v][0];
	}
}
int main()
{
	int i,j,fa;
	em = 0;
	scanf("%d",&n);
	for(i = 0;i < n;i ++) eda[i] = -1;
	scanf("%d",&val[0]);
	for(i = 1;i < n;i ++)
	{
		scanf("%d%d",&fa,&val[i]);
		add(i,fa);
	}
	dfs(0,-1);
	if(dp[0][0] > dp[0][1] ) printf("%lld\n",dp[0][0]);
	else printf("%lld\n",dp[0][1]);
	return 0;
}

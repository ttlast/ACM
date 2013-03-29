#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 100020;
const int Mod = 10007;
int n;
int dp[maxn][2];
int ans[maxn][2];
struct Node{
	int v,next;
};
Node mat[maxn*2];
int eda[maxn],em;
void add(int u,int v)
{
	mat[em].v = v;mat[em].next = eda[u];
	eda[u] = em++;
	swap(u,v);
	mat[em].v = v;mat[em].next = eda[u];
	eda[u] = em++;
}
int get(int a,int b,int na,int nb)
{
	if(a > b) return nb;
	else if(b > a) return na;
	return (na + nb)%Mod ;
}
void DP(int u,int fa)
{
	int i,v;
	dp[u][0] = 0;dp[u][1] = 1;
	ans[u][0] = ans[u][1] = 1;
	for(i = eda[u];i != -1;i = mat[i].next)
	{
		v = mat[i].v;
		if(v == fa) continue;
		DP(v,u);
		dp[u][0] += dp[v][1];
		dp[u][1] += min(dp[v][1],dp[v][0]);
		ans[u][1] = ans[u][1]*get(dp[v][0],dp[v][1],ans[v][0],ans[v][1])%Mod;
		ans[u][0] = ans[u][0]*ans[v][1]%Mod;
	}
}
int main()
{
	int t,i,u,v,st;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d",&n);
		em = 0;
		for(i = 0;i <= n;i ++) eda[i] = -1;
		for(i = 1;i < n;i ++)
		{
			scanf("%d%d",&u,&v);
			add(u,v);
		}
		DP(1,-1);
		printf("%d %d\n",min(dp[1][0],dp[1][1]),get(dp[1][0],dp[1][1],ans[1][0],ans[1][1]));
	}
	return 0;
}
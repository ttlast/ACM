#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 10005;
int n,s,k,em;
struct Eda{
	int v,d,next;
};
Eda mat[maxn*2];
int eda[maxn];
int dp[maxn][12];
void Addeda(int u,int v,int d)
{
	mat[em].v = v;mat[em].d = d;
	mat[em].next = eda[u];
	eda[u] = em++;
	swap(u,v);
	mat[em].v = v;mat[em].d = d;
	mat[em].next = eda[u];
	eda[u] = em++;
}
void init()
{
	em = 0;
	int i;
	for(i = 0;i <= n;i ++) eda[i] = -1;
	memset(dp,-1,sizeof(dp));
}

/* 可以证明,一个点返回的机器人最多一个的时候最优，
因为其他返回情况，可以用一个机器人遍历去代替。
dp[u][j] u 进入j个机器人.j = 0 进入一个机器人并且返回
*/
void dfs(int st,int fa)
{
	int i,j,u,v;
	if((fa != -1 && mat[eda[st]].next == -1)||(fa == -1 && eda[st] == -1))
	{
		for(i = 0;i <= k;i ++) dp[st][i] = 0;
	}
	for(u = eda[st];u != -1;u = mat[u].next)
	{
		v = mat[u].v;
		if(v == fa) continue;
		dfs(v,st);
		for(j = k;j >= 0;j --)
		{
			if(dp[st][j] == -1)  //第一个分支
			{
				if(j) dp[st][j] = dp[v][j] + j*mat[u].d;
				else dp[st][j] = dp[v][0] + 2*mat[u].d;
				for(i = j;i >= 1;i --)
				{
					if(dp[st][j] == -1 || dp[st][j] > dp[v][i] + i*mat[u].d)
						dp[st][j] = dp[v][i] + i*mat[u].d;
				}
			}else
			{
				dp[st][j] += dp[v][0] + 2*mat[u].d;
				for(i = j;i >= 1;i --)
				{
					if(dp[st][j] > dp[st][j-i] + dp[v][i] + i*mat[u].d)
						dp[st][j] = dp[st][j-i] + dp[v][i] + i*mat[u].d;
				}
			}
		}
	}
}
int main()
{
	int i,j,u,v,d;
	while(scanf("%d%d%d",&n,&s,&k)!=EOF)
	{
		init();
		for(i = 1;i < n;i ++) {
			scanf("%d%d%d",&u,&v,&d);
			Addeda(u,v,d);
		}
		dfs(s,-1);
		printf("%d\n",dp[s][k]);
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
const int inf = 1000000000;
const int maxn = 400;
int n,m,k;
int dp[maxn][maxn][2],tmp[maxn][2],sum[maxn];
bool sign[maxn][2];
struct Node{
	int v,d,next;
};
Node mat[maxn*2];
int eda[maxn],em,ans;
void addEda(int u,int v,int d)
{
	mat[em].v = v; mat[em].d = d;
	mat[em].next = eda[u];
	eda[u] = em ++;
	swap(u,v);
	mat[em].v = v; mat[em].d = d;
	mat[em].next = eda[u];
	eda[u] = em ++;
}
int dfs(int u,int fa,int num,int co)
{
	int i,v,j,t;
	int ci,cj;
	sum[u] = 1;
	memset(dp[u],0x3f,sizeof(dp[u]));
	dp[u][0][0] = 0;  dp[u][1][1] = 0;
	for(i = eda[u];i != -1;i = mat[i].next)
	{
		v = mat[i].v;
		if(v == fa) continue;
		if(m == 2) t = mat[i].d;
		else t = 0;
		dfs(v,u,num,1);
		sum[u] += sum[v];
		memcpy(tmp,dp[u],sizeof(tmp));
		memset(dp[u],0x3f,sizeof(dp[u]));
		for(ci = min(sum[u],num);ci >= 0;ci --)
			{
				if(ci > 0)
					for(cj = ci-1;cj >= 0;cj --)
					{
						dp[u][ci][1] = min(dp[u][ci][1],
							dp[u][ci-cj][1]+min(dp[v][cj][0],dp[v][cj][1]+mat[i].d));
					}
				for(cj = ci;cj >= 0;cj --)
					dp[u][ci][0] = min(dp[u][ci][0],
					   dp[u][ci-cj][0]+min(dp[v][cj][0]+t,dp[v][cj][1]));
			}	
	}
	return dp[u][num][co];
}
void check()
{
	if(m-1 <= n-k)
	{
		ans = dfs(1,-1,k,1);  //1 is boss
	}else ans = -1;
}
int main()
{
	int i,j,u,v,d;
	em = 0;
	scanf("%d%d%d",&n,&m,&k);
	for(i = 0;i <= n;i ++) sign[i][0] = sign[i][1] = false,eda[i] = -1;
	for(i = 1;i < n;i ++)
	{
		scanf("%d%d%d",&u,&v,&d);
		addEda(u,v,d);
	}
	check();
	printf("%d\n",ans);
	return 0;
}
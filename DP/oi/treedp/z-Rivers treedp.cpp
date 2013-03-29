#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
#define inf 2000000000
const int maxn = 108;
struct Node{
	int lc,rb;
	Node():lc(-1),rb(-1){};
};
Node mat[maxn];
int n,k,d[maxn],w[maxn],num[maxn];
int dp[maxn][55][maxn];
void add(int u,int v)
{
	mat[v].rb = mat[u].lc;
	mat[u].lc = v;
}
void dfs(int u)
{
	int v;
	for(v = mat[u].lc;v != -1;v = mat[v].rb)
	{
		d[v] += d[u];
		dfs(v);
	}
}
void countnum(int u)
{
	int v;
	num[u] = 1;
	if(mat[u].lc != -1) 
	{
		countnum(mat[u].lc);
		num[u] += num[mat[u].lc];
	}
	if(mat[u].rb != -1)
	{
		countnum(mat[u].rb);
		num[u] += num[mat[u].rb];
	}
}
int DP(int u,int p,int fa)
{
	if(dp[u][p][fa] > -1) return dp[u][p][fa];
	if(mat[u].lc == mat[u].rb)
	{
		if(p == 0) dp[u][p][fa] = w[u]*(d[u] - d[fa]);
		else dp[u][p][fa] = 0;
	}else{
		int v,i,j,tmp = inf;
		if(mat[u].lc == -1)  //仅有兄弟节点
		{
			if(p >= 1)
				tmp = min(tmp,DP(mat[u].rb,p-1,fa));   //此处建一个点
				tmp = min(tmp,DP(mat[u].rb,p,fa) + w[u]*(d[u]-d[fa]));  //不建
		}else if(mat[u].rb == -1)  //仅有子节点
		{
			if(p >= 1)
				tmp = min(tmp,DP(mat[u].lc,p-1,u)); //此处建一个点
			if(p <= num[u])
				tmp = min(tmp,DP(mat[u].lc,p,fa) + w[u]*(d[u]-d[fa])); //不建
		}else{
			for(i = min(num[mat[u].lc],p);i >= 0;i --)
			{
				tmp = min(tmp,DP(mat[u].lc,i,fa) + DP(mat[u].rb,p-i,fa) + w[u]*(d[u]-d[fa]));
				if(i < p)
					tmp = min(tmp,DP(mat[u].lc,i,u) + DP(mat[u].rb,p-i-1,fa));
			}
		}
		dp[u][p][fa] = tmp;
	}
	return dp[u][p][fa];
}
int main()
{
	int i,j,v;
	scanf("%d%d",&n,&k);
	for(i = 1;i <= n;i ++)
	{
		scanf("%d%d%d",&w[i],&v,&d[i]);
		add(v,i);
	}
	dfs(0);
	countnum(0);
	memset(dp,-1,sizeof(dp));
	printf("%d\n",DP(0,k,0));
	return 0;
}

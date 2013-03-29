#include <iostream>
using namespace std;
#define inf 0x7ffffffffffff
typedef __int64 LL;
const int maxn = 105;
const int N = 105;
int n,m;
int L1,L2,L3,L4,C1,C2,C3,C4;
LL mat[maxn][maxn],val[maxn];
LL dp[maxn][maxn];
int path[N], vis[N];
void Dijk(__int64 cost[][N],__int64  lowcost[N], int n, int beg){
	int i, j;
	__int64  min;
	memset(vis, 0, sizeof(vis));
	vis[beg] = 1;
	for (i=0; i<n; i++){
		lowcost[i] = cost[beg][i]; path[i] = beg;
	}
	lowcost[beg] = 0;
	path[beg] = -1; // 树根的标记
	int pre = beg;
	for (i=1; i<n; i++){
		min = inf;
		for (j=0; j<n; j++)
			// 下面的加法可能导致溢出,INF不能取太大
			if (vis[j]==0 &&
				lowcost[pre]+cost[pre][j]<lowcost[j]){
					lowcost[j] = lowcost[pre] + cost[pre][j];
					path[j] = pre;
			}
			for (j=0; j<n; j++)
				if (vis[j] == 0 && lowcost[j] < min){
					min = lowcost[j]; pre = j;
				}
				vis[pre] = 1;
	}
}
LL cost(LL a)
{
	if(a < 0) a = -a;
	if(a > L4) return inf;
	else if(a > L3) return C4;
	else if(a > L2) return C3;
	else if(a > L1) return C2;
	else if(a > 0) return C1;
	return 0;
}
int main()
{
	int t,ncase = 1,i,j,u,v;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d%d%d%d",&L1,&L2,&L3,&L4,&C1,&C2,&C3,&C4);
		scanf("%d%d",&n,&m);
		for(i = 0;i < n;i ++)
		{
			scanf("%I64d",&val[i]);
		}
		for(i  = 0;i < n;i ++)
			for(j = 0;j < n;j ++)
				mat[i][j] = cost(val[i] - val[j]);
		printf("Case %d:\n",ncase++);
		memset(dp,-1,sizeof(dp));
		for(i = 0;i < m;i ++)
		{
			scanf("%d%d",&u,&v);
			u -- ;v --;
			if(dp[u][v] = -1) {
				Dijk(mat,dp[u],n,u);
				//dp[v][u] = dp[u][v];
			}
			if(dp[u][v] == inf) printf("Station %d and station %d are not attainable.\n",u+1,v+1);
			else printf("The minimum cost between station %d and station %d is %I64d.\n",u+1,v+1,dp[u][v]);
		}
		
	}
	return 0;
}
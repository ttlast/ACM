#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
const int maxn = 50005;

int n,m;
struct Node{
	int v,d,next;
};
int eda[maxn],em;
Node mat[maxn<<1];
int dp[maxn][2],len[maxn];
int pos[maxn][2];
bool sign[maxn];
void add(int u,int v,int d)
{
	mat[em].v = v;mat[em].d = d;
	mat[em].next = eda[u]; eda[u] = em ++;
	swap(u,v);
	mat[em].v = v;mat[em].d = d;
	mat[em].next = eda[u]; eda[u] = em ++;
}
int dfs(int u,int fa)
{
	dp[u][0] = dp[u][1] = 0;
	int i,v,tmp;
	for(i = eda[u];i != -1;i = mat[i].next)
	{
		v = mat[i].v;
		if(v == fa) continue;
		tmp = mat[i].d + dfs(v,u);
		if(tmp > dp[u][0])
		{
			swap(dp[u][1],dp[u][0]); swap(pos[u][0],pos[u][1]);
			dp[u][0] = tmp; pos[u][0] = v;
		}else if(tmp > dp[u][1])
		{
			dp[u][1] = tmp; pos[u][1] = v;
		}
	}
	return dp[u][0];
}
int que[maxn],front,tail;
void bfs(int u)
{
	int i,v,tmp;
	for(i = 1;i <= n;i ++) sign[i] = false;
	que[0] = u;front = 0;tail = 1;
	while(front < tail)
	{
		u = que[front++];
		len[u] = dp[u][0];
		sign[u] = true;
		for(i = eda[u];i != -1;i = mat[i].next)
		{
			v = mat[i].v;
			if(sign[v]) continue;
			if(pos[u][0] != v)  tmp = dp[u][0] + mat[i].d;
			else tmp = dp[u][1] + mat[i].d;
			if(tmp > dp[v][0])
			{
				swap(dp[v][0],dp[v][1]); swap(pos[v][0],pos[v][1]);
				dp[v][0] = tmp; pos[v][0] = u;
			}else if(tmp > dp[v][1])
			{
				dp[v][1] = tmp;
				pos[v][1] = u;
			}
			que[tail++] = v;
		}
	}
}
int minq[maxn],minf,mint;
int maxq[maxn],maxf,maxt;
int main()
{
	int x,y,z,q,i,l,r,ans;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n == 0 && m == 0) break;
		em = 0;
		for(i = 1;i <= n;i ++) eda[i] = -1;
		for(i = 1;i < n;i ++)
		{
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z);
		}
		dfs(1,0); bfs(1);
		//for(i = 1;i <= n;i ++)
		//	printf("%d\n",dp[i][0]);
		for(i = 0;i < m;i ++)
		{
			if(n > 0) ans = 1;
			else ans = 0;
			scanf("%d",&q);
			if(q < 0) q = -q;
			minq[0] = maxq[0] = 1;
			minf = maxf = 0;
			mint = maxt = 1;
			l = 1;r = 1;
			while(l <= r && r < n)
			{
				r ++;
				while(mint > minf && len[minq[mint-1]] > len[r]) mint --;
				minq[mint++] = r;
				while(maxt > maxf && len[maxq[maxt-1]] < len[r]) maxt --;
				maxq[maxt++] = r;
				while(len[maxq[maxf]] - len[minq[minf]] > q)
				{
					if(maxq[maxf] > minq[minf])
					{
						l = minq[minf] + 1;
						minf ++;
					}else
					{
						l = maxq[maxf] + 1;
						maxf ++;
					}
				}
				ans = max(ans,r-l+1);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
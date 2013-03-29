#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1000005;

int n,m;
int eda[maxn],em;
struct Node{
	int v,d,next;
};
Node mat[maxn<<1];
int dp[maxn][2];
int len[maxn];
bool sign[maxn];
int pos[maxn][2];
void add(int u,int v,int d)
{
	mat[em].v = v; mat[em].d = d;
	mat[em].next = eda[u]; eda[u] = em ++;
	swap(u,v);
	mat[em].v = v; mat[em].d = d;
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
			swap(dp[u][0],dp[u][1]);
			dp[u][0] = tmp;
			swap(pos[u][0],pos[u][1]);
			pos[u][0] = v;
		}else if(tmp > dp[u][1])
		{
			swap(tmp,dp[u][1]);
			pos[u][1] = v;
		}
	}
	return dp[u][0]; 
}
int que[maxn],front,tail;
void bfs(int u)
{
	int i,v,tmp;
	front = 0;tail = 1;
	que[0] = u;
	memset(sign,false,sizeof(sign));
	while(front < tail)
	{
		u = que[front++];
		len[u] = dp[u][0];
		sign[u] = true;
		for(i = eda[u];i != -1;i = mat[i].next)
		{
			v = mat[i].v;
			if(sign[v]) continue;
			if(pos[u][0] != v) tmp = dp[u][0] + mat[i].d;
			else tmp = dp[u][1] + mat[i].d;
			if(tmp > dp[v][0])
			{
				swap(dp[v][0],dp[v][1]);
				dp[v][0] = tmp;
				swap(pos[v][0],pos[v][1]);
				pos[v][0] = u;
			}else if(tmp > dp[v][1])
			{
				dp[v][1] = tmp;
				pos[v][1] = u;
			}
			que[tail++] = v;
		}
	}
}

int qmin[maxn],qmax[maxn];
int qminf,qmint,qmaxf,qmaxt;
int main()
{
	int i,v,d,tmp,ans,l,r;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(m < 0) m = -m;
		for(i = 1;i <= n;i ++) eda[i] = -1;
		em = 0;
		for(i = 2;i <= n;i ++)
		{
			scanf("%d%d",&v,&d);
			add(i,v,d);
		}
		dfs(1,0);  bfs(1);
		ans = 1;
		qmin[0] = qmax[0] = 1;
		l = r  = 1;
		qminf = qmaxf = 0;
		qmint = qmaxt = 1;
		while(l <= r && r <= n)
		{
			r ++;
			while(qmint > qminf && len[qmin[qmint-1]] > len[r])
				qmint --;
			qmin[qmint++] = r;
			while(qmaxt > qmaxf && len[qmax[qmaxt-1]] < len[r])
				qmaxt --;
			qmax[qmaxt++] = r;
			while(len[qmax[qmaxf]] - len[qmin[qminf]] > m)
			{
				if(qmax[qmaxf] > qmin[qminf])
				{
					l = qmin[qminf] + 1;
					qminf ++;
				}else
				{
					l = qmax[qmaxf] + 1;
					qmaxf ++;
				}
			}
			ans = max(ans,r-l+1);
		}
		printf("%d\n",ans);
	}
	return 0;
}

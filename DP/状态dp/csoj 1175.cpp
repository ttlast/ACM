#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxde = 33000;
#define inf 1000000000
const int maxn = 11000;
const int maxe = 201000;

const int dmat[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072};
struct Node{
	int ei,vi,next;
};
int n,m,k;
int mudi[20];
Node mat[maxe];
int eda[maxn];
int dist[20][20];
int len;
void add(int u,int v,int d)
{
	mat[len].vi = v; mat[len].ei = d;
	mat[len].next = eda[u];
	eda[u] = len ++;
	swap(u,v);
	mat[len].vi = v; mat[len].ei = d;
	mat[len].next = eda[u];
	eda[u] = len ++;
}

int dis[maxn],in[maxn];
void spfa(int s)
{
	int i,j,k,v;
	int tmp;
	for(i = 0;i < n;i ++) dis[i] = inf,in[i] = 0;
	dis[s] = 0;
	queue<int> que;
	in[s] = 1;
	que.push(s);
	while(!que.empty())
	{
		tmp = que.front(); que.pop();
		in[tmp] = 0;
		for(i = eda[tmp];i != -1;i = mat[i].next)
		{
			v = mat[i].vi;
			if(dis[v] > dis[tmp] + mat[i].ei)
			{
				dis[v] = dis[tmp] + mat[i].ei;
				if(!in[v]) que.push(v),in[v] = 1;
			}
		}
	}
}

int dp[15][maxde]; 

int main()
{
	int i,j,l,u,v,d,ans,lt,maxd;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		len = 0;
		for(i = 0;i <= n;i ++) eda[i] = -1;
		for(i = 0;i < m;i ++)
		{
			scanf("%d%d%d",&u,&v,&d);
			add(u,v,d);
		}
		for(i = 1;i <= k;i ++)
			scanf("%d",&mudi[i]);
		scanf("%d",&mudi[0]);
		lt = 1;
		for(i = 0;i <= k && lt;i ++)
		{
			spfa(mudi[i]);
			for(j = i+1;j <= k && lt;j ++)
			{
				dist[i][j] = dist[j][i] = dis[mudi[j]];
				if(dis[mudi[j]] == inf) lt = 0;
			}
		}
		if(lt)
		{
			
			maxd = dmat[k]-1;
			for(i = 1;i <= k;i ++)
				dp[i][dmat[i-1]] = dist[0][i];
			for(i = 1;i <= maxd;i ++)
			{
				for(j = 1;j <= k;j ++)
				{
					if(i == dmat[j-1]) break;
					if(!(dmat[j-1]&i)) continue;
					dp[j][i] = inf;
					for(l = 1;l <= k;l ++)
					{
						if(l == j) continue;
						if(i&dmat[l-1])
						{
							dp[j][i] = min(dp[j][i],dp[l][i-dmat[j-1]]+dist[l][j]);
						}
					}
				}
			}
			for(i = 1,ans = inf;i <= k;i ++)
				if(mudi[i] != mudi[0]) ans = min(ans,dp[i][maxd]+dist[i][0]);
			if(ans == inf) ans = 0;  //wa here
			printf("%d\n",ans);
		}else printf("What a pity\n");
		
	}
	return 0;
}
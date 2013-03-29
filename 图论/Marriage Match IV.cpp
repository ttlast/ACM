#include <iostream>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstdio>
using namespace std;
#define inf 1000000000
const int maxn = 1005;
const int maxe = 100008;
struct Node{
	int v,d,next;
};
Node mat[maxe];
int n,m;
int eda[maxn],em;
int dp[maxn];
void insert(int u,int v,int d){
	mat[em].v = v;mat[em].d = d;
	mat[em].next = eda[u];
	eda[u] = em++;
}
struct CNode
{
    int v,d;
};
bool operator < ( const CNode & t1, const CNode & t2)
{
 	 if( t1.d > t2.d) return true;
 	 return false;
} 
int dis[maxn]; 
void dijk(int src,int dst)
{
 	 int i,j,u,v;
 	 priority_queue<CNode> q;
 	 for(i = 0;i <= n;i ++) dis[i] = inf;
 	 CNode tm,mq;
 	 tm.v = src; tm.d = 0;
 	 dis[src] = 0;
 	 q.push(tm);
 	 while(!q.empty())
 	 {
	   tm = q.top();
	   q.pop();
	   u = tm.v;
	   if(u == dst) break;
	   for(i = eda[u];i != -1;i = mat[i].next)
	   {
 		  v = mat[i].v;
 		  if(dis[v] > tm.d+mat[i].d)
 		  {
  			dis[v] = dis[u] + mat[i].d;
  			mq.v = v; mq.d = dis[v];
  			q.push(mq);
		  }
	   }
	  }
}
int flow[maxn];
Node mat2[maxe*2];
int eda2[maxn],em2;
int scur,sink,gap[maxn],h[maxn],ph[maxn];
void insert2(int u,int v,int d){
	mat2[em2].v = v;mat2[em2].d = d;
	mat2[em2].next = eda2[u];
	eda2[u] = em2++;
	swap(u,v);
	mat2[em2].v = v;mat2[em2].d = 0;
	mat2[em2].next = eda2[u];
	eda2[u] = em2++;
}
void init(){
	em = 0;em2 = 0;
	memset(eda2,-1,sizeof(eda2));
	memset(eda,-1,sizeof(eda));
}
int dfs(int u,int d)
{
	int lv = d,minh = n-1,mind,v,j;
	if(u == sink) return d;
	for(j = eda2[u];j != -1;j = mat2[j].next)
	{
		v = mat2[j].v;
		if(mat2[j].d > 0)
		{
			if(h[v]+1 == h[u])
			{
				if(lv > mat2[j].d) mind = mat2[j].d;
				else mind = lv;
				mind = dfs(v,mind);
				mat2[j].d -= mind;mat2[j^1].d += mind;
				lv -= mind;
				if(h[scur] >= n) return d - lv;
				if(lv == 0) break;
			}
			if(h[v] < minh) minh = h[v];
		}
	}
	if(d == lv)
	{
		--gap[h[u]];
		if(gap[h[u]] == 0) h[scur] = n;
		h[u] = minh +1;
		++gap[h[u]];
	}
	return d - lv;
}
int isap(int st,int ed)
{
	int v = 0;
	scur = st;sink = ed;
	memset(h,0,sizeof(h));
	memset(gap,0,sizeof(gap));
	n ++;
	gap[st] = n;  //×ÜµãÊý+1 
	while(h[st] < n)
	{
		v += dfs(st,inf);
	}
	return v;
}

int main()
{
	int t,ncase = 1,i,j,u,v,d,scur,sink,ret;
	scanf("%d",&t);
	while(t--)
	{
		init();
		scanf("%d%d",&n,&m);
		for(i = 0;i < m;i ++)
		{
			scanf("%d%d%d",&u,&v,&d);
			insert(u,v,d);
		}
		scanf("%d%d",&scur,&sink);
		dijk(scur,sink);
		for(i = 1;i <= n;i ++)
		{
			for(j = 1;j <= n;j ++) flow[j] = 0;
			for(j = eda[i];j != -1;j = mat[j].next)
			{
				if(mat[j].d == dis[mat[j].v] - dis[i]) flow[mat[j].v] ++;
			}
			for(j = 1;j <= n;j ++)
				if(flow[j]) insert2(i,j,flow[j]);
		}
		ret = isap(scur,sink);
		printf("%d\n",ret);
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int maxn=20500;
const int maxe=500000;
const int inf = 1000000000;
struct Node{
	int v,d,next;
};
Node mat[maxe];
int eda[maxn],em,scur,sink,n,m,gap[maxn],h[maxn],ph[maxn];
void init(int n){
	em = 0;
	int i;
	for(i = 0;i <= n;i ++) eda[i] = -1;
}
void insert(int u,int v,int d,int d2 = 0)  //单向边
{
	mat[em].v = v;mat[em].d = d;
	mat[em].next = eda[u];
	eda[u] = em++;
	swap(u,v);
	mat[em].v = v;mat[em].d = d2;
	mat[em].next = eda[u];
	eda[u] = em++;
}
int dfs(int u,int d)
{
	int lv = d,minh = n-1,mind,v,j;
	if(u == sink) return d;
	for(j = eda[u];j != -1;j = mat[j].next)
	{
		v = mat[j].v;
		if(mat[j].d > 0)
		{
			if(h[v]+1 == h[u])
			{
				if(lv > mat[j].d) mind = mat[j].d;
				else mind = lv;
				mind = dfs(v,mind);
				mat[j].d -= mind;mat[j^1].d += mind;
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
	n += 2;
	gap[st] = n;  //总点数+1 
	while(h[st] < n)
	{
		v += dfs(st,inf);
	}
	return v;
}

int main()
{
	int i,j,a,b,c,ret;
	while(scanf("%d%d",&n,&m)==2)
	{
		init(n+1);
		scur = 0;sink = n+1;
		for(i = 1;i <= n;i ++)
		{
			scanf("%d%d",&a,&b);
			insert(scur,i,a,0);
			insert(i,sink,b,0);
		}
		for(i = 0;i < m;i ++)
		{
			scanf("%d%d%d",&a,&b,&c);
			insert(a,b,c,c);
		}
		ret = isap(scur,sink);
		printf("%d\n",ret);
	}
    return 0;
}

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int inf = 0x3fffffff;
const int maxn = 1005;
struct House{
	int a,b,c;
};
int n,x,y,z;
House h[maxn];
int dist(int u,int v)
{
	return abs(h[u].a - h[v].a) + abs(h[u].b - h[v].b) + abs(h[u].c - h[v].c);
}
struct Edage{
	int u,v,d;
};
Edage eda[1100000];
int em;
void addEda(int u,int v,int d)
{
	eda[em].u = u;eda[em].v = v;
	eda[em++].d = d;
}
int pre[maxn],belong[maxn],in[maxn],vis[maxn];
int solve()
{
	int i,j,k,v;
	int sum = 0,root = 0,num = 0;
	n ++;
	while(1)
	{
		for(i = 0;i < n;i ++)
			in[i] = inf;
		for(i = 0;i < em;i ++) 
		{
			if(in[eda[i].v] > eda[i].d && eda[i].u != eda[i].v)
			{
				pre[eda[i].v] = eda[i].u;
				in[eda[i].v] = eda[i].d;
			}
		}
		memset(vis,-1,sizeof(vis));
		memset(belong,-1,sizeof(belong));
		in[root] = 0;
		for(num = 0,i = 0;i < n;i ++)  
		{
			sum += in[i];
			j = i;
			while(vis[j] != i && belong[j] == -1 && j != root)
			{
				vis[j] = i; j = pre[j];
			}
			if(vis[j] == i)
			{
				for(k = pre[j];k != j;k = pre[k])
					belong[k] = num;
				belong[j] = num ++;
			}
		}
		if(!num) return sum;
		for(i = 0;i < n;i ++)   //Ëõµã
			if(belong[i] == -1) belong[i] = num ++;
		//¸ü¸Ä±ß
		for(i = 0;i < em;i ++)
		{
			v = eda[i].v;
			eda[i].u = belong[eda[i].u];
			eda[i].v = belong[eda[i].v];
			eda[i].d -= in[v];
		}
		root = belong[root];
		n = num;
	}
	return sum;	
}
int main()
{
	int i,j,k,v;
	while(scanf("%d%d%d%d",&n,&x,&y,&z)!=EOF)
	{
		em = 0;
		if(n == 0) break;
		for(i = 1;i <= n;i ++)
		{
			scanf("%d%d%d",&h[i].a,&h[i].b,&h[i].c);
			addEda(0,i,h[i].c*x);
		}
		for(i = 1;i <= n;i ++)
		{
			scanf("%d",&k);
			for(j = 0;j < k;j ++)
			{
				scanf("%d",&v);
				if(v == i) continue;
				if(h[i].c >= h[v].c)
				{
					addEda(i,v,dist(i,v)*y);
				}else addEda(i,v,dist(i,v)*y + z);
			}
		}
		printf("%d\n",solve());
	}
	return 0;
}
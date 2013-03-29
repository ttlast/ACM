#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 105;

int n,m;
struct Node{
	int v,next;
};
Node mat[maxn*maxn];
int eda[maxn],em,ans;
int color[maxn],tc[maxn];

void add(int u,int v)
{
	mat[em].v = v; mat[em].next = eda[u];
	eda[u] = em ++;
}

void dfs(int u)
{
	int i,v,tmp = 0;
	if(u > n)
	{
		for(i = 1;i <= n;i ++)
			if(tc[i] == 1) tmp ++;
		if(tmp > ans)
		{
			ans = tmp;
			memcpy(color,tc,sizeof(tc));
		}
	}else{
		for(i = eda[u];i != -1;i = mat[i].next)
		{
			v = mat[i].v;
			if(tc[v]) break;
		}
		if(i != -1)
		{
			dfs(u+1);
		}else{
			tc[u] = 1;
			dfs(u+1);
			tc[u] = 0;
			dfs(u+1);
		}
	}
}

int main()
{
	int t,i,j,u,v,s;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d%d",&n,&m);
		em = 0;
		for(i = 1;i <= n;i ++)
			eda[i] = -1,color[i] = tc[i] = 0;
		for(i = 0;i < m;i ++)
		{
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		ans = 0;
		dfs(1);
		printf("%d\n",ans);
		for(i = 1,s = 0;i <= n;i ++)
			if(color[i]) 
			{
				if(s) printf(" ");
				printf("%d",i);
				s ++;
			}
		printf("\n");
	}
	return 0;
}
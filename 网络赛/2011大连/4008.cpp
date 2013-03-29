#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int inf = 0xfffffff;
const int maxn = 100100;
int n,q;
struct DNode{
	int ans[4];  //分别记录 儿子 最小 次小  子树 最小 次小 
};
DNode xi[maxn];
struct Node{
	int v,next;
};
Node mat[maxn*2];
int eda[maxn];
int em;
void addEda(int u,int v)
{
	mat[em].v = v; mat[em].next = eda[u];
	eda[u] = em++;
	swap(u,v);
	mat[em].v = v; mat[em].next = eda[u];
	eda[u] = em++;
}
int dfn[maxn],color,maxdfn[maxn],dfa[maxn],mid[maxn];
void dfs(int u,int fa)
{
	int v,i,j,mind;
	dfa[u] = fa;
	xi[u].ans[0] = xi[u].ans[1] = xi[u].ans[2] = xi[u].ans[3] = inf;
	dfn[u] = maxdfn[u] = color ++;   //maxdfn 记录子节点顺序。
	for(i = eda[u];i != -1;i = mat[i].next)
	{
		v = mat[i].v;
		if(v == fa) continue;
		dfs(v,u);
		maxdfn[u] = max(maxdfn[u],maxdfn[v]);
		//子树的
		mind = min(xi[v].ans[2],v);
		if(mind < xi[u].ans[2])
		{
			mid[u] = v;
			xi[u].ans[3] = xi[u].ans[2];
			xi[u].ans[2] = mind;
		}else if(mind <  xi[u].ans[3]) xi[u].ans[3] = mind;
		//儿子
		if(v < xi[u].ans[0])
		{
			xi[u].ans[1] = xi[u].ans[0];
			xi[u].ans[0] = v;
		}else if(v < xi[u].ans[1]) xi[u].ans[1] = v;
	}
}
int main()
{
	int t,u,v,i,a1,a2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&q);
		for(i = 0;i <= n;i ++) eda[i] = -1;
		em = color = 0;
		for(i = 1;i < n;i ++)
		{
			scanf("%d%d",&u,&v);
			addEda(u,v);
		}
		dfs(1,inf); // 1 为根扩展
		for(i = 0;i < q;i ++)
		{
			scanf("%d%d",&u,&v);
			if(mat[eda[v]].next == -1) puts("no answers!");
			else
			{
				if(dfn[u] >= dfn[v] && dfn[u] <= maxdfn[v]) //u 是 v的儿子节点
				{
					if(dfn[u] >= dfn[xi[v].ans[0]] && dfn[u] <= maxdfn[xi[v].ans[0]])
						a1 = xi[v].ans[1];
					else a1 = xi[v].ans[0];
					if(dfn[u] >= dfn[mid[v]] && dfn[u] <= maxdfn[mid[v]])
						a2 = xi[v].ans[3];  //最小那个点在u所在的分支上 ，舍去
					else a2 = xi[v].ans[2];
					if(v != 1)  {a1 = min(a1,dfa[v]);a2 = 1;}
					printf("%d %d\n",a1,a2);
				}else
				{
					printf("%d %d\n",xi[v].ans[0],xi[v].ans[2]);
				}
			}
		}
		printf("\n");
	}
	return 0;
}
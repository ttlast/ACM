#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
const int maxn = 110000;

int fa[maxn],len,em,tree;

int findfa(int u)
{
	if(fa[u] != u) fa[u] = findfa(fa[u]);
	return fa[u];
}

void unit(int u,int v)
{
	u = findfa(u);
	if(u == v) return ;
	fa[v] = u;
	tree --;
}

int main()
{
	int u,v,sign,al,ncase = 0,fu,fv;
	sign = 1;
	while(1)
	{
		ncase ++;
		memset(fa,0,sizeof(fa));
		em = len = 0;
		tree = 0;
		al = 1;
		while(scanf("%d%d",&u,&v)!=EOF)
		{
			if(u < 0 || v < 0)
			{
				sign = 0;
				break;
			}
			if(u == 0 && v == 0) break;
			if(fa[u] == 0)
			{
				fa[u] = u;
				tree ++;
				len ++;
			}
			if(fa[v] == 0)
			{
				fa[v] = v;
				len ++;
				tree ++;
			}
			unit(u,v);
			em ++;
			al = 0;
		}
		if(!sign) break;
		if(al) printf("Case %d is a tree.\n",ncase);
		else{
			if(tree == 1 && len - em == 1) printf("Case %d is a tree.\n",ncase);
			else printf("Case %d is not a tree.\n",ncase);
		}
	}
	return 0;
}
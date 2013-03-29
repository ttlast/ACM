#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int maxn = 1000;
struct Node{
	int c,v;
};
Node mat[maxn];
int pm[7],ln,ans;
int c,n,m;
int que[maxn];
inline bool comp(const Node & t1,const Node & t2)
{
	if(pm[t1.c] != pm[t2.c]) return pm[t1.c] < pm[t2.c];
	else return t1.v < t2.v;
}
inline int bf(int s,int len)
{
	int l,r,mid,pos;
	l = 0;r = len;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(comp(mat[que[mid]],mat[s])) l = mid + 1;
		else r = mid - 1;
	}
	return l;
}
void dfs(int u)
{
	int i,pos;
	if(u == c)
	{
		que[0] = 0;ln = 1;
		for(i = 1;i < m;i ++)
		{
		    pos = bf(i,ln-1);
			//pos = 1;
			que[pos] = i;
			if(pos >= ln) ln ++;
		}
		if(m - ln < ans) ans = m - ln;
	}else
	{
		dfs(u+1);
		for(i = u+1;i < c;i ++)
		{
			swap(pm[u],pm[i]);
			dfs(u+1);
			swap(pm[u],pm[i]);
		}
	}
}
int main()
{
	int i,j;
	scanf("%d%d",&c,&n);
		m = c*n;
	for(i = 0;i < m;i ++)
	{
		scanf("%d%d",&mat[i].c,&mat[i].v);
		mat[i].c --;
	}
	for(i = 0;i < c;i ++) pm[i] = i+1;
	ans = m;
	dfs(0);
	printf("%d\n",ans);
	return 0;
}

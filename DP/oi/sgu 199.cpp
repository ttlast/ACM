#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
//#define Debug
using namespace std;
const int maxn = 100005;
struct Node{
	int s,b,pos;
};
Node num[maxn];
int pre[maxn];
bool comp(const Node & t1,const Node & t2)
{
	if(t1.s != t2.s) return t1.s < t2.s;
	return t1.b > t2.b;
}
int qu[maxn],l;
int n;
int find_l(int s,int ln)
{
	int pos,l,r,mid;
	l = 0;
	pos = -1;
	r = ln;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(num[qu[mid]].b >= num[s].b)  //bug
		{
			pos = mid;
			r = mid - 1;
		}else l = mid + 1;
	}
	return pos;
}
void dfs(int u,int dep)
{
	if(dep == 1)
	{
		printf("%d",num[u].pos+1);
		return ;
	}
	dfs(pre[u],dep-1);
	printf(" %d",num[u].pos+1);
}
int main()
{
	int i,j;
	while(scanf("%d",&n)!=EOF)
	{
		for(i = 0;i < n;i ++)
			scanf("%d%d",&num[i].s,&num[i].b),num[i].pos = i;
		sort(num,num+n,comp);
		l = 1;qu[0] = 0; pre[0] = -1;
		for(i = 1;i < n;i ++)
		{
			if(num[i].b > num[qu[l-1]].b)
			{
				pre[i] = qu[l-1];
				qu[l++] = i;
			}else
			{
				j = find_l(i,l-1);
				if(j >= 0) qu[j] = i;
				if(j > 0) pre[i] = qu[j-1];
				else pre[i] = -1;
			}
		}
		printf("%d\n",l);
		dfs(qu[l-1],l);
		printf("\n");
	}
	return 0;
}
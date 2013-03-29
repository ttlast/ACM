#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int maxn = 6000;
int n;
struct Node{
	int l,w;
};
Node mat[maxn];
int que[maxn],ln;
bool comp(const Node & t1,const Node & t2)
{
	if(t1.l != t2.l) return t1.l < t2.l;
	return t1.w < t2.w;
}
int bs(int s,int len)
{
	int l,r,mid;
	l = 0;r = len;
	while(l <= r)
	{
		mid = (l + r) >> 1;
		if(que[mid] > mat[s].w)  l = mid + 1;
		else r = mid - 1;
	}
	return l;
}
int main()
{
	int i,j,t;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d",&n);
		for(i = 0;i < n;i ++)
			scanf("%d%d",&mat[i].l,&mat[i].w);
		sort(mat,mat+n,comp);
		que[0] = mat[0].w; ln = 1;
		for(i = 1;i < n;i ++)
		{
			j = bs(i,ln - 1);
			que[j] = mat[i].w;
			if(j >= ln) ln ++;
		}
		printf("%d\n",ln);		
	}
	return 0;
}
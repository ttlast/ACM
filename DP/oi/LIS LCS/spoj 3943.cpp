#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 20005;
struct Node{
	int w,h;
};
Node mat[maxn];
int que[maxn],ln,ans;
bool comp(const Node & t1,const Node & t2)
{
	if(t1.w != t2.w) return t1.w < t2.w;
	else return t1.h > t2.h;
}
int n;
int bs(int s,int len)
{
	int l,r,mid,pos;
	l = 0;r = len;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(que[mid] >= mat[s].h)
		{
			l = mid + 1;
		}else r = mid - 1;
	}
	return l;
}
int main()
{
	int t,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i = 0;i < n;i ++)
			scanf("%d%d",&mat[i].w,&mat[i].h);
		sort(mat,mat+n,comp);
		que[0] = mat[0].h; ln = 1;
		ans = 1;
		for(i = 1;i < n;i ++)
		{
			j = bs(i,ln -1);
			que[j] = mat[i].h;
			if(j >= ln) ln ++;
		}
		printf("%d\n",ln);
	}
	return 0;
}
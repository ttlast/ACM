#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1100;

struct Node{
	int x,y,c;
};
int n,l;
Node mat[maxn*2];
int len;
int yl[maxn*2],cly;
bool comp(const Node & t1,const Node & t2)
{
	if(t1.x != t2.x) return t1.x < t2.x;
	return t1.c < t2.c;
}
int bfind(int val)
{
	int l,r,mid;
	l = 0;r = cly-1;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(yl[mid] == val) return mid;
		else if(yl[mid] > val) r = mid-1;
		else l = mid+1;
	}
}
int val[maxn*8],maxd[maxn*8];
void build(int root,int L,int R)
{
	val[root] = maxd[root] = 0;
	if(L == R)
	{
		return ;
	}
	int mid = (L+R)>>1;
	build(root<<1,L,mid);
	build((root<<1)+1,mid+1,R);
}
void insert(int root,int v,int l,int r,int L,int R)
{
	if(l <= L && r >= R)
	{
		val[root] += v;
		maxd[root] += v;
		return ;
	}
	if(val[root] != 0)
	{
		val[root<<1] += val[root];
		val[(root<<1)+1] += val[root];
		maxd[root<<1] += val[root];
		maxd[(root<<1)+1] += val[root];
		val[root] = 0;
	}
	if(maxd[root<<1] > maxd[root]) maxd[root<<1] = maxd[root];
	if(maxd[(root<<1)+1] > maxd[root]) maxd[(root<<1)+1] = maxd[root];
	int mid = (L+R)>>1;
	if(l <= mid) insert(root<<1,v,l,r,L,mid);
	if(r > mid) insert((root<<1)+1,v,l,r,mid+1,R);
	maxd[root] = max(maxd[root<<1],maxd[(root<<1)+1]);
}
int main()
{
	int i,j,x,y,y1,y2,ans;
	while(scanf("%d%d",&n,&l)!=EOF)
	{
		len = cly = 0;
		for(i = 0;i < n;i ++)
		{
			scanf("%d%d",&x,&y);
			mat[len].x = x;mat[len].y = y; mat[len++].c = 1;
			mat[len].x = x+l+1;mat[len].y = y; mat[len++].c = -1;
			yl[cly++] = y;
			yl[cly++] = y+l;
		}
		sort(yl,yl+cly);
		cly = unique(yl,yl+cly) - yl;
		build(1,0,cly-1);
		sort(mat,mat+len,comp);
		for(i = ans = 0;i < len;i ++)
		{
			y1 = bfind(mat[i].y);
			y2 = bfind(mat[i].y+l);
			insert(1,mat[i].c,y1,y2,0,cly-1);
			ans = max(ans,maxd[1]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
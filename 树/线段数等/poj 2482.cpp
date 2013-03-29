#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10300;
typedef unsigned int Uint;

struct Node{
	Uint x,y;
	int c;
};
bool comp(const Node & t1,const Node & t2)
{
	if(t1.x != t2.x) return t1.x < t2.x;
	return t1.c < t2.c;
}
int n,w,h;
Node mat[maxn*2];
int len;
Uint ly[maxn*2],cly;

int bfind(Uint val)
{
	int l,r,mid;
	l = 0;r = cly-1;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(ly[mid] == val) return mid;
		else if(ly[mid] > val) r = mid-1;
		else l = mid+1;
	}
}
int val[maxn*8],maxd[maxn*8];
void build(int root,int L,int R)
{
	int mid = (L+R)>>1;
	maxd[root] = 0;
	val[root] = 0;
	if(L+1 == R) return ;
	build(root<<1,L,mid);
	build((root<<1)+1,mid,R);
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
	if(l < mid) insert(root<<1,v,l,r,L,mid);
	if(r > mid) insert((root<<1)+1,v,l,r,mid,R);
	maxd[root] = max(maxd[root<<1],maxd[(root<<1)+1]);
}
int main()
{
	int i,j,x,y,c,ans,y1,y2;
	while(scanf("%d%d%d",&n,&w,&h)!=EOF)
	{
		len = cly = 0;
		for(i = 0;i < n;i ++)
		{
			scanf("%d%d%d",&x,&y,&c);
			mat[len].x = x;mat[len].y = y;
			mat[len++].c = c;
			mat[len].x =(Uint) x+w; mat[len].y = y;
			mat[len++].c = -c;
			ly[cly++] = y;
			ly[cly++] = y+h;
		}
		sort(mat,mat+len,comp);
		sort(ly,ly+cly);
		cly = unique(ly,ly+cly)-ly;
		build(1,0,cly);
		for(i = 0,ans = 1;i < len;i ++)
		{
			y1 = bfind(mat[i].y);
			y2 = bfind(mat[i].y+h);
			insert(1,mat[i].c,y1,y2,0,cly);
			ans = max(ans,maxd[1]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
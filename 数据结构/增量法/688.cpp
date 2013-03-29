#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;
#define inf 0.001
const int maxn = 405;

struct Node{
	double x,l,r;
	int val;
};
Node mat[maxn];
double yl[maxn];
int len,ylen;
bool comp(const Node & t1,const Node & t2)
{
	if(fabs(t1.x-t2.x) > inf) return t1.x < t2.x;
	return false;
}

int bfind(double val)
{
	int l,r,mid;
	l = 0;r = ylen-1;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(abs(yl[mid]-val) <= inf) return mid;
		else if(yl[mid]-val > inf) r = mid - 1;
		else l = mid + 1;
	}
	return r;
}
struct CNode{
	int ncount;
	double val;
};
CNode tree[maxn*10];
void build(int root,int l,int r)
{
	tree[root].ncount = 0;
	tree[root].val = 0;
	if(l+1 >= r)
	{
		return ;
	}
	int mid = (l+r)>>1;
	build(root<<1,l,mid);
	build((root<<1)+1,mid,r);
}
void insert(int root,int L,int R,int l,int r,int val)
{
	if(l >= r) return ;
	if(L >= l && R <= r)
	{
		tree[root].ncount += val;
		if(tree[root].ncount)
			tree[root].val = yl[R] - yl[L];
		else if(L+1 < R)
			tree[root].val = tree[root<<1].val + tree[(root<<1)+1].val;
		else tree[root].val = 0;
		return ;
	}
	int mid = (L+R)>>1;
	if(l < mid)
		insert(root<<1,L,mid,l,r,val);
	if(r > mid)
		insert((root<<1)+1,mid,R,l,r,val);
	if(tree[root].ncount == 0 && L+1 < R)
	{
		tree[root].val = tree[root<<1].val + tree[(root<<1)+1].val;
	}
}
int main()
{
	int n,ncase = 0,i,xl,sl;
	double x,y,r;
	double ans;
	while(scanf("%d",&n),n)
	{
		len = ylen = 0;
		for(i = 0;i < n;i ++)
		{
			scanf("%lf%lf%lf",&x,&y,&r);
			yl[ylen++] = y-r;
			yl[ylen++] = y+r;

			mat[len].x = x-r;
			mat[len].l = y-r;mat[len].r = y+r;
			mat[len].val = 1;
			len ++;

			mat[len].x = x+r;
			mat[len].l = y-r;mat[len].r = y+r;
			mat[len].val = -1;
			len ++;
		}
		sort(yl,yl+ylen);
		ylen = unique(yl,yl+ylen)-yl;
		sort(mat,mat+len,comp);
		build(1,0,ylen-1);
		for(i = ans = 0;i < len;i ++)
		{
			if(i != 0 && mat[i].x -mat[i-1].x > inf)
			{
				ans += tree[1].val*(mat[i].x-mat[i-1].x);
			}
			xl = bfind(mat[i].l);
			sl = bfind(mat[i].r);
			insert(1,0,ylen-1,xl,sl,mat[i].val);
		}
		ncase ++;
		printf("%d %.2lf\n",ncase,ans);
	}
	return 0;
}
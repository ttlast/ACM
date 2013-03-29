#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int Maxn = 10005;

typedef long long LL;
struct Node{
	int s,e,p;
};
Node mat[Maxn];

int b[Maxn*2],len;

bool comp(const Node & t1,const Node & t2)
{
	if(t1.e != t2.e) return t1.e < t2.e;
	return t1.s < t2.s;
}

int bfind(int val)
{
	int l,r,mid;
	l = 0;r = len - 1;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(b[mid] == val) return mid;
		else if(b[mid] < val) l = mid + 1;
		else r = mid - 1;
	}
}

LL Tree[Maxn*8];

void build(int root,int l,int r)
{
	Tree[root] = 0;
	if(l == r) return ;
	int mid = (l+r)>>1;
	build(root<<1,l,mid);
	build((root<<1)+1,mid+1,r);
}

void updata(int root,int l,int r,int x,LL a)
{
	if(l == x && r == x)
	{
		Tree[root] = max(a,Tree[root]);
	}else
	{
		int mid = (l+r)>>1;
		if(x <= mid) updata(root<<1,l,mid,x,a);
		else updata((root<<1)+1,mid+1,r,x,a);
		Tree[root] = max(Tree[root<<1],Tree[(root<<1)+1]);
	}
}

LL queue(int root,int l,int r,int lx,int rx)
{
	if(l >= lx && r <= rx)
	{
		return Tree[root];
	}else
	{
		int mid = (l+r)>>1;
		if(rx <= mid) return queue(root<<1,l,mid,lx,rx);
		else if(lx > mid) return queue((root<<1)+1,mid+1,r,lx,rx);
		else
		{
			return max(queue(root<<1,l,mid,lx,rx),queue((root<<1)+1,mid+1,r,lx,rx));
		}
	}
}
int main()
{
	int t,n;
	int i,j,s,e;
	LL sum,tmp;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d",&n);
		len = sum = 0;
		for(i = 0;i < n;i ++)
		{
			scanf("%d%d%d",&mat[i].s,&mat[i].e,&mat[i].p);
			mat[i].e += mat[i].s;
			b[len++] = mat[i].s;
			b[len++] = mat[i].e;
		}
		sort(b,b+len);
		len = unique(b,b+len) - b;
		build(1,0,len-1);
		sort(mat,mat+n,comp);
		for(i = 0;i < n;i ++)
		{
			s = bfind(mat[i].s);
			e = bfind(mat[i].e);
			tmp = queue(1,0,len-1,0,s);
			tmp += mat[i].p;
			if(sum < tmp) sum = tmp;
			updata(1,0,len-1,e,tmp);
		}
		printf("%lld\n",sum);
	}
	return 0;
}
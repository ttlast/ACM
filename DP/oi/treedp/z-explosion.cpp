#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long int LL;
const int maxn = 100400;
struct Node{
	int pos,ypos,r;
	int cl,cr;
};
Node mat[maxn];
bool comp(const Node & t1,const Node & t2)
{
	return t1.pos < t2.pos;
}
int pos[maxn];

int findl(int n,int val)
{
	int l,r,mid;
	l = 0;r = n-1;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(pos[mid] < val) l = mid + 1;
		else r = mid - 1;
	}
	return l;
}

int findr(int n,int val)
{
	int l,r,mid;
	l = 0;r = n-1;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(pos[mid] <= val) l = mid + 1;
		else r = mid - 1;
	}
	return r;
}

struct CNode{
	int l,r;
	int ll,rr;
};
CNode cmat[maxn*4];

void build(int l,int r,int index)
{
	if(l == r)
	{
		cmat[index].l = cmat[index].r = l;
		cmat[index].ll = mat[l].cl;
		cmat[index].rr = mat[l].cr;
	}else
	{
		int mid = (l+r)>>1;
		build(l,mid,index<<1);
		build(mid+1,r,(index<<1)+1);
		cmat[index].l = l; cmat[index].r = r;
		cmat[index].ll = min(cmat[index<<1].ll,cmat[(index<<1)+1].ll);  //所能炸的最左最右炸弹号（排序后）
		cmat[index].rr = max(cmat[index<<1].rr,cmat[(index<<1)+1].rr);
	}
}



CNode findtree(int l,int r,int index)
{
	if(l <= cmat[index].l && r >= cmat[index].r)
	{
		return cmat[index];
	}else
	{
		int mid;
		mid = (cmat[index].l + cmat[index].r)>>1;
		if(r <= mid) return findtree(l,r,index<<1);
		else if(l > mid) return findtree(l,r,(index<<1)+1);
		else{
			CNode tmp,tmp2;
			tmp = findtree(l,r,index<<1);
			tmp2 = findtree(l,r,(index<<1)+1);
			tmp.ll = min(tmp.ll,tmp2.ll);
			tmp.rr = max(tmp.rr,tmp2.rr);
			return tmp;
		}
	}
}

void updata(int pos,int ll,int rr,int l,int r,int index)
{
	if(l == pos && r == pos)
	{
		cmat[index].ll = ll; cmat[index].rr = rr;
	}else{
		int mid = (l+r)>>1;
		if(pos <= mid) updata(pos,ll,rr,l,mid,index<<1);
		else updata(pos,ll,rr,mid+1,r,(index<<1)+1);
		cmat[index].ll = min(cmat[index<<1].ll,cmat[(index<<1)+1].ll);  //所能炸的最左最右炸弹号（排序后）
		cmat[index].rr = max(cmat[index<<1].rr,cmat[(index<<1)+1].rr);
	}
}
int main()
{
	int n,i,s,sum;
	scanf("%d",&n);
	for(i = 0;i < n;i ++)
	{
		scanf("%d",&mat[i].pos);
		mat[i].ypos = i+1;
	}
	for(i = 0;i < n;i ++)
		scanf("%d",&mat[i].r);
	sort(mat,mat+n,comp);
	for(i = 0;i < n;i ++)
		pos[i] = mat[i].pos;
	for(i = 0;i < n;i ++)
	{
		mat[i].cl = findl(n,mat[i].pos - mat[i].r);  //自己爆炸所能达到最左 ~ 最右
		mat[i].cr = findr(n,mat[i].pos + mat[i].r);
	}
	build(0,n-1,1);
	s = n+1;
	sum = 0;
	for(i = 0;i < n;i ++)
	{
		int ll,rr;
		ll = mat[i].cl;
		rr = mat[i].cr;
		do{
			CNode tmp = findtree(ll,rr,1);
			if(ll != tmp.ll || rr != tmp.rr)
			{
				ll = tmp.ll;
				rr = tmp.rr;
			}else break;
		}while(1);
		updata(i,ll,rr,0,n-1,1);
		if(rr - ll + 1 > sum)
		{
			sum = rr - ll + 1;
			s = mat[i].ypos;
		}else if(rr - ll + 1 == sum && s > mat[i].ypos)
			s = mat[i].ypos;
	}
	printf("%d %d\n",s,sum);
	return 0;
}

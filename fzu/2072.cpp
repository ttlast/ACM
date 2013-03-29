#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
const int maxn = 100005;
struct Node{
	int v,pos;
};
Node mat[maxn];
int n;
bool comp(const Node & t1,const Node &t2)
{
	if(t1.v != t2.v) return t1.v < t2.v;
	return t1.pos < t2.pos;
}
int lbfind(int val)
{
	int l,r,mid;
	l = 0;r = n-1;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(mat[mid].v < val) l = mid + 1;
		else r = mid - 1;
	}
	if(mat[l].v == val) return l;
	return -1;
}
int rbfind(int val)
{
	int l,r,mid;
	l = 0;r = n-1;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(mat[mid].v <= val) l = mid + 1;
		else r = mid - 1;
	}
	if(mat[r].v == val) return r;
	return -1;
}

int llbfind(int val,int l,int r)
{
	int mid;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(mat[mid].pos < val) l = mid + 1;
		else r = mid - 1;
	}
	return l;
}
int rrbfind(int val,int l,int r)
{
	int mid;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(mat[mid].pos <= val) l = mid + 1;
		else r = mid - 1;
	}
	return r;
}
int main()
{
	int q,i,j,l,r,x,ans = 0,cl,cr;
	while(scanf("%d%d",&n,&q)!=EOF)
	{
		for(i = 0;i < n;i ++)
		{
			scanf("%d",&mat[i].v);
			mat[i].pos = i+1;
		}
		sort(mat,mat+n,comp);
		for(i = 0;i < q;i ++)
		{
			scanf("%d%d%d",&l,&r,&x);
			cl = lbfind(x);
			cr = rbfind(x);
			if(cl == -1) ans = 0;
			else{
				l = llbfind(l,cl,cr);
				r = rrbfind(r,cl,cr);
				ans = r-l+1;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
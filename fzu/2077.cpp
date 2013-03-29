#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
typedef __int64 LL;
const int maxn = 100005;

struct Node{
	int a,b;
};
Node mat[maxn];
bool comp(const Node & t1,const Node & t2)
{
	if(t1.a != t2.a) return t1.a > t2.a;
	return t1.b > t2.b;
}
int que[maxn],qs,qe,data[maxn];
int n,m;
inline LL height(int s,int x)
{
	return (LL) mat[s].b*x + mat[s].a;
}
int bfind(int a,int b)
{
	int l,r,mid;
	l = 0;r = 100000;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(height(a,mid) > height(b,mid))
			l = mid+1;
		else r = mid - 1;
	}
	return l;
}
int rfind(int x)
{
	int l,r,mid;
	l = 0;r = qe-1;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(data[mid] <= x)
			l = mid + 1;
		else r = mid - 1;
	}
	return r;
}
int main()
{
	int i,j,d,x;
	int l,r,mid;
	LL ans;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i = 0;i < n;i ++)
			scanf("%d%d",&mat[i].a,&mat[i].b);
		sort(mat,mat+n,comp);
		data[0] = que[0] = 0;
		qs = 0;qe = 1;
		for(i = 1;i < n;i ++)
		{
			if(mat[i].b <= mat[que[qe-1]].b)
				continue;
			if(height(i,100000) <= height(que[qe-1],100000))
				continue;
			l = 0;r = qe-1;
			while(l <= r)
			{
				mid = (l+r)>>1;
				if(height(que[mid],data[mid]) > height(i,data[mid]))
					l = mid + 1; //找第一个  <= i data[mid]
				else r = mid - 1; 
			}
			if(l == qe)
				d = bfind(que[qe-1],i);
			else d = bfind(que[l-1],i);
			qe = l;
			que[qe] = i;
			data[qe] = d;
			qe ++;
		}
		for(i = 0;i < m;i ++)
		{
			scanf("%d",&x);
			d = rfind(x);
			ans = (LL) mat[que[d]].b*x + mat[que[d]].a;
			printf("%I64d\n",ans);
		}
	}
	return 0;
}

/* 单调队列版
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
typedef __int64 LL;
const int maxn = 100005;

struct Node{
	int a,b;
};
Node mat[maxn];
bool comp(const Node & t1,const Node & t2)
{
	if(t1.a != t2.a) return t1.a > t2.a;
	return t1.b > t2.b;
}
int que[maxn],qs,qe,data[maxn];
int n,m;
LL height(int a,int b,int x)
{
	return (LL) b*x + a;
}
int bfind(int a,int b)
{
	int l,r,mid;
	l = 0;r = 100000;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(height(mat[a].a,mat[a].b,mid) > height(mat[b].a,mat[b].b,mid))
			l = mid+1;
		else r = mid - 1;
	}
	return l;
}
int rfind(int x)
{
	int l,r,mid;
	l = 0;r = qe-1;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(data[mid] <= x)
			l = mid + 1;
		else r = mid - 1;
	}
	return r;
}
int main()
{
	int i,j,d,x;
	LL ans;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i = 0;i < n;i ++)
			scanf("%d%d",&mat[i].a,&mat[i].b);
		sort(mat,mat+n,comp);
		data[0] = que[0] = 0;
		qs = 0;qe = 1;
		for(i = 1;i < n;i ++)
		{
			if(mat[i].b <= mat[i-1].b)
				continue;
			if(height(mat[i].a,mat[i].b,100000) <= height(mat[que[qe-1]].a,mat[que[qe-1]].b,100000))
				continue;
			while(qs < qe)
			{
				d = bfind(que[qe-1],i);
				if(d > data[qe-1]) break;
				qe --;
			}
			que[qe] = i;
			data[qe] = d;
			qe ++;
		}
		for(i = 0;i < m;i ++)
		{
			scanf("%d",&x);
			d = rfind(x);
			ans = (LL) mat[que[d]].b*x + mat[que[d]].a;
			printf("%I64d\n",ans);
		}
	}
	return 0;
}*/
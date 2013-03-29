#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
using namespace std;
const int maxn = 1005;

int a[maxn],n;
struct Node{
	int x,y,v;
};
Node mat[maxn*maxn];
bool comp(const Node & t1,const Node & t2)
{
	if(t1.v != t2.v)
		return t1.v < t2.v;
	return t1.x < t2.x;
}
int len;

bool check(int val,int p2,int p1)
{
	int l,r,mid;
	l = 0;r = len-1;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(mat[mid].v < val)
			l = mid + 1;
		else r = mid - 1;
	}
	while(mat[l].v == val && l < len)
	{
		if(mat[l].y != p1 && mat[l].x != p1 && mat[l].y != p2 && mat[l].x != p2)
			return true;
		l ++;
	}
	return false;
}

int main()
{
	int i,j,tm;
	while(scanf("%d",&n),n)
	{
		
		for(i = 0;i < n;i ++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		len = 0;
		for(i = 0;i < n;i ++)
			for(j = i+1;j < n;j ++)
			{
				tm = a[i] + a[j];
				mat[len].x = i;mat[len].y = j;
				mat[len++].v = tm;
			}
		sort(mat,mat+len,comp);
		for(i = n-1;i >= 0;i --)
		{
			for(j = i-1;j >= 0;j --)
			{
				tm = a[i] - a[j];
				if(check(tm,i,j))
					break;
			}
			if(j >= 0) break;
		}
		
		if(i >= 0) printf("%d\n",a[i]);
		else printf("no solution\n");
	}
	return 0;
}
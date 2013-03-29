#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 500005;
struct Node{
	int x,y;
};
Node mat[maxn];
bool comp(const Node & t1,const Node & t2)
{
	if(t1.y != t2.y) return t1.y < t2.y;
	else return t1.x > t2.x;
}
int dp[maxn],n,ln;
int bf(int s,int len)
{
	int l,r,mid;
	l = 0;r = len;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(mat[s].x - mat[dp[mid]].x >= mat[s].y - mat[dp[mid]].y) l = mid + 1;
		else r = mid - 1;
	}
	return l;
}
int main()
{
	int i,pos;
	while(scanf("%d",&n)!=EOF)
	{
		for(i = 0;i < n;i ++)
		{
			mat[i].x = i;
			scanf("%d",&mat[i].y);
		}
		sort(mat,mat+n,comp);
		i = 0;
		while(mat[i].y > mat[i].x + 1 && i < n) i ++;
		if(i < n) 
		{
			ln = 1;dp[0] = i;
		}else ln = 0;
		for(i = i + 1;i < n;i ++)
		{
			if(mat[i].y <= mat[i].x + 1)
			{
				pos = bf(i,ln-1);
				dp[pos] = i;
				if(pos >= ln) ln ++;
			}
		}
		printf("%d\n",ln);
	}
	return 0;
}
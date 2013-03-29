#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 10008;
struct Node{
	int l,r,v;
};
int n;
LL dp[maxn*2];
Node mat[maxn];
bool comp(const Node & t1,const Node & t2)
{
	return t1.r < t2.r;
}
int bit[maxn*2];
int bsh(int val,int cn)
{
	int mid,l,r;
	l =  0; r = cn;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(val < bit[mid]) r = mid - 1;
		else if(val == bit[mid]) return mid;
		else if(val > bit[mid]) l = mid + 1;
	}
	return mid;
}
int main()
{
	int i,j,t,cn;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d",&n);
		cn = 0;
		for(i = 0;i < n;i ++)
		{
			scanf("%d%d%d",&mat[i].l,&mat[i].r,&mat[i].v);
			bit[cn++] = mat[i].l;
			mat[i].r += mat[i].l;
			bit[cn++] = mat[i].r;
		}
		sort(bit,bit+cn);
		cn = unique(bit,bit+cn) - bit;
		for(i = 0;i < n;i ++)
		{
			mat[i].l = bsh(mat[i].l,cn-1);
			mat[i].r = bsh(mat[i].r,cn-1);
		}
		sort(mat,mat+n,comp);
		dp[0] = 0;
		for(i = 1,j = 0;i < cn;i ++)
		{
			dp[i] = dp[i-1];
			while(j < n && mat[j].r == i)
			{
				dp[i] = max(dp[i],dp[mat[j].l] + mat[j].v);
				j ++;
			}
		}
		printf("%lld\n",dp[cn-1]);
	}
	return 0;
}
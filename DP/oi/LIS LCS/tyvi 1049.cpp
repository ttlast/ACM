#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 5005;
int bs(int a[],int n,int t)
{
	int l,r,mid,best;
	l = 0;r = n-1;
	best = 0;
	while(r >= l)
	{
		mid = (l+r)>>1;
		if(a[mid] <= t)
		{
		   l = mid + 1;
		}else r = mid -1;
	}
	return l;
}
int main()
{
	int i,j,n,num[maxn],dp[maxn],l,si;
	while(scanf("%d",&n)!=EOF)
	{
		for(i = 0;i < n;i ++)
				scanf("%d",&num[i]);
		l = 0;
		for(i = 0;i < n;i ++)
		{
			si = bs(dp,l,num[i]);
			if(si >= l)
			{
				dp[l++] = num[i];
			}else if(dp[si] > num[i]) dp[si] = num[i];
		}
		printf("%d\n",l);
	}
	return 0;
}
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define lowbit(x) ((x)&(-(x)))
const int P = 5000000;
const int Maxn = 10006;

int st[Maxn],b[Maxn],len;
int dp[55][Maxn];

int bfind(int val)
{
	int l,r,mid;
	l = 0; r = len - 1;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(b[mid] == val) return mid;
		else if(b[mid] < val) l = mid + 1;
		else r = mid - 1;
	}
}

int Getsum(int k,int x)
{
	int sum = 0;
	while(x > 0)
	{
		sum += dp[k][x];
		if(sum >= P) sum -= P;
		x -= lowbit(x);
	}
	return sum;
}

void Add(int k,int x,int val)
{
	while(x <= len)
	{
		dp[k][x] += val;
		if(dp[k][x] >= P) dp[k][x] -= P;
		x += lowbit(x);
	}
}

int main()
{
	int n,k,sum;
	int i,j,s,t;
	scanf("%d%d",&n,&k);
	for(i = 0;i < n;i ++)
	{
		scanf("%d",&st[i]);
		b[i] = st[i];
	}
	sort(b,b+n);
	len = unique(b,b+n) - b;
	
	for(i = 0;i < n;i ++)
	{
		s = bfind(st[i]);
		s ++;
		Add(1,s,1);
		for(j = 1;j < k;j ++)
		{
			t = Getsum(j,s-1);
			Add(j+1,s,t);
		}
	}
	sum = Getsum(k,len);
	if(k >= P) k -= P;
	if(k < 0) k += P;
	printf("%d\n",sum);
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define lowbit(x) ((x)&(-x))
const int P = 9901;
const int maxn = 100000;
int bit[maxn*4],n,d,cn;
int a[maxn],b[maxn*4];

void Update(int index,int n,int val)
{
	while(index <= n)
	{
		bit[index] += val;
		if(bit[index] >= P) bit[index] -= P;
		index += lowbit(index);
	}
}
int Sum(int index)
{
	int ret = 0;
	while(index > 0)
	{
		ret += bit[index];
		if(ret >= P) ret -= P;
		index -= lowbit(index);
	}
	return ret;
}
int Bsearch(int val,int n)
{
	int l,mid,r;
	l = 0;r = n;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(b[mid] == val)  break;
		else if(b[mid] > val) r = mid - 1;
		else l = mid + 1;
	}
	return mid+1;
}
int main()
{
	int i,j,c1,c2,c3,s,ret;
	while(scanf("%d%d",&n,&d)!=EOF)
	{
		cn = 0;
		for(i = 0;i < n;i ++)
		{
			scanf("%d",&a[i]);
			b[cn++] = a[i] - d;
			b[cn++] = a[i];
			b[cn++] = a[i] + d;
		}
		sort(b,b+cn);
		cn = unique(b,b+cn) - b;
		ret = 0;
		for(i = 0;i <= cn;i ++) bit[i] = 0;
		for(i = 0;i < n;i ++)
		{
			c1 = Bsearch(a[i]-d,cn-1);
			c2 = Bsearch(a[i],cn-1);
			c3 = Bsearch(a[i]+d,cn-1);
			s = Sum(c3) - Sum(c1-1);
			if(s < 0) s += P;
			ret += s;
			if(ret >= P) ret -= P;
			Update(c2,cn,s+1);
		}
		printf("%d\n",ret);
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
const int maxn = 10005;

int a[maxn];
int bfind(int val,int r)
{
	int l,mid;
	l = 0;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(a[mid] <= val) l = mid +1;
		else r = mid - 1;
	}
	return l;
}
int main()
{
	int n,x,t,pos,i;
	x = 0;
	while(scanf("%d",&a[x])!=EOF)
	{
		pos = bfind(a[x],x);
		if(pos < x)
		{
			t = a[x];
			for(i = x;i >= pos;i --)
				a[i+1] = a[i];
			a[pos] = t;
		}
		x ++;
		t = x/2;
		if(x&1) printf("%d\n",a[t]);
		else printf("%d\n",(a[t]+a[t-1])/2);
	}
	return 0;
}
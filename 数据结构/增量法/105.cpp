#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
const int maxn = 10005;

int a[maxn];
int main()
{
	int n,l,r,h,i,maxr;
	maxr = 0;
	while(scanf("%d%d%d",&l,&h,&r)!=EOF)
	{
		for(i = l;i < r;i ++)
			if(a[i] <= h) a[i] = h;
		if(maxr < r) maxr = r;
	}
	printf("1 %d ",a[1]);
	for(i = 2;i < maxr;i ++)
	{
		if(a[i] == a[i-1]) continue;
		printf("%d %d ",i,a[i]);
	}
	printf("%d 0\n",maxr);
}
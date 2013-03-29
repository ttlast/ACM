#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <ctime>
#include <queue>
#include <cstring>
using namespace std;
#define lowbit(x) ((x)&(-(x)))
const int maxdn = 1000005;
const int maxn = (1<<22)-1;

int pos[maxn];
int a[maxdn];
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i = 1;i <= n;i ++)
	{
		scanf("%d",&a[i]);
		pos[maxn^a[i]] = i;
	}
	for(i = maxn;i >= 1;i --)
		if(pos[i] != 0)
			for(j = i;j > 0;j -= lowbit(j))
				pos[i-lowbit(j)] = pos[i];
	for(i = 1;i <= n;i ++)
	{
		if(i != 1) printf(" ");
		if(pos[a[i]] != 0) printf("%d",a[pos[a[i]]]);
		else printf("-1");
	}
	printf("\n");
	return 0;
}
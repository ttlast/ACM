#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
const int maxn = 3005;
#define _abs(x) (x) > 0 ? (x):(-(x))

int hash[maxn];
int a[maxn];
int main()
{
	int n,i,j,t;
	while(scanf("%d",&n)!=EOF)
	{
		for(i = 1;i < n;i ++)
			hash[i] = 0;
		if(n > 0) scanf("%d",&a[0]);
		for(i = 1;i < n;i ++)
		{
			scanf("%d",&a[i]);
			t = _abs(a[i]-a[i-1]);
			if(t < n) hash[t] = 1;
		}
		for(i = 1;i < n;i ++)
			if(!hash[i]) break;
		if(i < n) printf("Not jolly\n");
		else printf("Jolly\n");
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 1005;

int v[maxn];
int main()
{
	int t,n,i,ans;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d",&n);
		ans = 0;
		for(i = 1;i <= n;i ++)
			scanf("%d",&v[i]);
		sort(v+1,v+n+1);
		for(i = n;i >= 1;i --)
			v[i] = v[i] - v[i-1] - 1;
		for(i = n;i > 0;i -= 2) ans ^= v[i];
		if(!ans) printf("Bob will win\n");
		else printf("Georgia will win\n");
	}
	return 0;
}
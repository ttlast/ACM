#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 30;

int main()
{
	int n,i,v,ans;
	while(scanf("%d",&n)!=EOF)
	{
		for(i = 0,ans = 0;i < n;i ++)
		{
			scanf("%d",&v);
			ans ^= v;
		}
		if(ans) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
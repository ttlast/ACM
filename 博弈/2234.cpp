#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <cstring>
using namespace std;

int main()
{
	int n,i,ans,v;
	while(scanf("%d",&n)!=EOF)
	{
		ans = 0;
		for(i = 0;i < n;i ++)
		{
			scanf("%d",&v);
			ans ^= v;
			
		}
		if(ans) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <cstring>
using namespace std;

int main()
{
	int n,i,t,ans,m,l;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d",&n);
		ans = 0;
		for(i = 0;i < n;i ++)
		{
			scanf("%d%d",&m,&l);
			ans ^= (m%(l+1));
		}
		if(!ans) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
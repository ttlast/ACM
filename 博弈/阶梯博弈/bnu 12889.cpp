#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 50005;

int main()
{
	int n,m,i,j,ans,v;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		ans = 0;
		for(i = 1;i <= n;i ++)
			for(j = 1;j <= m;j ++)
			{
				scanf("%d",&v);
				if((j^m)&1) ans ^= v;
			}
		if(n == 1) printf("Bob\n");
		else{
			if(ans) printf("Alice\n");
			else printf("Bob\n");
		}
	}
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 10005;

int n;
int v[maxn];
int main()
{
	int t,ncase = 0,ans,i,j;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d",&n);
		for(i = 1;i <= n;i ++)
			scanf("%d",&v[i]);
		if(n >= 2) ans = v[2];
		else ans = 0;
		for(i = 5;i <= n;i ++)  //1 3 4
		{
			if(i&1){   //ÆæÊý
				if(i%3 == 2) ans ^= v[i];
			}else{
				if(i%3 == 0) ans ^= v[i];
				else if(i%3 == 2) ans ^= v[i];
			}
		}
		ncase ++;
		printf("Case %d: ",ncase);
		if(ans) printf("Alice\n");
		else printf("Bob\n");
	}
	return 0;
}
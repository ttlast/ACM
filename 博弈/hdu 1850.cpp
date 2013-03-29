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
	int n,i,j,ans,tmp;
	while(scanf("%d",&n),n)
	{
		ans = 0;
		for(i = 0;i < n;i ++)
		{
			scanf("%d",&v[i]);
			ans ^= v[i];
		}
		if(ans)
		{
			tmp = 0;
			for(i = 0;i < n;i ++)
				if((ans^v[i]) < v[i]) tmp ++;
			printf("%d\n",tmp);
		}else printf("0\n");
	}
}
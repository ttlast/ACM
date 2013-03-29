#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <cstring>
using namespace std;
const int maxe = 10005;
const int maxn = 105;
int val[maxn];
int ss[maxe];
int sg[maxe];

int main()
{
	int n,i,j,k,m,maxd,ans,v;
	while(scanf("%d",&n),n)
	{
		for(i = 0;i < maxe;i ++) sg[i] = 0;
		for(i = 0;i < n;i ++)
			scanf("%d",&val[i]);
		sort(val,val+n);
		for(i = 0;i < n;i ++)
			sg[val[i]] = 1;  //Ê¤Àû
		maxd = 0;
		for(i = 1;i < maxe;i ++)
		{
			for(j = 0;j < n && val[j] <= i;j ++)
			{
				ss[sg[i-val[j]]] = 1;
				if(sg[i-val[j]] > maxd) maxd = sg[i-val[j]];
			}
			for(j = 0;;j ++)
				if(ss[j] == 0) break;
			sg[i] = j;
			for(j = 0;j <= maxd;j ++) ss[j] = 0;
		}

		scanf("%d",&m);
		for(i = 0;i < m;i ++)
		{
			scanf("%d",&k);
			ans = 0;
			for(j = 0;j < k;j ++)
			{
				scanf("%d",&v);
				ans ^= sg[v];
			}
			if(ans) printf("W");
			else printf("L");
		}
		printf("\n");
	}
	return 0;
}
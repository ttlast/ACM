#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <math.h>
using namespace std;
const int inf = 1 << 30;
const int maxn = 20;
int np[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072};
int n,t;
int dp[1<<17],dpd[1<<17],udp[1<<17];
int d[maxn],c[maxn],out[maxn],len;
char pn[maxn][108];
int main()
{
	int i,j,l,k,tm;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d",&n);
		for(i = 0;i < n;i ++)
		{
			scanf("%s%d%d",pn[i],&d[i],&c[i]);
		}
		l = np[n]-1;
		for(i = 1;i <= l;i ++)
			dp[i] = inf,dpd[i] = 0,udp[i] = -1;
		for(i = 1;i <= l;i ++)
		{
			for(j = 0;j < n;j ++)
			{
				if(np[j] & i)
				{
					k = i - np[j];
				    if(dpd[k] + c[j] > d[j]) tm = dpd[k] + c[j] - d[j];
					else tm = 0;
					if(dp[i] > dp[k] + tm)
					{
						dpd[i] = dpd[k] + c[j];
						dp[i] = dp[k] + tm;
						udp[i] = j;
					}else if(dp[i] == dp[k] + tm)
					{
						if(udp[i] == -1) 
						{
							udp[i] = j;
						}
						else
						{
							udp[i] = max(udp[i],j);
						}
					}
				}
			}
		}
		printf("%d\n",dp[l]);
		len = 0;
		j = l;
		while(j > 0)
		{
			out[len++] = udp[j];
			j -= np[udp[j]];
		}
		for(i = len -1;i >= 0;i --)
			printf("%s\n",pn[out[i]]);
	}
	return 0;
}
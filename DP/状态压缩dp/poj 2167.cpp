#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <math.h>
using namespace std;
const int maxn = 16;
const int N = 1<<16;
int np[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072};
char c[3000];
int leg[3000],len;
int n;
int num[maxn][maxn];
int dp[maxn][3000];
void getLeg()
{
	int i,tmp;
	len = 0;
	leg[len++] = 0;
	for(i = 1;i < N;i ++)
	{
		tmp = i;
		if(tmp&(tmp>>1)) continue;
		leg[len++] = i;
	}
}
int getId(int x)
{
	int l,r,mid,best;
	l = best = 0;r = len;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(leg[mid] > x)
			best = mid,r = mid - 1;
		else l  = mid + 1;
	}
	return best;
}
int main()
{
	int i,j,k,tm,l,ans,tmp;
	getLeg();
	while(gets(c))
	{
		n = 0;tm = 0;
		for(i = 0;c[i];i ++)
		{
			if(c[i] == ' ') num[0][n++] = tm ,tm = 0;
			else tm = tm*10 + c[i] - '0';
		}
		num[0][n++] = tm; tm = 0;
		for(j = 1;j < n;j ++)
		{
			gets(c);k = 0;
			for(i = 0;c[i];i ++)
			{
				if(c[i] == ' ') num[j][k++] = tm ,tm = 0;
				else tm = tm*10 + c[i] - '0';
			}
			num[j][k++] = tm; tm = 0;
		}
		memset(dp,0,sizeof(dp));
		gets(c);
		l = getId(np[n]-1);
		for(j = 0;j < l;j ++)
		{
			tm = leg[j];k = 0;
			dp[0][j] = 0;
			while(tm)
			{
				if(tm&1) dp[0][j] += num[0][k];
				k ++;
				tm >>= 1;
			}
		}
		for(i = 1;i < n;i ++)
		{
			for(j = 0;j < l;j ++)
			{
				tm = leg[j];k = 0;
				tmp = 0;
				while(tm)
				{
					if(tm&1) tmp += num[i][k];
					k ++;
					tm >>= 1;
				}
				for(k = 0;k < l;k ++)
				{
					if((leg[j]&leg[k]) || (leg[j]&(leg[k]>>1)) || (leg[j]&(leg[k]<<1))) continue;
						dp[i][j] = max(dp[i][j],dp[i-1][k] + tmp);
				}
			}
		}
		ans = 0;
		for(j = 0;j < l;j ++)
			if(dp[n-1][j] > ans) ans = dp[n-1][j];
		printf("%d\n",ans);
	}
	return 0;
}
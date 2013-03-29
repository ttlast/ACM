#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
const int maxn = 4000;
bool np[maxn];
int dp[maxn],s,t,n,m,len;
int pos[105],npos[105];
void init()
{
	int i,tmp,dis = 2*t;
	npos[0] = 0;
	memset(np,false,sizeof(np));
	for(i = 1;i < m;i ++)
	{
		tmp = pos[i] - pos[i-1];
		if(pos[i] - pos[i-1] > dis)
		{
			tmp = (pos[i] - pos[i-1] - dis)/t*t;
			tmp = pos[i] - pos[i-1] - tmp;
		}
		npos[i] = npos[i-1] + tmp;
		np[npos[i]] = true;
	}
}
void do_dp()
{
	int i,j,ans;
	np[npos[m-1]] = false;
	len = npos[m-1] + t;
	for(i = 0;i < s;i ++)
	{
		dp[i] = maxn;
	}
	dp[0] = 0;
	for(i = s;i < len;i ++)
	{
		if(np[i]){
			dp[i] = dp[i-s] + 1;
			for(j = s + 1;j <= t;j ++)
				if(i > j)
				{
					dp[i] = min(dp[i],dp[i-j]+1);
				}else break;
		}else{
			dp[i] = dp[i-s];
			for(j = s + 1;j <= t;j ++)
				if(i > j)
				{
					dp[i] = min(dp[i],dp[i-j]);
				}else break;
		}
	}
	ans = maxn;
	for(i = npos[m-1];i < len;i ++)
		if(ans > dp[i]) ans = dp[i];
	printf("%d\n",ans);
}
int main()
{
	int i;
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%d%d%d",&s,&t,&m);
		m ++;
		pos[0] = 0;
		for(i = 1;i < m;i ++) scanf("%d",&pos[i]);
		pos[m] = n;
		m ++;
		sort(pos,pos+m);
		while(pos[m-1] > n) m --;
		init();
		do_dp();
	}
	return 0;
}
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 105;

int a[maxn][maxn],n,tmp[maxn],tn,ans;

int dfn[maxn],low[maxn],mtn;
void dfs(int u,int v)
{
	int i,j,sz = 0;
	bool ss = false;
	low[u] = dfn[u] = mtn ++;
	for(i = 1;i <= n;i ++)
	{
		if(!a[u][i]) continue;
		if(i == v) continue;
		if(dfn[i])
		{
			low[u] = min(low[u],dfn[i]);
		}else{
			sz ++;
			dfs(i,u);
			low[u] = min(low[i],low[u]);
			if(low[i] >= dfn[u]) ss = true;
		}
	}
	if(u == 1)
	{
		if(sz > 1) ans ++;
	}
	else if(ss) ans ++;
}
int main()
{
	int i,j,l;
	char c[maxn*10];
	while(scanf("%d",&n),n)
	{
		gets(c);
		memset(a,0,sizeof(a));
		while(gets(c))
		{
			l = strlen(c);
			if(l == 1 && c[0] == '0') break;
			tn = 0;
			for(i = 0;i < l;i ++)
			{
				for(j = i;j < l;j ++)
					if(c[j] >= '0' && c[j] <= '9') break;
				tmp[tn] = c[j] - '0';
				for(j = j+1;j < l;j ++)
				{
					if(!(c[j] >= '0' && c[j] <= '9')) break;
					tmp[tn] = tmp[tn]*10 + c[j] - '0';
				}
				i = j;
				tn ++;
			}
			for(i = 1;i < tn;i ++)
				a[tmp[0]][tmp[i]] = a[tmp[i]][tmp[0]] = 1;
		}
		ans = 0;
		mtn = 1;
		memset(dfn,0,sizeof(dfn));
		dfs(1,1);
		printf("%d\n",ans);
	}
	return 0;
}
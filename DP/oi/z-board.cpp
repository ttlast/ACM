#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 505;
#define P 1000000000
typedef long long LL;
LL dp[maxn][maxn];
char cc[maxn][maxn];
int r,c,k,len;
char ss[1050];
void dfs(int cr,int cc,int l,int k)
{
	if(l == 0)
	{
		ss[len] = '\0';
	}else
	{
		if(cr == r-1)
		{
			ss[len-l] = 'R';
			dfs(cr,cc+1,l-1,k);
		}else if(cc ==  c-1)
		{
			ss[len-l] = 'D';
			dfs(cr+1,cc,l-1,k);
		}else
		{
			if(k <= dp[cr+1][cc])
			{
				ss[len-l] = 'D';
				dfs(cr+1,cc,l-1,k);
			}else{
				ss[len-l] = 'R';
				dfs(cr,cc+1,l-1,k-dp[cr+1][cc]);
			}
		}
	}
}
int main()
{
	int i,j;
	scanf("%d%d%d",&r,&c,&k);
	for(i = 0;i < r;i ++)
		scanf("%s",cc[i]);
	dp[r-1][c-1] = 1;
	if(cc[r-1][c-1] == '#') printf("impossible\n");
	else
	{
		for(i = c-2;i >= 0;i --)
			if(cc[r-1][i] != '#') dp[r-1][i] = dp[r-1][i+1];
			else dp[r-1][i] = 0;
		for(i = r-2;i >= 0;i --)
			if(cc[i][c-1] != '#') dp[i][c-1] = dp[i+1][c-1];
			else dp[i][c-1] = 0;
		for(i = r-2;i >= 0;i --)
			for(j = c-2;j >= 0;j --)
			{
				if(cc[i][j] != '#') dp[i][j] = dp[i][j+1] + dp[i+1][j];
				else dp[i][j] = 0;
				if(dp[i][j] >= P) dp[i][j] = P;
			}
			len = r + c - 2;
			if(dp[0][0] < k) printf("impossible\n");
			else 
			{
				dfs(0,0,len,k);
				printf("%s\n",ss);
			}
	}
	return 0;
}

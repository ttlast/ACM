#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 1000000000;
const int maxn = 1005; //O(n^2);
int dp[maxn][maxn];
int s[maxn][maxn];
int df[maxn];
void print(int i,int j)
{
	if(i == j) printf("A%d",j);
	else
	{
		printf("(");
	    print(i,s[i][j]);
		print(s[i][j]+1,j);
		printf(")");
	}
}
int main()
{
	int n,i,j,k;
	while(scanf("%d",&n)!=EOF)
	{
		for(i = 0;i <= n;i ++)   //n 个矩阵的n+1个行 与 列
			scanf("%d",&df[i]);
		memset(dp,0,sizeof(dp));
		for(i = 0;i < n;i ++) s[i][i] = i;
		for(i = 1;i < n;i ++)
			for(j = 0;j < n - i;j ++)
			{
				dp[j][j+i] = inf;
				for(k = j;k < j+i;k ++)
				{
					if(dp[j][j+i] > dp[j][k] + dp[k+1][j+i] + df[j] * df[k+1] * df[j+i+1])
					{
						dp[j][j+i] = dp[j][k] + dp[k+1][j+i] + df[j] * df[k+1] * df[j+i+1];
						s[j][j+i] = k;
					}
				}
			}
		printf("%d\n",dp[0][n-1]);
		print(0,n-1);
		printf("\n");
	}
	return 0;
}


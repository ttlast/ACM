#include <iostream>
using namespace std;
const int inf = 1000000000;
const int maxn = 310;
int n;
int dp[maxn][maxn],s[maxn][maxn],val[maxn],w[maxn][maxn];
int main()
{
    int i,j,len,k,a,b;
    while(scanf("%d",&n)!=EOF)
    {
      for(i = 1;i <= n;i ++)
      {
          scanf("%d",&val[i]);
          val[i] += val[i-1];
      }
      for(i = 1;i <= n;i ++)
        for(j = i+1;j <= n;j ++)
           w[i][j] = val[j] - val[i-1];
      for(i = 1;i <= n;i ++)
        s[i][i] = i,dp[1][i] = w[i][i];
      for(len = 2;len <= n;len ++)
	  {
		  for(i = n-len+1;i > 0;i --)
		  {
			  j = i+len-1;
			  a = s[i][j-1];
			  if(i == n-len+1) b = j-1;
			  else b = s[i+1][j];
			  dp[i][j] = inf;
			  for(k = a;k <= b;k ++)
			  {
				  if(dp[i][j] > dp[i][k]+dp[k+1][j] + w[i][j])
				  {
					  dp[i][j] = dp[i][k]+dp[k+1][j] + w[i][j];
					  s[i][j] = k;
				  }
			  }
		  }
	  }
      printf("%d\n",dp[1][n]);
    }
    return 0;
}

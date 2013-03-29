#include <iostream>
using namespace std;
const int maxn = 1002;
const int inf = 1000000000;
int n,m;
int val[maxn],sum[maxn],w[maxn][maxn],s[maxn][maxn];
int dp[maxn][maxn];
int main()
{
    int i,j,k;
    while(scanf("%d%d",&n,&m),n|m)
    {
	  m ++;
	  for(i = 1;i <= n;i ++) {scanf("%d",&val[i]);sum[i] = val[i];}
      for(i = 1;i <= n;i ++) sum[i] += sum[i-1];
      for(i = 1;i <= n;i ++)
        for(j = i-1;j > 0;j --)
          w[j][i] = w[j+1][i] + val[j]*(sum[i]-sum[j]);
      for(i = 1;i <= n;i ++) s[1][i] = 0,dp[1][i] = w[1][i];
      for(i = 2;i <= m;i ++)
      {
         s[i][n+1] = n;
         for(j = n;j >= i;j --)
         {
            dp[i][j] = inf;
            for(k = s[i-1][j];k <= s[i][j+1];k ++)
            {
              if(dp[i][j] > dp[i-1][k] + w[k+1][j])
              {
                 dp[i][j] = dp[i-1][k] + w[k+1][j];
                 s[i][j] = k;
              }
            }
         }
      }
      printf("%d\n",dp[m][n]);
    }
    return 0;
}

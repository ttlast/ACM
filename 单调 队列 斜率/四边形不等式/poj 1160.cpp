#include <iostream>
using namespace std;
const int inf = 1000000000;
const int maxn = 305;
int dp[maxn][maxn],w[maxn][maxn],val[maxn];
int s[maxn][maxn];
int main()
{
    int n,m,i,j,k,tmp;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
      for(i = 1;i <= n;i ++) scanf("%d",&val[i]);
      for(i = 1;i <= n;i ++)
      {
         w[i][i] = 0;
         for(j = i+1;j <= n;j ++) w[i][j] = w[i][j-1]+val[j]-val[(j+i)>>1];
      }
      for(i = 1;i <= n;i ++)
      {
         dp[i][1] = w[1][i];s[i][1] = 0;
      }
      for(i = 2;i <= m;i ++)
      {
         s[n+1][i] = n;
         for(j = n;j > i;j --)
         {
            dp[j][i] = inf;
            for(k = s[j][i-1];k <= s[j+1][i];k ++)
            {
               tmp = dp[k][i-1] + w[k+1][j];
               if(tmp < dp[j][i])
               {
                  dp[j][i] = tmp;
                  s[j][i] = k;
               }
            }
         }
      }
      printf("%d\n",dp[n][m]);
    }
    return 0;
}

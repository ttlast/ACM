#include <iostream>
using namespace std;
const int maxn = 1005;
const int inf = 1000000000;
int x[maxn],y[maxn];
int n,dp[maxn][maxn],s[maxn][maxn];
int dis(int i,int k,int j)
{
    return y[k]-y[j]+x[k+1]-x[i];
}

int main()
{
    int i,j,k;
    while(scanf("%d",&n)!=EOF)
    {
       for(i = 1;i <= n;i ++) scanf("%d%d",&x[i],&y[i]);
       for(i = 1;i <= n;i ++) s[i][i] = i;
       for(i = 1;i < n;i ++)
       {
          for(j = n-i;j >= 1;j --)
          {
             dp[j][j+i] = inf;
             for(k = s[j][j+i-1];k <= s[j+1][j+i]&&k < i+j;k ++)
             {
                if(dp[j][j+i] > dp[j][k]+dp[k+1][j+i]+dis(j,k,j+i))
                {
                   dp[j][j+i] = dp[j][k]+dp[k+1][j+i]+dis(j,k,j+i);
                   s[j][j+i] = k;
                }
             }
          }
       }
       printf("%d\n",dp[1][n]);
    }
    return 0;
}

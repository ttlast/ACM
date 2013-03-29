//区间dp 四边形不等式
#include <iostream>
using namespace std;
const int inf = 1000000000;
const int  maxn = 2005;
int dp[maxn][maxn],w[maxn][maxn],s[maxn][maxn],n,val[maxn];
int main()
{
    int i,j,k,a,b,n2,ans;
    while(scanf("%d",&n)!=EOF)
    {
       for(i = 1;i <= n;i ++)
       {
         scanf("%d",&val[i]);
         val[i+n] = val[i];
       }
       n2 = n<<1;
       for(i = 1;i <= n2;i ++)
       {
          s[i][i] = i;
          val[i] += val[i-1];
       }
       for(i = 1;i < n;i ++)
       {
         for(j = n2-i;j >= 1;j --)
         {
            dp[j][j+i] = inf;
            for(k = s[j][j+i-1];k <= s[j+1][j+i];k ++)
            {
               if(dp[j][j+i] > dp[j][k] + dp[k+1][j+i] + val[j+i] - val[j-1])
               {
                  dp[j][j+i] = dp[j][k] + dp[k+1][j+i] + val[j+i] - val[j-1];
                  s[j][j+i] = k; 
               }
            }
         }
       }
       ans = inf;
       for(i = 1;i <= n;i ++)
        if(ans > dp[i][i+n-1]) ans = dp[i][i+n-1];
       printf("%d\n",ans);
    }
    return 0;
}

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int inf = 1000000000;
const int maxn = 10005;
int dp[maxn][maxn],s[maxn][maxn],val[maxn],n,m;
int cal(int i,int j)
{
    return (val[j]-val[i])*(val[j]-val[i]);
}
int main()
{
    int i,j,k,t,ncase = 0;
    scanf("%d",&t);
    while(t--)
    {
      ncase ++; 
      scanf("%d%d",&n,&m);
      for(i = 1;i <= n;i ++) scanf("%d",&val[i]);
      sort(val+1,val+n+1);
      for(i = 1;i <= n;i ++) s[1][i] = 0,dp[1][i] = cal(1,i);
      for(i = 2;i <= m;i ++)
      {  
         s[i][n+1] = n;
         for(j = n;j >= i;j --)
         {
            dp[i][j] = inf;
            for(k = s[i-1][j];k <= s[i][j+1];k ++)
            {
              if(dp[i][j] > dp[i-1][k] + cal(k+1,j))
              {
                 dp[i][j] = dp[i-1][k]+cal(k+1,j);
                 s[i][j] = k;
              } 
            }
         }         
      }
      printf("Case %d: %d\n",ncase,dp[m][n]);      
    }
    return 0;
}

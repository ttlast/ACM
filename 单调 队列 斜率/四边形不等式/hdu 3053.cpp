#include <iostream>
#include <algorithm> 
using namespace std;
//滚动数组 + 四边形. 
const int inf = 1000000000;
const int maxn = 3002;
int pos[maxn];
int dp[2][maxn],s[2][maxn],w[maxn][maxn];
int main()
{
    int n,k,sign;
    int t,i,j,l,tmp;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d%d",&n,&k);
       for(i = 1;i <= n;i ++)
        scanf("%d",&pos[i]);
       sort(pos+1,pos+n+1);
       for(i = 1;i <= n;i ++)
       {
           w[i][i] = 0;
           for(j = i+1;j <= n;j ++) w[i][j] = w[i][j-1] + pos[j] - pos[(i+j)>>1];
       }
       sign = 1;
       for(i = 1;i <= n;i ++)
         s[0][i] = 0,dp[0][i] = w[1][i];
       for(i = 2;i <= k;i ++)
       {
          s[sign][n+1] =  n;
          for(j = n;j >= i;j --)  //only j n -->i make it change; 
          {
             dp[sign][j] = inf;
             for(l = s[!sign][j];l <=  s[sign][j+1];l ++)
             {
                tmp = dp[!sign][l] + w[l+1][j];
                if(tmp < dp[sign][j])
                {
                   dp[sign][j] = tmp;
                   s[sign][j] = l;
                } 
             } 
          }          
          sign ^= 1;
       }
       sign ^= 1;
       printf("%d\n",dp[sign][n]);
    }
    return 0;
}

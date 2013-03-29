#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long LL;
const int maxn = 11;
int digit[maxn],len;
LL dp[10][maxn];
void cls(){
    memset(dp,0,sizeof(dp));
}
void DP()
{
     int i,j,k;
     cls();
     for(i = 0;i < 10;i ++) dp[i][0] = 1;
     for(i = 1;i < maxn;i ++)
        for(j = 0;j < 10;j ++)
         for(k = 0;k < 10;k ++)
           if(abs(j-k) >= 2) dp[j][i] += dp[k][i-1];
}
LL check(LL a)
{
    int i,j,k,nc = 0,l1,l2;
    LL tmp = a,ans = 0;
    len = 0;
    while(a)  digit[len++] = a%10, a /= 10;
    if(len == 1) return a-1;
    for(i = 0;i < len-1;i ++) 
       for(j = 0;j <= 9;j ++)
          ans += dp[j][i];
    for(i = len-1;i >= 0;i --)
    {
       j = (i == len-1 ? 1:0);
       for(;j < digit[i];j ++)
       {
          if(i == len || abs(digit[i+1]-j) >= 2)
          {
             for(k = 0;k <= 9; k ++)
                if(abs(j-k) >= 2) ans += dp[k][i-1];
          }
       }
       if(i < len-1 && abs(digit[i+1]-digit[i])<2)
         return ans;
    }
    for(i = 0;i < digit[0];i ++)
        ans += abs(digit[1]-i) >= 2;
    return ans;
}
int main()
{
    int i,j;
    LL a,b;
    DP();
    while(scanf("%lld%lld",&a,&b)!=EOF)
    {
       b ++;
       a = check(a); b = check(b);
       printf("%lld\n",b-a);
    }
    return 0;
}

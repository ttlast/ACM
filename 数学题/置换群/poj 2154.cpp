#include <iostream>
#include <cmath>
using namespace std;
/*
 欧拉函数 + 快速幂 + 筛选质因数 
*/
const int maxn =  34000;
bool sign[maxn];
int p[maxn],num;
int n,m;
void init()
{
    int i,j;
    num = 0;
    p[num++]= 2;
    for(i = 4;i < maxn;i += 2) sign[i] = true;
    for(i = 3;i < maxn;i ++)
    {
       if(!sign[i])
       {
          p[num++] = i;
          for(j = i*i;j < maxn;j += i)
            sign[j] = true;
       }
    }
}
int euler(int x)
{
    int i,ans = x;
    for(i = 0;i < num;i ++)
    {
        if(x < p[i]) break;
        if(x%p[i] == 0)
        {
           ans = ans/p[i]*(p[i]-1);
           while(x%p[i] == 0) x /= p[i]; 
        }
    }
    if(x > 1) ans = ans/x*(x-1);
    return ans;
}
int pow_m(int a,int b)
{
    int ans = 1,t = a%m;
    while(b)
    {
       if(b&1) ans = (ans*t)%m;
       t = (t*t)%m;
       b >>= 1;
    }
    return ans;
}
int polya(int n)
{
    int i,j,ans = 0,t = sqrt(n*1.0)+1;
    for(i = 1;i < t;i ++)
    {
         if(n%i) continue;
         ans = (ans+(euler(n/i)%m)*pow_m(n,i-1))%m;
         if(i*i != n)
         {
            ans = (ans+(euler(i)%m)*pow_m(n,n/i-1))%m;
         }
         ans %= m;
    }
    return ans;
}
int main()
{
    int x,ans;
    init();
    scanf("%d",&x);
    while(x--)
    {
       scanf("%d%d",&n,&m);
       ans = polya(n);
       printf("%d\n",ans);
    }
    return 0;
}

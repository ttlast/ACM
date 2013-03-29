#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int maxn = 100;
bool noprim[maxn]= {0};
typedef unsigned __int64 u64;
u64 base[maxn];
int num[maxn],len,prim[maxn],pl;
int c[maxn],c_len;
u64 factor[maxn],c_factor[maxn][maxn];int fac_len;
u64 random()
{
    u64 a = rand();
    a *= rand(); a *= rand();
    a *= rand();
    return a;
}
void init()
{
     int i,j;
     num[0] = 2;len = 1;
     for(i = 4;i < 64;i += 2) noprim[i] = true;
     for(i = 3;i < 64;i += 2)
     {
         if(!noprim[i])
         {
             for(j = i*i;j < 64;j += i) noprim[j] = true;
             num[len] = i;len ++;
         }
     }
}
u64 Mulit_mod(u64 a,u64 b,u64 n)
{
    u64 ret = 0,temp = a%n;
    while(b > 0)
    {
        if(b&1) ret = ret+temp;
        if(ret > n) ret -= n;
        temp <<= 1;
        if(temp > n) temp -= n;
        b >>= 1;
    }
    return ret;
}
u64 Pow_mod(u64 a,u64 b,u64 n)
{
    u64 ret = 1,temp = a%n;
    while(b > 0)
    {
        if(b&1) ret = Mulit_mod(ret,temp,n);
        if(ret > n) ret -= n;
        temp = Mulit_mod(temp,temp,n);
        b >>= 1;
    }
    return ret;
}
bool Miller_Rabin(u64 n)
{
     if(n < 2) return false;
     if(n == 2) return true;
     if(!(n&1)) return false;
     int i,j,m = 0;
     u64 a,p = n-1,d;
     while(!(p&1)) p >>= 1,m ++;
     for(i = 0;i < len;i ++)
     {
          if(n <= num[i]) return true;
          a = Pow_mod(num[i],p,n);
          if(a == 1) continue;
          for(j = 0;j < m;j ++)
          {
              d = Mulit_mod(a,a,n);
              if(d == 1 && a != 1 && a != (n-1)) return false;
              a = d;
          }
          if(d != 1) return false;
     }
     return true;
}
u64 gcd(u64 a,u64 b)
{
    if(b == 0) return a;
    return gcd(b,a%b);
}
u64 Pollard_Rho(u64 k,u64 n)
{
    int i = 1,t = 2;
    u64 a,x,y,d;
    x = random()%(n-1)+1;
    y = x;
    while(1)
    {
       i ++;
       x = (Mulit_mod(x+1,x-1,n)+k)%n;
       d = gcd(y-x,n);
       if(d > 1 && d < n) return d;
       if(x == y) return n;
       if(t == i) y = x,t <<= 1;
    }
}
void Find_All_Factor(u64 n)
{
     if(Miller_Rabin(n))
     {
       factor[fac_len++] = n;
     }else
     {
        u64 fac = n,k = 100;
        while(fac >= n)
           fac = Pollard_Rho(k--,n);
        Find_All_Factor(fac);
        Find_All_Factor(n/fac);
     }
}
int main()
{
    init();
    int k,i,j;
    srand((unsigned)time(NULL));
    base[0] = 1;
    for(i = 1;i < 64;i ++) base[i] = base[i-1]*2;
    for(i = 0,c_len = 0;i < len;i ++)
    {
         if(Miller_Rabin(base[num[i]]-1)) continue;
         else
         {
             fac_len = 0;
             Find_All_Factor(base[num[i]]-1);
             c[c_len] = num[i];
             c_factor[c_len][0] = fac_len;
             for(j = 0;j < fac_len;j ++) c_factor[c_len][j+1] = factor[j];
             sort(c_factor[c_len]+1,c_factor[c_len]+fac_len+1);
             c_len ++;
         }
    }
    while(scanf("%d",&k)!= EOF)
    {
        for(i = 0;i < c_len;i ++)
        {
            if(k < c[i]) break;
            printf("%I64d",c_factor[i][1]);
            for(j = 2;j <= c_factor[i][0]; j ++) printf(" * %I64d",c_factor[i][j]);
            printf(" = %I64d = ( 2 ^ %d ) - 1\n",base[c[i]]-1,c[i]);
        }
    }
    return 0;
}

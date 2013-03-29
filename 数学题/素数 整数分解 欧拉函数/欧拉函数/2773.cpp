//二分 + 容斥原理 
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;
typedef unsigned long long u64;
const int maxn = 1000005;
const u64 inf = 1100000000000000;
u64 n,k,k2;
bool noprim[maxn] = {0};
int prim[80000],len;
int fac[100],flen;
void init()
{
     int i,j;
     prim[0] = 2;len = 1;
     for(i = 4;i < maxn;i += 2) noprim[i] = true;
     for(i = 3;i < maxn;i += 2)
     {
         if(!noprim[i])
         {
             for(j = i*2;j < maxn;j += i) noprim[j] = true;
             prim[len] = i;len ++;
         }
     }
}
void Dfs(int now,u64 mult,int num,int depth,u64 m,u64 & ans)
{
    int i;
    if(num == depth)
    {
        ans += m/mult;
    }else
    {
        for(i = now;i < flen;i ++)
        {
           if(mult*fac[i] > m) break;
           Dfs(i+1,mult*fac[i],num+1,depth,m,ans);
        }
    }
}
u64 check(u64 num)
{
    int i;u64 ret = num,tmp;
    for(i = 1;i <= flen;i ++)
    {
        tmp = 0;
        Dfs(0,1,0,i,num,tmp);
        if(i&1) ret -= tmp;
        else ret += tmp;
    }
    return ret;
}
void All_fac(u64 num)
{
     flen = 0;
     int i;
     for(i = 0;i < len;i ++)
     {
		 if(num < prim[i]) break;
         if(num%prim[i] == 0)
         {
             while(num%prim[i] == 0) num /= prim[i];
             fac[flen] = prim[i];flen ++;
         }
     }
}
int main()
{
    init();
    while(scanf("%lld%lld",&n,&k)!=EOF)
    {
        All_fac(n);
        u64 l = 1,r = inf,mid,ret,best;
        while(l <= r)
        {
           mid = (l+r)>>1;
           ret = check(mid);
           if(ret >= k)
           {
               best = mid;
               r = mid-1;
           }else l = mid+1;
        }
        printf("%llu\n",best);
    }
    return 0;
}

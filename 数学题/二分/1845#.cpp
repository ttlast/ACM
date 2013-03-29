#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef unsigned long long  u64;
u64 Mulit_mod(u64 a,u64 b,u64 c)
{
    u64 ret = 0,tmp = a%c;
    while(b)
    {
       if(b&1) ret += tmp;
       if(ret >= c) ret -= c;
       tmp <<= 1;
       if(tmp >= c) tmp -= c;
       b >>= 1;
    }
    return ret;
} 
u64 Pow_mod(u64 a,u64 b,u64 c)
{
    u64 ret = 1,tmp = a%c;
    while(b)
    {
       if(b&1) ret = Mulit_mod(ret,tmp,c);
       tmp = Mulit_mod(tmp,tmp,c);
       b >>= 1;
    }
    return ret;
} 
int main()
{
    u64 a,b,c;
    while(scanf("%llu%llu",&a,&b)!=EOF)
    {
       c = Pow_mod(a,b,9901);
       printf("%lld\n",c);
    }
    return 0;
} 

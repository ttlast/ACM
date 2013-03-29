#include <iostream>
using namespace std;
typedef unsigned long long u64;
char s[1000006];
u64 a,c,b,d;
u64 euler(u64 c)
{
    u64 ret = 1;
    int i;
    if(c%2 == 0)
    {
        c/= 2;
        while(c%2 == 0) c >>= 1,ret *= 2;
    }
    for(i = 3;i * i <= c;i += 2)
        if(c%i == 0)
        {
             c /= i;ret *= (i-1);
             while(c%i == 0) c /= i,ret *= i;
        }
    if(c > 1) ret *= c-1;
    return ret;
}
u64 strmod(char s[],u64 c)
{
    u64 ret = 0;
    int len = strlen(s),i;
    for(i = 0;i < len;i ++)
    {
        ret = ret*10 + s[i] - '0';
        while(ret >= c) ret -= c;
    }
    return ret;
}
int cmp(char s[],u64 x)
{
   u64 sum=0;
   int len=strlen(s),i;
   for(i=0;i<len;i++)
   {
      sum=sum*10+s[i]-'0';
       if(sum>x)
              return 1;
   }
   return 0;
}
u64 Pow_mod(u64 a,u64 b,u64 c)
{
    u64 ret = 1,tmp = a%c;
    while(b)
    {
        if(b&1) ret = (ret*tmp)%c;
        tmp = (tmp*tmp)%c;
        b >>= 1;
    }
    return ret;
}
int main()
{
    while(scanf("%llu%s%llu",&a,s,&c)!=EOF)
    {
        d = euler(c);
        if(cmp(s,d))
        {
        d = strmod(s,d)+d;
        }else d = strmod(s,d);
        a = Pow_mod(a,d,c);
        printf("%llu\n",a);
    }
    return 0;
}

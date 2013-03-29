#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long u64;
const int maxn = 65535;
struct Hash
{
    u64 a,b;
    int next;
}hash[maxn<<1];
int flag[maxn],top,idx;
void insert(u64 a,u64 b)
{
    int ind = b&maxn;
    if(flag[ind] != idx)
    {
        flag[ind] = idx;
        hash[ind].next = -1;
        hash[ind].a = a;hash[ind].b = b;
        return ;
    }
    while(hash[ind].next != -1)
    {
        if(hash[ind].b == b) return ;
        ind = hash[ind].next;
    }
    hash[ind].next = ++top;
    hash[top].next = -1;
    hash[top].a = a;hash[top].b = b;
}
u64 find(u64 b)
{
    int ind = b&maxn;
    if(flag[ind] != idx) return -1;
    while(ind != -1)
    {
        if(hash[ind].b == b) return hash[ind].a;
        ind = hash[ind].next;
    }
    return -1;
}
u64 gcd(u64 a,u64 b)
{
    return b ? gcd(b,a%b):a;
}
u64 extend_gcd(u64 a,u64 b,u64 &x,u64 &y)
{
    u64 t,ret;
    if(!b)
    {
        x = 1;y = 0; return a;
    }
    ret = extend_gcd(b,a%b,x,y);
    t = x;x = y; y = t - a/b*y;
    return ret;
}
u64 Mulit_mod(u64 a,u64 b,u64 c)
{
    return (a*b)%c;
    /*
    u64 ret = 0,tmp = a%c;
    if(tmp < 0) tmp += c;
    while(b)
    {
        if(b&1) ret = ret + tmp;
        if(ret >= c) ret -= c;
        tmp <<= 1;
        if(tmp >= c) tmp -= c;
        b >>= 1;
    }
    return ret;
    */
}
u64 Pow_mod(u64 a,u64 b,u64 c)
{
    u64 ret = 1%c,tmp = a%c;
    while(b)
    {
        if(b&1) ret = Mulit_mod(ret,tmp,c);
        tmp = Mulit_mod(tmp,tmp,c);
        b >>= 1;
    }
    return ret;
}
u64 Inval(u64 a,u64 b,u64 c)  //·µ»Øa*x = b mod c ÖÐx
{
    u64 x,y,e;
    extend_gcd(a,c,x,y);
    e = Mulit_mod(x,b,c);
    return e < 0 ? e+c : e;
}
int BabyStep(u64 a,u64 b,u64 c)
{
    ++idx;
    top = maxn;
    u64 buf = 1%c,D = buf,k,tmp;
    int i,d = 0;
    for(i = 0;i <= 100; ++i)
    {
        if(buf == b) return i;
        buf = Mulit_mod(buf,a,c);
    }
    while((tmp = gcd(a,c)) != 1)
    {
        if(b%tmp) return -1;
        ++d;
        c /= tmp;
        b /= tmp;
        D = (D*a/tmp)%c;
    }
    int m = (int) ceil(sqrt(c*1.0));
    for(i = 0,buf = 1%c;i <= m;++i)
    {insert(i,buf);buf = (buf*a)%c;}
    for(i = 0,k = Pow_mod(a,m,c);i <= m; D = (D*k)%c,++i)
    {
        tmp = Inval(D,b,c);
        int w;
        if(tmp > 0 && (w = find(tmp)) != -1) return i*m+w+d;
    }
    return -1;
}
int main()
{
    u64 a,b,c,ans;
    while(scanf("%I64d%I64d%I64d",&a,&c,&b)!=EOF)
    {
        if(b >= c) { puts("Orz,I can¡¯t find D!");continue;}
        ans = BabyStep(a,b,c);
        if(ans < 0) puts("Orz,I can¡¯t find D!");
        else printf("%I64d\n",ans);
    }
    return 0;
}

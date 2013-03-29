#include <iostream>
using namespace std;
typedef unsigned long long u64;
u64 gcd(u64 a,u64 b)
{
    if(b == 0) return a;
    return gcd(b,a%b);
}
int eular(int n){
	int ret=1,i;
	for (i=2;i*i<=n;i++)
		if (n%i==0){
			n/=i,ret*=i-1;
			while (n%i==0)
				n/=i,ret*=i;
		}
	if (n>1)
		ret*=n-1;
	return ret;
}
bool  pow(u64 i,u64 b)
{
    u64 tmp = 1,t = 2;
    while(i)
    {
        if(i&1) tmp = (tmp*t)%b;
        t = (t*t)%b;
        i >>= 1;
    }
    if(tmp == 1) return true;
    return false;
}
u64 find(u64 p,u64 b)  //根据同根性质。欧拉函数。 
{
    u64 tmp = p;
    int i;
    for(i = 1;i*i < p;i ++)
    {
        if(p%i == 0)
        {
        if(pow(i,b))
        {
           return i;
        }
        if(pow(p/i,b)) tmp = p/i;
        }
    }
    if(pow(i,b)) return i;
    else return tmp;
}
int main()
{
    int i,j,ncase = 0;
    u64 a,b,d,f,y,p;
    while(scanf("%llu/%llu",&a,&b)!=EOF)
    {
        while(a > b) a -= b;
        d = gcd(a,b);a /= d;b /= d;
        f = 0;
        ncase ++;
        if(a%b == 0)
        {
          printf("Case #%d: 0,0\n",ncase);
        }else
        {
        while(!(b&1)) b >>= 1,f ++;
        f ++;
        p = eular(b);
        y = find(p,b);
        printf("Case #%d: %llu,%llu\n",ncase,f,y);
        }
    }
    return 0;
}

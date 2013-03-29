#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int maxn = 2000;
const int mod = 10007;
typedef long long LL;
bool noprim[maxn] = {0};
int prim[maxn],len;
void init()
{
	int i,j;
	prim[0] = 2,len = 1;
	for(i = 4;i < maxn;i += 2) noprim[i] = true;
	for(i = 3;i < maxn;i += 2)
	{
		if(!noprim[i])
		{
			for(j = i*i;j < maxn;j += i) noprim[j] = true;
			prim[len++] = i;
		}
	}
}
int fac[100],num[100],nlen;
void check(int v)
{
	nlen = 0;
	int i;
	for(i = 0;i < len;i ++)
	{
		if(v < prim[i]) break;
		if(v%prim[i] == 0)
		{
			fac[nlen] = prim[i];
			num[nlen] = 0;
			while(v%prim[i] == 0)
			{
				num[nlen]++;
				v /= prim[i];
			}
			nlen ++;
		}
	}
	if(v != 1)
	{
		fac[nlen] = v;
		num[nlen] = 1;
		nlen ++;
	}
}
LL Powmod(LL n,LL m,LL p)
{
	LL ret = 1,tmp = n%p;
	while(m){
		if(m&1) ret = ((LL) ret*tmp)%p;
		tmp = ((LL) tmp*tmp)%p;
		m >>= 1;
	}
	return ret;
}
int main()
{
	LL ans,t;
	int a,b,ncase = 1,i,j;
	init();
	while(scanf("%d%d",&a,&b)==2)
	{
		if(a == 1)
		{
			printf("Case %d: 1\n",ncase++);
			continue;
		}
		check(a);
		//b = b%mod;
		
		for(i = 0,ans = 1;i < nlen;i ++)
			ans =((LL) ans*(num[i]*b))%mod;
		ans = (ans+1)%mod;
		
		for(i = 0,ans = 1;i < nlen;i ++)
		{
			t = num[i]*b+1;
			t = (t*(t+1)/2)%mod;
			t *= t;
			ans = (ans*t)%mod;//%mod;  //»ýÐÔº¯Êý
		}
		//ans = ans*Powmod(b,nlen,mod)%mod;
		//printf("%lld\n",ans);
		//ans = (((LL) (ans*ans)%mod)*(((LL)(ans+1)*(ans+1))%mod)*Powmod(4,mod-2,mod))%mod;

		if(ans < 0) ans += mod;
		printf("Case %d: %lld\n",ncase++,ans);
	}
	return 0;
}

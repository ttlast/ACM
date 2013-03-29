#include <iostream>
using namespace std;
typedef __int64 LL;
const int maxn = 40000;
bool noprim[maxn] = {0};
LL n,m;
int prim[maxn],len;
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
			prim[len++] = i;
		}
	}
}
LL Eular(LL m)
{
	LL ret = 1,i;
	for(i = 0;i < len;i ++)
	{
		if(m < prim[i]) break;
		if(m%prim[i] == 0)
		{
			m /= prim[i];
			ret *= (prim[i] -1);
			while(m%prim[i] == 0)
			{
				m /= prim[i];
				ret *= prim[i];
			}
		}
	}
	if(m != 1) ret *= (m-1);
	return ret;
}
LL Mulit_mod(LL a,LL b,LL m)
{
	LL ret = 0,tmp = a%m;
	while(b)
	{
		if(b&1) ret += tmp;
		if(ret >= m) ret -= m;
		tmp <<= 1;
		if(tmp >= m) tmp -= m;
		b >>= 1;
	}
	return ret;
}
LL Pow_mod(LL a,LL b,LL m)
{
	LL ret = 1%m,tmp = a%m;
	while(b)   //此处溢出了几次
	{
		if(b&1) ret = Mulit_mod(ret,tmp,m);
		tmp = Mulit_mod(tmp,tmp,m);
		b >>= 1;
	}
	return ret;
}
bool larger(LL a,LL b,LL c)
{
	LL ret = 1,i = 0;
	for(i = 0;i < b;i ++)
	{
		ret *= a;
		if(ret >= c) return true;
	}
	return false;
}
LL F(LL n,LL m)
{
	LL ret,e,fn;
	if(n == 0) return 1%m;
	if(m == 1) return 0;
	e = Eular(m);
	ret = n%10;
	fn = F(n/10,e);
	if(larger(ret,fn,m)) ret = Pow_mod(ret,fn,m)+m;  //指数上取余防止归0
	else ret = Pow_mod(ret,fn,m);
	return ret;
}
int main()
{
	int t;
	scanf("%d",&t);
	init();
	while(t--)
	{
		scanf("%I64d%I64d",&n,&m);
		//e = Eular(m);
		printf("%I64d\n",F(n,m)%m);
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef long long LL;
LL Powmod(LL n,LL m,LL p)
{
	LL ret = 1,tmp = n%p;
	while(m){
		if(m&1) ret = (ret*tmp)%p;
		tmp = (tmp*tmp)%p;
		m >>= 1;
	}
	return ret;
}
LL Cm(LL n,LL m,LL p)
{
	if(m > n) return 0;
	LL i,ans = 1;
	for(i = 1;i <= m;i ++)
		ans = ((ans*(n-i+1)%p)*Powmod(i,p-2,p)%p);
	return ans;
}
LL Luscas(LL n,LL m,LL p)
{
	if(m == 0) return 1;
	return (Luscas(n/p,m/p,p)*Cm(n%p,m%p,p))%p;
}
int main()
{
	int t;
	LL m,n,p,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%I64d%I64d%I64d",&n,&m,&p);
		ans = Luscas(n,m,p);
		if(ans < 0) ans += p;
		printf("%I64d\n",ans);
	}
	return 0;
}
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef __int64 LL;
const int maxn = 100;
LL gcd(LL a,LL b)
{
	if(b == 0) return a;
	else return gcd(b,a%b);
}
LL lcm(LL a,LL b)
{
	return a*b/gcd(a,b);
}
LL check(LL tmp)
{
	LL a = 1,b = 1,c;
	int num = 1;
	while(1)
	{
		c = (a+b)%tmp;
		num ++;
		if(b%tmp == 1 && c%tmp == 1) return num - 1;
		a = b; b = c;
	}
}
int main()
{
	int i,j,n,ncase = 1;
	LL ans;
	scanf("%d",&n);
	while(scanf("%d",&n)!=EOF)
	{
		ans = 1;
		if(n == 1) ans = 1;
		else{
			int sqrn = sqrt(n*1.0)+1;
			for(i = 2;i <= sqrn;i ++)
			{
				if(n < i) break;
				if(n%i == 0)
				{
					int si = 1,pi;
					n /= i;
					while(n %i == 0) si *= i, n /= i;
					pi = check(i);
					ans = lcm(ans,pi*si);
				}
			}
			if(n != 1) ans = lcm(ans,check(n));
		}
		printf("Case #%d: %I64d\n",ncase ++,ans);
	}
	return 0;
}
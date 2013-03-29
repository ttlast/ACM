#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
const int maxn = 35;
typedef long long LL;

LL gcd(LL x,LL y)
{
	if(y == 0) return x;
	return gcd(y,x%y);
}
LL fac[maxn];
int m,r[maxn];
int main()
{
	int i,j,k;
	LL tmp,d,ans,rows;
	while(scanf("%d",&m),m)
	{
		rows = 0;
		for(i = 1;i <= m;i ++)
		{
			scanf("%d",&r[i]);
			rows += r[i];
		}
		for(i = 1;i <= rows;i ++)
			fac[i] = i;
		for(i = 1;i <= m;i ++)
		{
			for(j = 1;j <= r[i];j ++)
			{
				tmp = r[i] - j + 1;
				for(k = i+1;k <= m;k ++)
				{
					if(r[k] >= j)
						tmp ++;
					else break;
				}
				if(tmp > 1)
				{
					for(k = 1;k <= rows;k ++)
					{
						d = gcd(tmp,fac[k]);
						tmp /= d;
						fac[k] /= d;
						if(tmp == 1) break;
					}
				}
			}
		}
		for(i = ans = 1;i <= rows;i ++)
			ans *= fac[i];
		printf("%I64d\n",ans);
	}
	return 0;
}
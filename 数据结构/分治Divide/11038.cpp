#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;

LL check(LL a,LL h,LL len)
{
	LL ret = 0,b;
	b = a/10;
	if(a%10== 0)
		ret = (b-1)*len + h+1;
	else
		ret = b*len;
	if(b >= 10)
		ret += check(b,h+(a%10)*len,len*10);
	return ret;
}
int main()
{
	LL m,n;
	LL ans;
	while(scanf("%lld%lld",&m,&n)!=EOF)
	{
		if(m < 0) break;
		ans = check(n,0,1) - check(m-1,0,1);
		if(m == 0) ans ++;
		printf("%lld\n",ans);
	}
	return 0;
}
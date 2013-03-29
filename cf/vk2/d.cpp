#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
typedef __int64 LL;
const int maxn = 41000;

char c[maxn];
LL dp[maxn],num[maxn];
int main()
{
	int i,j,cl,l,len,r;
	LL ans = 0;
	scanf("%s",c);
	cl = strlen(c);
	len = cl*2;
	for(i = 0;i < len;i ++)
	{
		l = i/2; r = (i+1)/2;
		while(l >= 0 && r < cl && c[l] == c[r])
		{
			dp[r] ++;
			num[l] ++;
			l --;r ++;
		}
	}
	for(i = cl-2;i >= 0;i --)
		num[i] += num[i+1];

	for(i = 1;i < cl;i ++)
		ans += dp[i-1]*num[i];
	printf("%I64d\n",ans);
	return 0;
}
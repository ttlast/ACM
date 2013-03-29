#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned long long LL;
const int maxn = 1000005;

LL a[maxn];
int main()
{
	int t,i,n,k;
	LL ans,t1,t2;
	scanf("%d",&t);
	while(t --){

		scanf("%d",&n);
		ans = 0;
		for(i = 0;i < n;i ++)
		{
			scanf("%I64u",&a[i]);
			ans ^= a[i];
		}
		k = t1 = t2 = 0;
		while(!(ans&1)){
			ans >>= 1;
			k ++;
		}
		for(i = 0;i < n;i ++)
		{
			if((a[i]>>k)&1) t1 ^= a[i];
			else t2 ^= a[i];
		}
		if(t1 > t2) swap(t1,t2);
		printf("%I64u %I64u\n",t1,t2);
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef __int64 LL;
int main()
{
	int i,n;
	int ans1,ans2,tmp;
	long long int ans,tm;
	scanf("%d",&n);
	ans1 = ans2 = ans = 0;
	for(i = 0;i < n;i ++)
	{
		scanf("%d",&tmp);
		if(tmp > ans1) {ans2 = ans1;ans1 = tmp;}
		else if(tmp > ans2) ans2 = tmp;
	}
	ans = (LL) ans1*(n-1);
	tm = ans1+ans2;
	tm = (LL)tm*(n-2);
	if(ans < tm) ans = tm;
	printf("%I64d\n",ans);
	return 0;
}
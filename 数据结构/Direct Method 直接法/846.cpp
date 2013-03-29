#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
using namespace std;
typedef long long LL;


int main()
{
	LL a,b,ans,step,dis,l;
	int t;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%lld%lld",&a,&b);
		dis = b-a;
		if(dis == 0) printf("0\n");
		else if(dis == 1) printf("1\n");
		else if(dis == 2) printf("2\n");
		else{
			ans = 0;
			step = 1;
			int flag = 0;
			while(dis > 0)
			{
				dis -= step;
				ans ++;
				if(flag) step ++;
				flag ^= 1;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
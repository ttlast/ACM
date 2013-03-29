#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;
typedef long long LL;

int a,b,c,d;
int main()
{
	int ans;
	while(scanf("%d%d%d%d",&a,&b,&c,&d),a|b|c|d)
	{
		ans = 1080;
		//ans += a*9;
	
		ans += ((a-b+40)%40)*9; //Ë³Ê±Õë
		
		ans += ((c-b+40)%40)*9; //ÄæÊ±Õë
		
		ans += ((c-d+40)%40)*9; //Ë³Ê±Õë

		printf("%d\n",ans);
	}
	return 0;
}
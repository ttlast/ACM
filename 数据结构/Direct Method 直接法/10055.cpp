#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
typedef long long LL;
#define __abs(x) (x) > 0 ? (x):(-(x))
LL a,b;
int main()
{
	while(scanf("%lld%lld",&a,&b)!=EOF)
	{
		printf("%lld\n",__abs(b-a));
	}
	return 0;
}
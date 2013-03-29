#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <cstring>
using namespace std;

int main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d%d",&n,&m);
		if(n <= m) printf("first\n");
		else if(n%(m+1) == 0) printf("second\n");
		else printf("first\n");
	}
	return 0;
}
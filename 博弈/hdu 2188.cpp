#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <cstring>
using namespace std;

int main()
{
	int n,m,t;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d%d",&n,&m);
		if(n%(m+1) == 0) printf("Rabbit\n");
		else printf("Grass\n");
	}
	return 0;
}
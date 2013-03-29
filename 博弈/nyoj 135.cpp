#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <cstring>
using namespace std;

//Sprague-Grundy ∂®¿Ì
int main()
{
	int t,i,n,a,b,ans;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d",&n);
		ans = 0;
		for(i = 0;i < n;i ++)
		{
			scanf("%d%d",&a,&b);
			ans ^= a%(b+1);
		}
		if(ans) printf("Win\n");
		else printf("Lose\n");
	}
	return 0;
}
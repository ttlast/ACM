#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	int t,a,f;
	int i,j,k;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d%d",&a,&f);
		for(i = 0;i < f;i ++)
		{
			if(i) printf("\n");
			for(j = 1;j <= a;j ++)
			{
				for(k = 1;k <= j;k ++)
				{
					printf("%d",j);
				}
				printf("\n");
			}
			for(j = a-1;j >= 1;j --)
			{
				for(k = 1;k <= j;k ++)
				{
					printf("%d",j);
				}
				printf("\n");
			}
		}
		if(t) printf("\n");
	}
	return 0;
}
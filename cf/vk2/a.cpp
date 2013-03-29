#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 1005;

char a[maxn][22],b[maxn][22];
int t[maxn],n,d,peny[maxn],pl;
int main()
{
	int i,j,k;
	scanf("%d%d",&n,&d);
	for(i = 0;i < n;i ++)
	{
		scanf("%s%s%d",a[i],b[i],&t[i]);
	}
	pl = 0;
	for(i = 0;i < n;i ++)
	{
		for(k = 0;k < pl;k ++)
		{
			if(strcmp(a[i],a[peny[k]]) == 0 && strcmp(b[i],b[peny[k]]) == 0)
				break;
			if(strcmp(a[i],b[peny[k]]) == 0 && strcmp(b[i],a[peny[k]]) == 0)
				break;
		}
		if(k < pl) continue;
		for(j = i+1;j < n;j ++)
		{
			if(t[j] - t[i] > d) break;
			if(t[j] - t[i] == 0) continue;
			if(strcmp(a[i],b[j]) == 0 && strcmp(b[i],a[j]) == 0)
			{
				peny[pl++] = i;
				break;
			}
		}
	}
	printf("%d\n",pl);
	for(i = 0;i < pl;i ++)
	{
		printf("%s %s\n",a[peny[i]],b[peny[i]]);
	}
	return 0;
}
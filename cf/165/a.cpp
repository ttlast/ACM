#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 205;

int x[maxn],y[maxn],n;
int main()
{
	int n,i,j,ans;
	bool right,left,lower,upper;
	scanf("%d",&n);
	for(i = 0;i < n;i ++)
		scanf("%d%d",&x[i],&y[i]);
	ans = 0;
	for(i = 0;i < n;i ++)
	{
		right = left = lower = upper = false;
		for(j = 0;j < n;j ++)
		{
			if(i == j) continue;
			if(y[i] == y[j] && x[i] < x[j]) right = true;
			if(y[i] == y[j] && x[i] > x[j]) left = true;
			if(x[i] == x[j] && y[i] < y[j]) upper = true;
			if(x[i] == x[j] && y[i] > y[j]) lower = true;
		}
		if(right && left && upper && lower) ans ++;
	}
	printf("%d\n",ans);
	return 0;
}
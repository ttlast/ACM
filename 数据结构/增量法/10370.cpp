#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
const int maxn = 1005;

int n,a[maxn];
int main()
{
	int t,ans,i;
	double sum;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d",&n);
		sum = 0;
		for(i = 0;i < n;i ++)
		{
			scanf("%d",&a[i]);
			sum += a[i];
		}
		sum /= n;
		for(i = 0,ans = 0;i < n;i ++)
			if(a[i] > sum)
				ans ++;
		printf("%.3f%\n",ans*100.0/n);
	}
	return 0;
}
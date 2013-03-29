#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
const int maxn = 1005;

char c[maxn];
int cc[maxn],xx;

int chuli(int & s)
{
	int ans = 0,sign;
	if(c[s] == '-')
		sign = -1,s ++;
	else sign = 1;

	while(c[s] >= '0' && c[s] <= '9')
	{
		ans = ans*10 + c[s] - '0';
		s ++;
	}
	return ans*sign;
}
int main()
{
	int ans;
	int n,i,l,j,ss;
	while(gets(c))
	{
		n = 0;
		l = strlen(c);
		for(i = 0;i < l;i ++)
		{
			cc[n++] = chuli(i);
		}
		gets(c);
		l = strlen(c);
		ss = 0;
		for(i = 0;i < l;i ++)
		{
			xx = chuli(i);
			ans = 0;
			for(j = 0;j < n;j ++)
			{
				ans = ans*xx + cc[j];
			}
			if(ss) printf(" ");
			printf("%d",ans);
			ss = 1;
		}
		printf("\n");
	}
	return 0;
}
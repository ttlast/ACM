#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
const int maxn = 1000500;

char c[maxn],* ptr;
int cc[maxn],xx,n;

int main()
{
	int x,i,l,ans;
	while(gets(c))
	{
		sscanf(c,"%d",&x);
		gets(c);
		l = strlen(c);
		for(n = 0,ptr = strtok(c," \t\n");ptr;)
		{
			sscanf(ptr,"%d",&cc[n]);
			n ++;
			ptr = strtok(NULL, " \t\n");
		}
		n --;
		for(i = 0;i < n;i ++)
		{
			cc[i] *= (n-i);
		}
		for(i = ans = 0;i < n;i ++)
		{
			ans = ans*x + cc[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
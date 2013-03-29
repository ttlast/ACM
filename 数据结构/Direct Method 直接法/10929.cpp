#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
const int maxn = 1050;

void __strrev(char *c)
{
	int i,l,tm;
	for(i = 0,l = strlen(c)-1;i < l;i ++,l --)
	{
		tm = c[i]; c[i] = c[l];c[l] = tm;
	}
}
char c[maxn];
int main()
{
	int ans,i,len;
	while(gets(c))
	{
		__strrev(c);
		len = strlen(c);
		if(len == 1 && c[0] == '0') break;
		for(i = ans = 0;i < len;i += 2)
		{
			ans += c[i] - '0';
		}
		for(i = 1;i < len;i += 2)
		{
			ans -= c[i] - '0';
		}
		__strrev(c);
		if(ans%11 == 0)
		{
			printf("%s is a multiple of 11.\n",c);
		}else printf("%s is not a multiple of 11.\n",c);
	}
	return 0;
}
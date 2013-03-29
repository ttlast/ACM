#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
const int maxn = 40;

char c[maxn];
int main()
{
	int num,i,len;
	freopen("1.txt","w",stdout);
	gets(c);
	while(gets(c))
	{
		if(c[0] == '_') break;
		for(i = num = 0;c[i] != '\0';i ++)
		{
			if(c[i] == 'o')
				num = (num<<1) + 1;
			else if(c[i] == ' ')
				num = num<<1;
		}
		printf("%c",num);
	}
	
	return 0;
}
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1005;
char c[] = "~1234567890-=qwertyuiop[]\\asdfghjkl;\'zxcvbnm,./";
char str[maxn];
map<char,int> mm;

int main()
{
	int s = 0,i,len;
	len = strlen(c);
	for(i = len-1;i >= 2;i --)
		mm[c[i]] = c[i-2];
	while(scanf("%s",str)!=EOF)
	{
		if(s) printf(" ");
		s ++;
		len = strlen(str);
		for(i = 0;i < len;i ++)
		{
			if(str[i] >= 'A' && str[i] <= 'Z')
				str[i] = 'a' + str[i] - 'A';
			str[i] = mm[str[i]];
		}
		printf("%s",str);
	}
	printf("\n");
	return 0;
}
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

char c[] = {'`','1','2','3','4','5','6','7','8','9','0','-','=','Q','W','E','R','T','Y','U','I','O','P','[',']','\\',
		'A','S','D','F','G','H','J','K','L',';','\'',
		'Z','X','C','V','B','N','M',',','.','/'};
map<char,char> mm;
char str[1005];
int main()
{
	int i,len;
	for(i = 1;c[i] != '/';i ++)
	{
		mm[c[i]] = c[i-1];
	}
	mm[c[i]] = c[i-1];
	while(gets(str))
	{
		len = strlen(str);
		for(i = 0;i < len;i ++)
		{
			if(str[i] == ' ' || str[i] == '/t')
				continue;
			str[i] = mm[str[i]];
		}
		puts(str);
	}
	return 0;
}
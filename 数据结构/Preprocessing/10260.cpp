#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

map<char,int> mm;
char str[50];
int main()
{
	int i,len;
	mm['B'] = mm['F'] = mm['P'] = mm['V'] = 1;
	mm['C'] = mm['G'] = mm['J'] = mm['K'] = mm['Q'] = mm['S'] = mm['X'] = mm['Z'] = 2;
	mm['D'] = mm['T'] = 3;
	mm['L'] = 4;
	mm['M'] = mm['N'] = 5;
	mm['R'] = 6;
	while(gets(str))
	{
		len = strlen(str);
		for(i = 0;i < len;i ++)
		{
			if(mm[str[i]] != 0)
			{
				if(i > 0 && mm[str[i]] == mm[str[i-1]])
					continue;
				printf("%d",mm[str[i]]);
			}
		}
		printf("\n");
	}
	return 0;
}
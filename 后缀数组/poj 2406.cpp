#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1000200;
char c[maxn];
int next[maxn],len;
void getnext()
{
	next[0] = -1;
	if(c[1] == c[0]) next[1] = -1;
	else next[1] = 0;
	int i,j = 0;
	for(i = 1;c[i] != '\0';)
	{
		if(j < 0 || c[i] == c[j])
		{
			i ++;j ++;
			next[i] = j;
		}else j = next[j];
	}
	len = i;
}
int main()
{
	int tmp,x,y;
	while(gets(c))
	{
		if(c[0] == '.') break;
		getnext();
		x = len;
		while(next[x] != -1)
		{
			tmp = len - next[x];
			if(len%tmp == 0)
			{
				printf("%d\n",len/tmp);
				break;
			}
			x = next[x];
		}
		if(next[x] == -1) printf("1\n");
	}
	return 0;
}
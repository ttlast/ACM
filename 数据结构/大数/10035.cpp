#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 30;

void __strrev(char *c)
{
	int i,l;
	char tmp;
	for(i = 0,l = strlen(c)-1;i < l;i ++,l --)
	{
		tmp = c[i];
		c[i] = c[l];
		c[l] = tmp;
	}
}
int main()
{
	int i,j,ans,al,bl,t;
	char a[maxn],b[maxn];
	while(scanf("%s%s",a,b)!=EOF)
	{
		if(a[0] == '0' && b[0] == '0') break;
		__strrev(a);
		__strrev(b);
		al = strlen(a);
		bl = strlen(b);
		i = j = t = ans = 0;
		while(1)
		{
			if(i >= al && j >= bl) break;
			if(i < al)
			{
				t += a[i] - '0';
				i ++;
			}
			if(j < bl)
			{
				t += b[j] - '0';
				j ++;
			}
			if(t >= 10) ans ++;
			t /= 10;
		}
		if(ans > 1) printf("%d carry operations.\n",ans);
		else if(ans == 1) printf("%d carry operation.\n",ans);
		else printf("No carry operation.\n");
	}
	return 0;
}
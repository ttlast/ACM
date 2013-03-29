#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
const int maxn = 1050;

char a[maxn],b[maxn];
int al,bl;
int numa[maxn],numb[maxn],ans[maxn],ansl;

void __strrev(char *c)
{
	char tmp;
	int i,l;
	for(i = 0,l = strlen(c)-1;i < l;i ++,l --)
	{
		tmp = c[i];
		c[i] = c[l];
		c[l] = tmp;
	}
}
int main()
{
	int i,j,tm;
	while(scanf("%s%s",a,b)!=EOF)
	{
		al = strlen(a);
		bl = strlen(b);
		for(i = 0,j = al-1;j >= 0;j --,i ++)
			numa[i] = a[j]-'0';
		for(i = 0,j = bl-1;j >= 0;j --,i ++)
			numb[i] = b[j]-'0';
		for(i = 0,ansl = 0;i < maxn;i ++)
			ans[i] = 0;
		for(i = 0;i < al;i ++)
		{
			tm = 0;
			for(j = 0;j < bl;j ++)
			{
				tm += numa[i]*numb[j];
				tm += ans[i+j];
				ans[i+j] = tm%10;
				tm /= 10;
			}
			while(tm > 0)
			{
				tm += ans[i+j];
				ans[i+j] = tm%10;
				tm /= 10;
				j ++;
			}
			ansl = i+j;
		}
		for(j = ansl-1;j > 0;)
			if(ans[j] == 0) j --;
			else break;
		for(i = j;i >= 0;i --)
				printf("%d",ans[i]);
		printf("\n");
	}
	return 0;
}

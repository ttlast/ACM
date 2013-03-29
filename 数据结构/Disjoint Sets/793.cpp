#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
const int maxn = 10000;

int fa[maxn];
char c[105],cm[5];

int findfa(int x)
{
	if(x != fa[x]) fa[x] = findfa(fa[x]);
	return fa[x];
}

void unit(int x,int y)
{
	x = findfa(x);
	y = findfa(y);
	if(x == y)
		return ;
	if(x < y)
		fa[y] = x;
	else
		fa[x] = y;
}
int main()
{
	int t,i,j,a,b,n;
	int unset,uset;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d",&n);
		gets(c);
		unset = uset = 0;
		for(i = 1;i <= n;i ++)
			fa[i] = i;
		while(gets(c))
		{
			if(c[0] == '\0') break;
			sscanf(c,"%s%d%d",cm,&a,&b);
			if(cm[0] == 'q')
			{
				if(findfa(a) != findfa(b))
					unset ++;
				else 
					uset ++;
			}else if(cm[0] == 'c')
			{
				unit(a,b);
			}
		}
		printf("%d,%d\n",uset,unset);
		if(t) printf("\n");
	}
	return 0;
}
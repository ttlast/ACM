#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
const int maxn = 1050;

int a[maxn],b[maxn],al,bl;
char c1[maxn],c2[maxn];

void chuli(int *a,char *c,int & len)
{
	len = 0;
	int l = strlen(c),i;
	for(i = 0;i < l;i ++)
	{
		while(c[i] == ' ') i ++;
		a[len] = 0;
		while(c[i] != ' '&&c[i] != '\0')
			a[len] = a[len]*10 + c[i++]-'0';
		len ++;
	}
}

int main()
{
	bool s,q;
	int i,j;
	while(gets(c1))
	{

		chuli(a,c1,al);
		s = false;
		q = true;
		gets(c2);

		chuli(b,c2,bl);
		
		if(al == bl)
		{
			for(i = 0;i < al;i ++)
			{
				for(j = 0;j < bl;j ++)
					if(a[i] == b[j]) break;
				if(j >= bl) q = false;
				if(j < bl) s = true;
			}
			if(q) printf("A equals B\n");
			else if(s) printf("I'm confused!\n");
			else printf("A and B are disjoint\n");
		}else if(al > bl)
		{
			for(i = 0;i < bl;i ++)
			{
				for(j = 0;j < al;j ++)
					if(b[i] == a[j]) break;
				if(j >= al) q = false;
				if(j < bl) s = true;
			}
			if(q) printf("B is a proper subset of A\n");
			else if(s) printf("I'm confused!\n");
			else printf("A and B are disjoint\n");
		}else if(al < bl)
		{
			for(i = 0;i < al;i ++)
			{
				for(j = 0;j < bl;j ++)
					if(a[i] == b[j]) break;
				if(j >= bl) q = false;
				if(j < bl) s = true;
			}
			if(q) printf("A is a proper subset of B\n");
			else if(s) printf("I'm confused!\n");
			else printf("A and B are disjoint\n");
		}
	}
	return 0;
}

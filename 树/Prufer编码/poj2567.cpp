#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000;

char c[maxn];
struct Node{
	int v,next;
};
Node mat[maxn];
int eda[55],len,n;
int du[55];

void addeda(int u,int v)
{
	if(u > n) n = u;
	if(v > n) n = v;
	du[u] ++;
	du[v] ++;
	mat[len].v = v;
	mat[len].next = eda[u];
	eda[u] = len ++;
	swap(u,v);
	mat[len].v = v;
	mat[len].next = eda[u];
	eda[u] = len ++;
}

int buildtree(int & l,int len)
{
	int num,i,tmp;
	num = 0;
	for(i = l+1;;i ++)
		if(c[i] >= '0' && c[i] <= '9')
			num = num*10 + c[i] - '0';
		else break;
	l = i;
	while(l < len)
	{
		if(c[l] == ' ')
		{
			l ++;
			tmp = buildtree(l,len);
			addeda(num,tmp);
		}else if(c[l] == ')')
		{
			l ++;
			return num;
		}
	}
	return num;
}
int main()
{
	int i,j,slen,s,k;
	while(gets(c))
	{
		for(i = 0;i <= 50;i ++)
		{
			eda[i] = -1;
			du[i] = 0;
		}
		n = 0;
		slen = strlen(c);
		s = 0;
		len = 0;
		buildtree(s,slen-1);
		s = 0;
		for(j = 2;j <= n;j ++)
		{
			for(j = 1;j <= n;j ++)
				if(du[j] == 1)
				{
					for(k = eda[j];k != -1;k = mat[k].next)
					{
						if(du[mat[k].v] != 0)
						{
							if(s) printf(" %d",mat[k].v);
							else printf("%d",mat[k].v);
							s = 1;
							du[mat[k].v] --;
						}
					}
					du[j] = 0;
					break;
				}
		}
		printf("\n");
	}
	return 0;
}
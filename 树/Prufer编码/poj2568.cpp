#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000;

struct Node{
	int v,next;
};
Node mat[maxn];
int eda[maxn],len,n,s;
char c[maxn];
int du[maxn];
int num[maxn];
void add(int u,int v)
{
	mat[len].v = v;
	mat[len].next = eda[u];
	eda[u] = len ++;
	swap(u,v);
	mat[len].v = v;
	mat[len].next = eda[u];
	eda[u] = len ++;
}
void dfs(int u,int fa)
{
	printf("(%d",u);
	int i,j,v;
	for(i = eda[u];i != -1;i = mat[i].next)
	{
		v = mat[i].v;
		if(v == fa) continue;
		printf(" ");
		dfs(v,u);
	}
	printf(")");
}
int main()
{
	int i,j,l,u;
	while(gets(c))
	{
		for(i = 0;i <= 50;i ++)
		{
			num[i] = du[i] = 0;
			eda[i] = -1;
		}
		l = strlen(c);
		s = 0;
		for(i = 0;i < l;i ++)
		{
			if(c[i] >= '0' && c[i] <= '9')
				num[s] = num[s]*10 + c[i] - '0';
			else
			{
				du[num[s]] ++;
				s ++;
			}
		}
		du[num[s]] ++;
		n = s + 2;
		if(c[0] == '\0') n = 1;
		for(i = 1;i <= n;i ++)
			du[i] ++;
		len = 0;
		for(i = 2;i <= n;i ++)
		{
			u = num[i-2];
			for(j = 1;j <= n;j ++)
			{
				if(du[j] == 1) break;
			}
			add(u,j);
			du[u] --;
			du[j] --;
		}
		dfs(1,-1);
		printf("\n");
	}
	return 0;
}
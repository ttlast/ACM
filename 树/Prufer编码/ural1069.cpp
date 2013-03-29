#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10000;

struct Node{
	int v,next;
};
struct CNode{
	int du,v;
};

bool operator < ( const CNode & t1, const CNode & t2)
{
	if(t1.du != t2.du) return t1.du > t2.du;
	return t1.v > t2.v;
}

Node mat[maxn*2];
int len,eda[maxn];
void addeda(int u,int v)
{
	mat[len].v = v;
	mat[len].next = eda[u];
	eda[u] = len ++;
	swap(u,v);
	mat[len].v = v;
	mat[len].next = eda[u];
	eda[u] = len ++;
}

int num[maxn],n;
int du[maxn] = {0};
int tm[maxn],tml;
void check()
{
	int i,j;
	CNode tmp;
	priority_queue<CNode> pq;
	for(i = 1;i <= n;i ++)
	{
		du[i] ++;
		if(du[i] == 1)
		{
			tmp.du = du[i];
			tmp.v = i;
			pq.push(tmp);
		}
	}
	for(i = 2;i <= n;i ++)
	{
		tmp = pq.top();
		pq.pop();
		addeda(num[i-2],tmp.v);
		du[num[i-2]] --;
		if(du[num[i-2]] == 1)
		{
			tmp.v = num[i-2];
			pq.push(tmp);
		}
	}
	for(i = 1;i <= n;i ++)
	{
		printf("%d:",i);
		tml = 0;
		for(j = eda[i];j != -1;j = mat[j].next)
			tm[tml++] = mat[j].v;
		sort(tm,tm+tml);
		for(j = 0;j < tml;j ++)
			printf(" %d",tm[j]);
		printf("\n");
	}
}
int main()
{
	int i,j;
	n = 0;
	while(scanf("%d",&num[n])!= EOF)
	{
		du[num[n]] ++;
		n ++;
	}
	len = 0;
	n ++;
	for(i = 1;i <= n;i ++) eda[i] = -1;
	check();
	return 0;
}
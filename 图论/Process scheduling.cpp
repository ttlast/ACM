#include <iostream>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef __int64 LL;
#define inf 1000000000
const int maxn = 50006;
const int maxe = 100008;
int n,m,num[3];
int mat[3][maxn],mat2[3][maxn];
struct Node{
	int d,id;
};
bool operator < (const Node &t1,const Node &t2)
{
	if(t1.d > t2.d) return true;
	return false;
}
bool check()
{
	int t,i,j;
	Node tm,tmp;
	priority_queue<Node> q[3];
	for(i = 0;i < n;i ++)
	{
		tm.id = i;
		tm.d = mat2[0][i];
		q[0].push(tm);
	}
	while(1)
	{
		t = 0;
		while(!q[0].empty())
		{
			tm = q[0].top();
			if(tm.d > num[0]) break;
			tmp.id = tm.id;tmp.d = mat2[1][tm.id];
			q[1].push(tmp);q[0].pop();
		}
		while(!q[1].empty())
		{
			tm = q[1].top();
			if(tm.d > num[1]) break;
			tmp.id = tm.id;tmp.d = mat2[2][tm.id];
			q[2].push(tmp);q[1].pop();
		}
		while(!q[2].empty())
		{
			tm = q[2].top();
			if(tm.d > num[2]) break;
			q[2].pop();
			t ++;
			num[0] += mat[0][tm.id];
			num[1] += mat[1][tm.id];
			num[2] += mat[2][tm.id];
		}
		if(q[0].empty() && q[1].empty() && q[2].empty()) break;
		if(t == 0) return false;
	}
	return true;
}
int main()
{
	int i,j;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i = 0;i < m;i ++)
			for(j = 0;j < n;j ++)
				scanf("%d",&mat[i][j]);
		for(i = 0;i < m;i ++)
			for(j = 0;j < n;j ++)
				scanf("%d",&mat2[i][j]);
		for(i = 0;i < m;i ++) scanf("%d",&num[i]);
		if(check()) puts("Yes");
		else puts("No");
	}
	return 0;
}
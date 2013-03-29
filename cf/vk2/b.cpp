#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
#define _min(x,y) (x) > (y) ? (y) : (x) 
const int maxn = 1004;
int n,m;

int marker[maxn][maxn],cap[maxn][maxn];
int cm[maxn],cc[maxn];
int main()
{
	int i,j,x,y,a,b,mx,my,u,v;
	scanf("%d%d",&n,&m);
	mx = my = 0;
	for(i = 0;i < n;i ++)
	{
		scanf("%d%d",&x,&y);
		mx = x > mx ? x : mx;
		my = y > my ? y : my;
		cm[y] ++;
		marker[x][y] ++;
	}
	for(i = 0;i < m;i ++)
	{
		scanf("%d%d",&a,&b);
		mx = a > mx ? a : mx;
		my = b > my ? b : my;
		cc[b] ++;
		cap[a][b] ++;
	}
	u = v = 0;
	for(i = 1;i <= my;i ++)
		u += _min(cm[i],cc[i]);
	for(i = 1;i <= mx;i ++)
		for(j = 1;j <= my;j ++)
		{
			v += _min(marker[i][j],cap[i][j]);
		}
	printf("%d %d\n",u,v);
	return 0;
}
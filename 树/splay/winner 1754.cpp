#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
const int maxn = 600006;
const int inf = 1000000000;
int n,m;
int num[maxn];
void build()
{
	int i,j;
	for(i = n-1;i >= 1;i --)
	{
		num[i] = max(num[i*2],num[i*2+1]);
	}
}
void change(int x,int y)
{
	int up,cur,l,r;
	cur = n + x - 1;
	num[cur] = y;
	while(cur > 1)
	{
		up = cur >> 1;
		l = up << 1;
		r = l + 1;
		if(num[l] > num[r]) num[up] = num[l];
		else num[up] = num[r];
		cur = up;
	}
}
int Query(int x,int y)
{
	x = n + x - 1;
	y = n + y - 1;
	int ans = num[x];
	while(x <= y)
	{
		if(num[x] > ans) ans = num[x];
		if(x & 1) x ++;
		if(num[y] > ans) ans = num[y];
		if((y&1) == 0) y --;
		x >>= 1;
		y >>= 1;
	}
	return ans;
}
int main()
{
	char c[5];
	int x,y,i,ans;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i = 0;i < n;i ++)
			scanf("%d",&num[n+i]);
		num[2*n] = - inf;
		build();
		for(i = 0;i < m;i ++)
		{
			scanf("%s%d%d",c,&x,&y);
			if(c[0] == 'Q')
			{
				if(x > y) swap(x,y);
				ans = Query(x,y);
				printf("%d\n",ans);
			}else if(c[0] == 'U')
			{
				change(x,y);
			}
		}
	}
	return 0;
}
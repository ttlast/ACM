#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
#define inf 1000000000;
typedef __int64 LL;
int n,m;

int main()
{
	LL step;
	int i,k,x,y,dx,dy,minx,miny;
	scanf("%d%d",&n,&m);
	scanf("%d%d",&x,&y);
	scanf("%d",&k);
	step = 0;
	for(i = 0;i < k;i ++)
	{
		scanf("%d%d",&dx,&dy);
		if(dx > 0)
		{
			if(dy > 0)
			{
				minx = (n-x)/dx;
				miny = (m-y)/dy;
				minx = min(minx,miny);
				step += minx;
				x += minx*dx;
				y += minx*dy;
			}else
			{
				minx = (n-x)/dx;
				if(dy != 0) miny = (1-y)/dy;
				else miny = inf;
				minx = min(minx,miny);
				step += minx;
				x += minx*dx;
				y += minx*dy;
			}
		}else
		{
			if(dy > 0)
			{
				if(dx != 0) minx = (1-x)/dx;
				else minx = inf;
				miny = (m-y)/dy;
				minx = min(minx,miny);
				step += minx;
				x += minx*dx;
				y += minx*dy;
			}else
			{
				if(dx != 0) minx = (1-x)/dx;
				else minx = inf;
				if(dy != 0) miny = (1-y)/dy;
				else miny = inf;
				minx = min(minx,miny);
				step += minx;
				x += minx*dx;
				y += minx*dy;
			}
		}
	}
	printf("%I64d\n",step);
	return 0;
}

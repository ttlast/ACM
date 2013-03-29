#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
const int maxn = 150;

struct Node{
	int x,y;
};
Node mat[maxn];
int n,len;

bool check(int a,int b)
{
	int i,tmp,s,x;
	s = x = 0;
	for(i = 0;i < len;i ++)
	{
		tmp = a*mat[i].x + b*mat[i].y ;
		if(tmp > 0) s ++;
		else if(tmp < 0) x ++;
		else break;
	}
	if(i < len) return false;
	if(s == x) return true;
	return false;
}
int main()
{
	int x,y,a,b,i;
	while(scanf("%d",&n),n)
	{
		for(i = len = 0;i < n;i ++)
		{
			scanf("%d%d",&mat[len].x,&mat[len].y);
			len ++;
			scanf("%d%d",&mat[len].x,&mat[len].y);
			len ++;
		}
		for(a = -500;a <= 500;a ++)
		{
			for(b = -500;b <= 500;b ++)
			{
				if(check(a,b)) break;
			}
			if(b <= 500) break;
		}
		printf("%d %d\n",a,b);
	}
	return 0;
}
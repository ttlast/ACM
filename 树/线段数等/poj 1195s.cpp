#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define lowbit(x) (x&(-x))
#define Max 1100

int Tree[Max][Max],s;

void Add_y(int rootx,int rooty,int a)
{
	while(rooty <= s)
	{
		Tree[rootx][rooty] += a;
		rooty += lowbit(rooty);
	}
}

void Add_x(int rootx,int rooty,int a)
{
	while(rootx <= s)
	{
		Add_y(rootx,rooty,a);
		rootx += lowbit(rootx);
	}
}

int Queue_y(int rootx,int rooty)
{
	int sum = 0;
	while(rooty > 0)
	{
		sum += Tree[rootx][rooty];
		rooty -= lowbit(rooty);
	}
	return sum;
}

int Queue_x(int rootx,int rooty)
{
	int sum = 0;
	while(rootx > 0)
	{
		sum += Queue_y(rootx,rooty);
		rootx -= lowbit(rootx);
	}
	return sum;
}
int Queue(int x1,int y1,int x2,int y2)
{
	return Queue_x(x2,y2) - Queue_x(x1-1,y2) + Queue_x(x1-1,y1-1) - Queue_x(x2,y1-1);
}

int main()
{
	int sign,x,y,a,x1,y1,x2,y2,sum;
	while(scanf("%d",&sign)!=EOF)
	{
		if(sign == 0)
		{
			scanf("%d",&s);
		}
		else if(sign == 1)
		{
			scanf("%d%d%d",&x,&y,&a);
			++ x; ++ y;
			Add_x(x,y,a);
		}
		else if(sign == 2)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			++ x1; ++ y1; ++ x2; ++ y2;
			sum = Queue(x1,y1,x2,y2);
			printf("%d\n",sum);
		}
		else break;
	}
	return 0;
}
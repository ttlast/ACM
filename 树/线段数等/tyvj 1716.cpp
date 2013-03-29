/*
X 4 4
L 1 1 3 3 2
L 2 2 4 4 1
k 2 2 3 3

12

delta[i][j]*(x-i+1)*(y-j+1)
= delta[i][j]*(x+1)*(y-j+1) - delta[i][j]*i*(y-j+1)
= delta[i][j]*(x+1)*(y+1) - delta[i][j]*j*(x+1) - delta[i][j]*i*(y+1) + delta[i][j]*i*j

*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define lowbit(x) (x&(-x))

#define Max 2100
int Tree[4][Max][Max];
int n,m;

void Add_y(int tr,int x,int y,int a)
{
	while(y <= m)
	{
		Tree[tr][x][y] += a;
		y += lowbit(y);
	}
}

void Add_x(int tr,int x,int y,int a)
{
	while(x <= n)
	{
		Add_y(tr,x,y,a);
		x += lowbit(x);
	}
}

void Updata(int x1,int y1,int x2,int y2,int a)
{
	Add_x(0,x1,y1,a);
	Add_x(0,x1,y2+1,-a);
	Add_x(0,x2+1,y2+1,a);
	Add_x(0,x2+1,y1,-a);

	Add_x(1,x1,y1,a*x1);
	Add_x(1,x1,y2+1,-a*x1);
	Add_x(1,x2+1,y2+1,a*(x2+1));
	Add_x(1,x2+1,y1,-a*(x2+1));

	Add_x(2,x1,y1,a*y1);
	Add_x(2,x1,y2+1,-a*(y2+1));
	Add_x(2,x2+1,y2+1,a*(y2+1));
	Add_x(2,x2+1,y1,-a*y1);

	Add_x(3,x1,y1,a*x1*y1);
	Add_x(3,x1,y2+1,-a*x1*(y2+1));
	Add_x(3,x2+1,y2+1,a*(x2+1)*(y2+1));
	Add_x(3,x2+1,y1,-a*(x2+1)*y1);
}

int Getsum_y(int tr,int x,int y)
{
	int sum = 0;
	while(y > 0)
	{
		sum += Tree[tr][x][y];
		y -= lowbit(y);
	}
	return sum;
}

int Getsum_x(int tr,int x,int y)
{
	int sum = 0;
	while(x > 0)
	{
		sum += Getsum_y(tr,x,y);
		x -= lowbit(x);
	}
	return sum;
}
int Getsum(int x,int y)
{
	int sum = 0;
	sum = (x+1)*(y+1)*Getsum_x(0,x,y) - (y+1)*Getsum_x(1,x,y) + Getsum_x(3,x,y) - (x+1)*Getsum_x(2,x,y);
	return sum;
}

int Queue(int x1,int y1,int x2,int y2)
{
	int sum = 0;
	int s1,s2,s3;
	sum = Getsum(x2,y2);
	s1 = Getsum(x1-1,y1-1);
	s2 = Getsum(x1-1,y2);
	s3 = Getsum(x2,y1-1);
	sum = sum - s2 + s1 - s3;
	return sum;
}

int main()
{
	char c[5];
	int x1,y1,x2,y2,a;
	scanf("%s%d%d",c,&n,&m);
	while(scanf("%s",c)!=EOF)
	{
		if(c[0] == 'L')
		{
			scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&a);
			Updata(x1,y1,x2,y2,a);
		}else{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			a = Queue(x1,y1,x2,y2);
			printf("%d\n",a);
		}
	}
	return 0;
}
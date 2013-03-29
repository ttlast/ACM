#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
const int maxn = 20;
#define esp 1e-8
typedef double LD;
struct Point{ LD x,y; };
LD xmult(Point p1,Point p2,Point p0){
	return (p1.x-p0.x)*(p2.y-p0.y) - (p1.y-p0.y)*(p2.x-p0.x);
}
LD xmult(Point p1,Point p2){ //(0,0)Ϊp0
	return p1.x*p2.y - p2.x*p1.y;
}
double dist(Point p1,Point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}
bool cross(Point p1,Point p2,Point p3,Point p4)
{
	if(xmult(p3,p2,p1)*xmult(p2,p4,p1) >= 0) return true;
	return false;
}
struct Wall
{
	double x,y[4];
}wall[maxn];
struct point
{
	double x,y,dis;int num;
};
double mindis = 1000000000.0;
int n;
void bfs()
{
	int i;
	double d;
	point s,e;
	Point p1,p2,p3,p4;
	queue<point> q;
	s.x = 0;s.y = 5;s.num = 0;s.dis = 0;
	p2.x = 10;p2.y = 5;
	q.push(s);
	while(!q.empty())
	{
		s = q.front();q.pop();
		p1.x = s.x;p1.y = s.y;
		for(i = s.num;i < n;i ++)
		{
			p3.x = wall[i].x;p3.y = 0;
			p4.x = wall[i].x;p4.y = wall[i].y[0];
			if(cross(p1,p2,p3,p4))
			{
				e.x = p4.x;e.y = p4.y;
				e.num = i+1;e.dis = s.dis + dist(p1,p4);
				q.push(e);
				e.y = wall[i].y[1];
				e.num = i+1;e.dis = s.dis + dist(p1,p4);
				q.push(e);
				break;
			}			
			p3.y = wall[i].y[1];
			p4.y = wall[i].y[2];
			if(cross(p1,p2,p3,p4))
			{
				e.x = p3.x;e.y = p3.y;
				e.num = i+1;e.dis = s.dis + dist(p1,p3);
				q.push(e);
				e.y = p4.y;
				e.num = i+1;e.dis = s.dis + dist(p1,p4);
				q.push(e);
				break;
			}
			p3.y = wall[i].y[3];
			p4.y = 10;
			if(cross(p1,p2,p3,p4))
			{
				e.x = p3.x;e.y = p3.y;
				e.num = i+1;e.dis = s.dis + dist(p1,p3);
				q.push(e);
				e.y = wall[i].y[2];
				e.num = i+1;e.dis = s.dis + dist(p1,p3);
				q.push(e);
				break;
			}

		}
		if(i >= n)
		{
			d = s.dis + dist(p1,p2);
			if(d < mindis) mindis = d;
		}
	}
}
int main()
{
	int i;
	while(scanf("%d",&n))
	{
		if(n < 0) break;
		mindis = 1000000000.0;
		for(i = 0;i < n;i ++)
		{
			scanf("%lf%lf%lf%lf%lf",&wall[i].x,&wall[i].y[0],&wall[i].y[1],&wall[i].y[2],&wall[i].y[3]);
		}
		bfs();
		printf("%.2lf\n",mindis);
	}
	return 0;
}

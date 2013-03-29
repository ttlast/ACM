#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;
#define MAXN  15
#define eps 1e-8
#define zero(x) (((x)>0?(x):(-x))<eps)
#define _sign(x) ((x)>eps?1:((x)<-eps?2:0)) //1 正 2 负 0 正 
typedef int LD;
struct Point{ LD x,y; };
struct point{ double x,y; };
struct Line{ Point a,b; };
LD xmult(Point p1,Point p2,Point p0){
	return (p1.x-p0.x)*(p2.y-p0.y) - (p1.y-p0.y)*(p2.x-p0.x);
}
LD xmult(Point p1,Point p2){ //(0,0)为p0
	return p1.x*p2.y - p2.x*p1.y;
}
bool isIntersected(Point s1,Point e1, Point s2,Point e2)
{
    return  (xmult(s1,s2,e1)*xmult(s1,e1,e2)>0) &&
            (xmult(s2,s1,e2)*xmult(s2,e2,e1)>0);
}
point intersection(Point u1,Point u2,Point v1,Point v2)
{
    point ret;ret.x = u1.x;ret.y = u1.y;
    double t=(double) ((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))
             /((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
    ret.x+=(u2.x-u1.x)*t;
    ret.y+=(u2.y-u1.y)*t;
    return ret;
}

Point p1,p2,p3,p4;
int n;
int main()
{
	int i,j,d1,d2;
	point t;
	while(scanf("%d",&n)!=EOF)
	{
		puts("INTERSECTING LINES OUTPUT");
		for(i = 0;i < n;i ++)
		{
			scanf("%d%d%d%d%d%d%d%d",&p1.x,&p1.y,&p2.x,&p2.y,
				&p3.x,&p3.y,&p4.x,&p4.y);
			d1 = (p2.y - p1.y)*(p4.x - p3.x);
			d2 = (p2.x - p1.x)*(p4.y - p3.y);
			if(d1 == d2&&xmult(p3,p4,p1) == 0)
			{
			    puts("LINE");
			}else
			{
			if(d1 != d2)
			{
				t = intersection(p1,p2,p3,p4);
				printf("POINT %.2lf %.2lf\n",t.x,t.y);
			}else  puts("NONE");
			}
		}
		puts("END OF OUTPUT");
	}
	return 0;
}

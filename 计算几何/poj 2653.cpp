#include <iostream>
using namespace std;
const int maxn = 100002;
typedef double DL;
struct point{
	DL x,y;
};
struct Line{
	point a,b;
};
DL xmult(point p1,point p2,point p0)
{
	return (p1.x - p0.x)*(p2.y - p0.y) - (p1.y - p0.y)*(p2.x - p0.x);
}
Line l[maxn];
bool cross(Line l1,Line l2)
{
	return (max(l1.a.x,l1.b.x) >= min(l2.a.x,l2.b.x))&&
		   (max(l1.a.y,l1.b.y) >= min(l2.a.y,l2.b.y))&&
		   (max(l2.a.x,l2.b.x) >= min(l1.a.x,l1.b.x))&&
		   (max(l2.a.y,l2.b.y) >= min(l1.a.y,l1.b.y))&&
		   (xmult(l2.a,l1.b,l1.a)*xmult(l1.b,l2.b,l1.a) > 0)&&
		   (xmult(l1.a,l2.b,l2.a)*xmult(l2.b,l1.b,l2.a) > 0);
}
bool sign[maxn];
int n;
int main()
{
	int i,j;
	bool t;
	while(scanf("%d",&n),n)
	{
		for(i = 0;i < n;i ++)
			scanf("%lf%lf%lf%lf",&l[i].a.x,&l[i].a.y,&l[i].b.x,&l[i].b.y);
		for(i = 0;i < n;i ++)
		{
			sign[i] = true;
			for(j = i+1;j < n;j ++)
			{
				if(cross(l[i],l[j]))
				{
					sign[i] = false;
					break;
				}
			}
		}
		printf("Top sticks: ");
		t = true;
		for(i = 0;i < n;i ++)
			if(sign[i])
			{
				if(t) printf("%d",i+1);
				else printf(", %d",i+1);
				t = false;
			}
		printf(".\n");
	}
	return 0;
}

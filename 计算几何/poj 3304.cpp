#include <iostream>
#include <cmath>
using namespace std;
#define eps 1e-10
const int maxn = 105;
struct Point
{
    double x,y;
};
struct Line
{
    Point p1,p2;
};
Line l[maxn];
int n;
double cross(Point p1,Point p2,Point p3)
{
    return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
};
double dis(Point p1,Point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
bool intersect(Point a,Point b)
{
     int i;
     if(dis(a,b)<eps) return false;
     for(i = 0;i < n;i ++)
        if(cross(a,b,l[i].p1)*cross(a,b,l[i].p2)>eps) return false;
     return true;
}
int main()
{
    int t,i,j;
    bool yes;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d",&n);
       for(i = 0;i < n;i ++)
       {
          scanf("%lf%lf%lf%lf",&l[i].p1.x,&l[i].p1.y,&l[i].p2.x,&l[i].p2.y);
       }
       yes = false;
       if(n <= 2) yes = true;
       for(i = 0; i < n;i ++)
       {
        for(j = i+1;j < n;j ++)
          if(intersect(l[i].p1,l[j].p1)||intersect(l[i].p1,l[j].p2)
           ||intersect(l[i].p2,l[j].p1)||intersect(l[i].p2,l[j].p2))
           {
                yes = true ; break;
           }
        if(yes) break;
        }
        if(yes) puts("Yes!");
        else puts("No!");
    }
    return 0;
}

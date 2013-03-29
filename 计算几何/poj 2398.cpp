#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1005;
struct Point
{
   double x,y;
   Point(double x1 = 0,double y1 = 0)
   {
      x = x1;y = y1;
   }
};
int n,m;
double x1,y1,x2,y2,x,y;
struct Line
{
   Point p1,p2;
   Line(){};
   Line(Point p3,Point p4)
   {
      p1 = p3;p2 = p4;
   }
};
Line line[maxn];
int ans[maxn],num[maxn];
bool check(int m)
{
     x2 = line[m].p2.x - x;
     y2 = line[m].p2.y - y;
     x1 = line[m].p1.x - x;
     y1 = line[m].p1.y - y;
     if(x2*y1 - x1*y2 >= 0) return true;
     return false;
}
void bsearch()
{
     int l,r,mid,ret;
     l = 0;r = n;
     while(l <= r)
     {
         mid = (l+r)>>1;
         if(check(mid))
         {
            ret = mid;
            l = mid+1;
         }else  r = mid-1;
     }
     ans[ret] ++;
}
bool comp(const Line l1,const Line l2)
{
     return l1.p1.x < l2.p1.x;
}
int main()
{
    int i,j;
    double u,l;
    Point p1,p2;
    while(scanf("%d%d%lf%lf%lf%lf",&n,&m,&x1,&y1,&x2,&y2)==6)
    {
       p1.x = x1,p1.y = y2;
       p2.x = x1,p2.y = y1;
       line[0] = Line(p1,p2);
       num[0] = ans[0] = 0;
       for(i = 1;i <= n;i ++)
       {
          scanf("%lf%lf",&u,&l);
          p1.x = l;p2.x = u;
          line[i] = Line(p1,p2);
          num[i] = ans[i] = 0;
       }
       sort(line,line+n+1,comp);
       for(i = 0;i < m;i ++)
       {
          scanf("%lf%lf",&x,&y);
          bsearch();
       }
       for(i = 0;i <= n;i ++)
       {
           num[ans[i]] ++;
       }
       printf("Box\n");
       for(i = 1;i <= n;i ++)
          if(num[i] != 0)
            printf("%d: %d\n",i,num[i]);
    }
    return 0;
}

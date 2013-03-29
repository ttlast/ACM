#include <iostream>
#include <cmath>
using namespace std;
const double eps = 1e-6;
struct Node
{
    int x,y;
};
Node a,b,c,d;
int vp,vq,vr;
double line(Node a,Node b)
{
     return sqrt(eps + (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));  //加个eps就ac了，什么原因呀。
}
double dis(double ax,double ay,double bx,double by)
{
     return sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by)); 
}
double cal(double u,double u2)
{
    double ret,x,y,x2,y2;
    ret = line(a,b);
    x = a.x + vp*u*(b.x-a.x)/ret;
    y = a.y + vp*u*(b.y-a.y)/ret;  
    ret = line(c,d);
    x2 = d.x + vq*u2*(c.x-d.x)/ret;
    y2 = d.y + vq*u2*(c.y-d.y)/ret;
    ret = u + u2 + dis(x,y,x2,y2)/vr;
    return ret;
}
double check(double u)
{
    double ret,t1,t2,l,r,lmid,lm;
    l = 0;r = line(c,d)/vq;
    while(r-l > eps)
    {
        lmid = (l+r)/2.0;
        lm = (r+lmid)/2.0;
        t1 = cal(u,lmid);
        t2 = cal(u,lm);
        if(t1 > t2)
        {
          ret = t1;
          l = lmid+eps;
        }else
        {
          ret = t2;
          r = lm-eps;
        }
    }
    return ret;
}
int main()
{
    int t;
    double l,r,lmid,lm,ans,t1,t2;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d%d%d%d",&a.x,&a.y,&b.x,&b.y);
       scanf("%d%d%d%d",&c.x,&c.y,&d.x,&d.y);
       scanf("%d%d%d",&vp,&vq,&vr);
       l = 0;r = line(a,b)/vp;
       while(r-l > eps)
       {
          lmid = (l+r)/2.0;
          lm = (r+lmid)/2.0;
          t1 = check(lmid);
          t2 = check(lm);
          if(t1 > t2)
          {
            ans = t1;
            l = lmid+eps;
          }else
          {
            ans = t2;
            r = lm-eps;
          }
       }
       printf("%.2lf\n",ans);
    }
    return 0;
}

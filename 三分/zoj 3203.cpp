#include <iostream>
using namespace std;
#define inf 0.00001
double  H,h,D;
double check(double x)
{
   double l = D*(h-x)/(H-x)+x;
   return l;
}
int main()
{
    int t;
    double l,r,lmid,rmid;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%lf%lf%lf",&H,&h,&D);
       l = 0;r = h;
       while(r-l>=inf)
       {
         lmid = (r+l)/2.0;
         rmid = (r+lmid)/2.0;
         if(check(lmid)>check(rmid))
         {
           r = rmid-inf;
         }else l = lmid+inf;
       }
       printf("%.3lf\n",check(l));
    }
    return 0;
}

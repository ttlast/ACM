//pick I(内点） +  E/2 (边点) - 1 = S(面积） 
#include <iostream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
using namespace std;
#define eps 1e-8
const int maxn = 105;
typedef double DL;
struct point{
	DL x,y;
};
DL xmult(point p1,point p2,point p0){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
bool comp(const point & p1,const point &p2){
     if(p1.y != p2.y) return p1.y < p2.y;
     return p1.x < p2.x;
}
point p[maxn];
double ans,I,E;
int len,n;
int gcd(int x,int y)
{
    if(y ==0) return x;
    return gcd(y,x%y);
}
int main()
{
    int t,ncase = 1,i;
    point tmp;
    DL x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        tmp.x = tmp.y = 0;
        for(i = 0;i < n;i ++)
        {
           scanf("%lf%lf",&x,&y);
           tmp.x += x;tmp.y += y;
           p[i] = tmp;
        }
        for(i = 1,E = 0;i < n;i ++){
              E += gcd((int)(fabs(p[i].x-p[i-1].x)+0.1),(int)(fabs(p[i].y-p[i-1].y)+0.1));
        }
        E += gcd((int)(fabs(p[n-1].x-p[0].x)+0.1),(int)(fabs(p[n-1].y-p[0].y)+0.1));
        n --;
        for(i = 1,ans = 0;i < n;i ++)
           ans += xmult(p[i],p[i+1],p[0]);
        if(ans < 0) ans = -ans;
        ans /= 2;
        I = ans - E/2.0 + 1;
        printf("Scenario #%d:\n",ncase++);
        printf("%.0f %.0f %.1f\n\n",I,E,ans);
    }
    return 0;
}

#include <iostream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
using namespace std;
#define eps 1e-8
const int maxn = 105;
typedef int DL;
struct point{
	DL x,y;
};
DL xmult(point p1,point p2,point p0){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
int gcd(int x,int y){
    if(y == 0) return x;
    return gcd(y,x%y);
}
point p[3];
int main()
{
    int i,ans,E,I;
    while(scanf("%d%d%d%d%d%d",&p[0].x,&p[0].y,&p[1].x,&p[1].y,&p[2].x,&p[2].y))
    {
        if(!(p[0].x||p[0].y||p[1].x||p[1].y||p[2].x||p[2].y)) break;
        ans = xmult(p[1],p[2],p[0]);
        if(ans < 0) ans = -ans;
        for(i = 0,E = 0;i < 2;i ++)
          E += gcd(abs(p[i].x-p[i+1].x),abs(p[i].y-p[i+1].y));
        E += gcd(abs(p[0].x-p[2].x),abs(p[0].y-p[2].y));
        I = ans/2 - E/2 + 1;
        printf("%d\n",I);
    }
    return 0;
}

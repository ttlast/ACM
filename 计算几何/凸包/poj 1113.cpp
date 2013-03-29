#include <iostream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const int maxn = 1005;
typedef int DL;
struct point{
	DL x,y;
};
DL xmult(point p1,point p2,point p0){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
double dist(point p1,point p2){
    return sqrt((double)(p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
point p[maxn],bag[maxn];
int n,l,len;
bool comp(const point & p1,const point &p2){
    if(p1.y != p2.y) return p1.y < p2.y;
    return p1.x < p2.x;
}
void grahamScan(point p[],int n,point bag[]){
    int i,j;
    sort(p,p+n,comp);
    bag[0] = p[0];len = 1;
    for(i = 1;i < n;i ++){
          while(len >= 2&&xmult(bag[len-2],bag[len-1],p[i])<= 0) len --;
          bag[len++] = p[i];
    }
    j = len+1;
    for(i = n-2;i >= 0;i --){
          while(len >= j&&xmult(bag[len-2],bag[len-1],p[i])<= 0) len --;
          bag[len++] = p[i];
    }
    len --;
}
int main()
{
    int i,j;double ans; //int wa, double ac
    while(scanf("%d%d",&n,&l)!=EOF)
    {
        for(i = 0;i < n;i ++)
        {
            scanf("%d%d",&p[i].x,&p[i].y); 
        }
        grahamScan(p,n,bag);
        ans = 0;
        for(i = 0;i < len;i ++)
          ans += dist(bag[i],bag[i+1]);
        ans += 2*l*acos(-1.0);
        printf("%.0lf\n",ans);        
    } 
    return 0;
}

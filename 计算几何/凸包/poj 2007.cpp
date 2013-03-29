#include <iostream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstdlib>
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
bool comp(const point & p1,const point &p2){
     if(p1.y != p2.y) return p1.y < p2.y;
     return p1.x < p2.x;
}
point p[maxn];
bool comp2(const point &p1,const point &p2){
     return xmult(p1,p2,p[0]) > 0;
}
int n;
int main()
{
    int i,j;
    n = 0;
    while(scanf("%d%d",&p[n].x,&p[n].y)!=EOF) n++;
    sort(p,p+n,comp);
    sort(p+1,p+n,comp2);
    for(i = 0;i < n;i ++) if(p[i].x == 0 && p[i].y == 0) break;
    for(j = 0;j < n;j ++,i ++)
        printf("(%d,%d)\n",p[i%n].x,p[i%n].y);
    system("pause");
    return 0;
}

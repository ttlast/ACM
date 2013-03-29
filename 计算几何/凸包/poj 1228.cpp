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
point p[maxn],bag[maxn];
int n,blen;
void make_bag(point p[],int n,point bag[])
{
     int i,j;
     sort(p,p+n,comp);
     bag[0] = p[0];blen = 1;
     for(i = 1;i < n;i ++){
          while(blen >= 2 && xmult(p[i],bag[blen-1],bag[blen-2]) >= 0) blen --;
          bag[blen++] = p[i];
     }
     j = blen+1;
     for(i = n-2;i >= 0;i --){
           while(blen >= j && xmult(p[i],bag[blen-1],bag[blen-2]) >= 0) blen --;
           bag[blen++] = p[i];
     }
     blen --;
}
int main()
{
    int i,j,t,num;
    //freopen("data.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i = 0;i < n;i ++) scanf("%d%d",&p[i].x,&p[i].y);
        make_bag(p,n,bag);
        if(blen < 3) puts("NO");
        else
        {
        for(i = 0;i < blen;i ++){
               num = 0;
               for(j = 0;j < n;j ++){
                  if(xmult(bag[i],bag[i+1],p[j]) == 0) num ++;
                  if(num >= 3) break;
               }
               if(num < 3) break;
        }
        if(i < blen) puts("NO");
        else puts("YES");
        } 
    }
    return 0;
}

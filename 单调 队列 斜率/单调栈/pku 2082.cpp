#include <iostream>
using namespace std;
const int maxn = 60000;
int stack[maxn],top,mv[maxn];
int main()
{
    int n,i,x,y,dw,ans,dy;
    while(scanf("%d",&n)!=EOF)
    {
       if(n < 0) break;
       top = ans = 0;
       scanf("%d%d",&x,&y);
       ans = x*y;
       stack[0] = y;mv[0] = x;
       for(i = 1;i < n;i ++)
       {
          dw = 0;
          scanf("%d%d",&x,&y);
          dy = stack[top];
          while(y < stack[top] && top >= 0)
          {
             dw += mv[top];
             dy = stack[top];
             if(dw*dy > ans) ans = dw*dy;
             top --;
          }
          x += dw;
          mv[++top] = x;
          stack[top] = y;
       }
       dw = dy = 0;
       while(top >= 0)
       {
         dw += mv[top];
         dy = stack[top];
         if(dw*dy > ans) ans = dw*dy;
         top --;
       }
       printf("%d\n",ans);
    }
    return 0;
}

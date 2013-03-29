#include <iostream>
using namespace std;
const int maxn = 100050;
int stack[maxn],mx[maxn];
int top;
int main()
{
    int n,i,j,h;
    __int64 dw,dy,ans;
    while(scanf("%d",&n)!=EOF)
    {
      if(n <= 0) break;
      top = 0;
      scanf("%d",&h);
      stack[0] = h;mx[0] = 1;
	  ans = h;
      for(i = 1;i < n;i ++)
      {
         dw = 0;
         scanf("%d",&h);
         while(stack[top] >= h && top >= 0)
         {
            dy = stack[top];
            dw += mx[top];
            if( dy*dw > ans) ans = dy*dw;
            top --;
         }
         stack[++top] = h;
         mx[top] = 1+dw;
      }
      dy = dw = 0;
      while(top >= 0)
      {
         dy = stack[top];
         dw += mx[top--];
         if(ans < dy*dw) ans = dy*dw;
      }
      printf("%I64d\n",ans);
    }
    return 0;
}

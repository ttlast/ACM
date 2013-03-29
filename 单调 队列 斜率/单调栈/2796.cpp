#include <iostream>
using namespace std;
const int maxn = 100060;
__int64 sum[maxn],ans;
int hpos[maxn],qpos[maxn],stack[maxn],top;
int main()
{
	bool sign;
    __int64 dw,dy;
    int n,i,j,h,num,l,r,tm,tm2;
    while(scanf("%d",&n)!=EOF)
    {
       scanf("%d",&num);
       ans = num;
       stack[0] = num;
       sum[0] = num;
       hpos[0] = qpos[0] = 1;
       top = 0;
       l = r = 1;
       for(i = 2;i <= n;i ++)
       {
          dw = 0;
		  sign = false;
          scanf("%d",&num);
          tm = hpos[top];
          while(num <= stack[top]&&top >= 0)
          {
			  sign = true;
              dw += sum[top];
              dy = stack[top];
			  tm2 = qpos[top];
              if(dw*dy > ans)
              {
                ans = dw*dy;
                r = tm;
                l = qpos[top];
              }
              top --;
          }
          stack[++top] = num;
		  if(sign) qpos[top] = tm2;
		  else qpos[top] = i;
          hpos[top] = i;
          sum[top] = dw + num;
       }
       dw = dy = 0;
       tm = hpos[top];
       while(top >= 0)
       {
          dw += sum[top];
          dy = stack[top];
          if(dw*dy > ans)
          {
             ans = dw*dy;
             r = tm;
             l = qpos[top];
          }
          top --;
       }
       printf("%I64d\n",ans);
       printf("%d %d\n",l,r);
    }
    return 0;
}

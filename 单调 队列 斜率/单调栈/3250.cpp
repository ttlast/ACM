#include <iostream>
using namespace std;
const int maxn = 81000;
int h[maxn],num[maxn],stack[maxn],top;
int main()
{
    int n,i,j,dw;
    __int64 ans;
    while(scanf("%d",&n)!=EOF)
    {
       top = -1;
       ans = 0;
       for(i = 0;i < n;i ++)
       {
         scanf("%d",&h[i]);
       }
       for(i = n-1;i >= 0;i --)
       {
          dw = 0;
          while(top >= 0 && stack[top] < h[i])
          {
              dw += num[top] + 1;
              ans += num[top];
              top --;
          }
          stack[++top] = h[i];
          num[top] = dw;
       }
	   while(top >= 0)
	   {
	     ans += num[top];
		 top --;
	   }
       printf("%I64d\n",ans);
    }
    return 0;
}

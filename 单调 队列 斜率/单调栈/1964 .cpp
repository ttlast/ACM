#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1200;
int k,m,n;
int h[maxn],stack[maxn],top,mv[maxn];
int main()
{
    int i,j,ans,dw;
    char c;
    scanf("%d",&k);
    while(k--)
    {
       scanf("%d%d",&n,&m);
       getchar();
       for(i = 0;i < m;i ++) h[i] = 0;
       ans = 0;
       for(i = 0;i < n;i ++)
       {
          top = -1;
          for(j = 0;j < m;j ++)
          {
              while(c = getchar(),c < 'A' || c > 'Z');
              if(c == 'F') h[j] ++;
              else h[j] = 0;
          }
          for(j = 0;j < m;j ++)
          {
              dw = 0;
              while(top >= 0 && stack[top] >= h[j])
              {
                 dw += mv[top];
                 if(dw * stack[top] > ans) ans = dw * stack[top];
                 top --;
              }
              stack[++top] = h[j];
              mv[top] = dw+1;
          }
          dw = 0;
          while(top >= 0)
          {
             dw += mv[top];
             if(dw * stack[top] > ans) ans = dw*stack[top];
             top --;
          }
       }
       printf("%d\n",ans*3);
    }
    return 0;
}

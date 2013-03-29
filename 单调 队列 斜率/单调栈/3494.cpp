#include <iostream>
using namespace std;
const int maxn = 2100;
int n,m;
int h[maxn],stack[maxn],mv[maxn],top;
int main()
{
    int i,j,ans,dw;
    char num;
    while(scanf("%d%d",&n,&m)!= EOF)
    {
        for(i = 0;i < m;i ++) h[i] = 0;
        ans = 0;
        for(i = 0;i < n;i ++)
        {
           for(j = 0;j < m;j ++)
           {
                while(num = getchar(),num < '0' || num > '9');
                if(num == '0') h[j] = 0;
                else h[j] ++;
           }
           top = -1;
           for(j = 0;j < m;j ++)
           {
               dw = 0;
               while(top >= 0 && stack[top] >= h[j])
               {
                  dw += mv[top];
                  if(dw*stack[top] > ans) ans = dw*stack[top];
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
        printf("%d\n",ans);
    }
    return 0;
}

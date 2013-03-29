#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 500006;
int stack[maxn],n,top;
int main()
{
    int i,j,u,r,l,m,best;
    __int64 tot;
    while(scanf("%d",&n)!=EOF)
    {
      scanf("%d",&u);
      stack[1] = u;
      tot = 0;
      top = 1;
      for(i = 1;i < n;i ++)
      {
         scanf("%d",&u);
         if(u < stack[top])
         {
           stack[++top] = u;
           tot ++;
         }else{
           best = l = 1;r = top;
           while(l <= r)
           {
              m = (l+r)>>1;
              if(stack[m] > u)
              {
			    best = m;
                l = m+1;
              }else r = m-1;
           }
           tot += top - best + 1;
		   while(l <= top && stack[l] >= u) l ++;
           top = l;
		   stack[top] = u;
         }
      }
      printf("%I64d\n",tot);
    }
    return 0;
}

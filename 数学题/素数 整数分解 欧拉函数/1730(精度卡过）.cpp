#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
    int i,p;
    long long x,s,s2;
    while(scanf("%lld",&x),x)
    {
         p = 1;
         if(x > 0)
         {
            for(i = 2;i < 33;i ++)
            {
               s = (long long)pow(x,1.0/i);
               if(s < 2) break;
               s2 = (long long)pow(s*1.0,i);
               if(s2 == x) p = i;
               else 
               {
                    s2 = (long long)pow(s+1.0,i);
                    if(s2 == x) p = i;
               }
            }
         }else
         {
             x = -x;
             for(i = 3;i < 32;i += 2)
             {
               s = (long long)pow(x,1.0/i);
               if(s < 2) break;
               s2 = (long long)pow(s*1.0,i*1.0);
               if(s2 == x) p = i;
               else 
               {
                    s2 = (long long)pow(s+1.0,i);
                    if(s2 == x) p = i;
               }
             }
         }
         printf("%d\n",p);
    }
    return 0;
}

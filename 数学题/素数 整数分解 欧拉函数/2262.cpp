#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxn = 1000005;
bool noprim[maxn] = {0};
int num[maxn],len;
void init()
{
     int i,j;
     len = 0;
     for(i = 2;i < maxn;i += 2) noprim[i] = true;
     for(i = 3;i < maxn;i += 2)
     {
          if(!noprim[i])
          {
              for(j = i*2;j < maxn;j += i) noprim[j] = true;
              num[len] = i;len ++;
          }
     }
}
int main()
{
    init();
    int x,i,j;
    while(scanf("%d",&x),x)
    {
       for(i = 0;i < len;i ++)
       {
          if(!noprim[x-num[i]]) break;
       }
       printf("%d = %d + %d\n",x,num[i],x-num[i]);
    }
    return 0;
}

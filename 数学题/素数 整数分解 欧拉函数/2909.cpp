#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxn = 32770;
bool noprim[maxn] = {0};
int num[maxn],len;
void init()
{
     int i,j;
     num[0] = 2;len = 1;
     noprim[0] = noprim[1] = true;
     for(i = 4;i < maxn;i += 2) noprim[i] = true;
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
    int x,i,j,s;
    while(scanf("%d",&x),x)
    {
       for(i = s = 0;i < len;i ++)
       {
          if(num[i] > x-num[i]) break;
          if(!noprim[x-num[i]]) s ++;
       }
       printf("%d\n",s);
    }
    return 0;
}

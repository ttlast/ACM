#include <iostream>
using namespace std;
const int maxn = 65540;
bool noprim[maxn] = {0};
int prim[8000],len;
void init()
{
     int i,j;
     prim[0] = 2;len = 1;
     for(i = 4;i < maxn;i += 2) noprim[i] = true;
     for(i = 3;i < maxn;i += 2)
     {
          if(!noprim[i])
          {
          for(j = i*2;j < maxn;j += i) noprim[j] = true;
          prim[len] = i;len ++;
          }
     }
}
int eular(int n)
{
    int ret = 1,i;
    for(i = 0;i < len;i ++)
    {
        if(n < prim[i]) break;
        if(n % prim[i] == 0)
        {
           n /= prim[i];ret = ret * (prim[i]-1);
           while(n%prim[i] == 0)
           {
              ret *= prim[i];
              n /= prim[i];
           }
        }
    }
    if(n != 1) ret *= (n-1);
    return ret;
}

int main()
{
    int n;
    init();
    while(scanf("%d",&n),n)
    {
        if(n == 1) puts("0");
        else
        {
        n = eular(n);
        printf("%d\n",n);
        }
    }
    return 0;
}

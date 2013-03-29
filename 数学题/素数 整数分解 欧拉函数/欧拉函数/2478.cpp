#include <iostream>
using namespace std;
typedef unsigned long long u64;
const int maxn = 1000001;
bool noprim[maxn] = {0};
u64 num[maxn];
void init()
{
     int i,j,t;
     num[1] = 0;
     for(i = 2;i < maxn;i ++) num[i] = 1;
     for(i = 4;i < maxn;i += 2)
     {
          noprim[i] = true;
          t = i/2;
          while(t%2 == 0)
          {
             num[i] *= 2;
             t /= 2;
          }
      }
     for(i = 3;i < maxn;i += 2)
     {
          if(!noprim[i])
          {
           for(j = i*2;j < maxn;j += i)
           {
                noprim[j] = true;
                t = j/i;num[j] *= (i-1);
                while(t%i == 0)
                {
                   t = t/i;num[j] *= i;
                }
           }
           num[i] = i-1;
          }
     }
     for(i = 3;i < maxn;i ++) num[i] += num[i-1];
}
int main()
{
    int n;
    init();
    while(scanf("%d",&n),n)
    {
       printf("%llu\n",num[n]);
    }
    return 0;
} 

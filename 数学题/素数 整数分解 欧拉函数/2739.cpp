#include <iostream>
using namespace std;
const int maxn = 15000;
bool noprim[maxn]= {0};
int num[maxn],len;
void init()
{
     int i,j;
     num[0] = 2;len = 1;
     for(i = 2;i < maxn;i += 2) noprim[i] = true;
     for(i = 3;i < maxn;i += 2)
        {
           if(!noprim[i])
           {
               for(j = i*i;j < maxn;j += i) noprim[j] = true;
               num[len] = i; len ++;
           }
          }
}
int main()
{
    int n,i,j,s,sl;
    init();
    while(scanf("%d",&n),n)
    {
       for(i = 0,sl = 0;num[i] <= n;i ++)
       {
           j = i;s = 0;
           while(s < n)
           {
              s += num[j];
              j ++;
           }
           if(s == n) sl ++;
       }
       printf("%d\n",sl);
    }
    return 0;
}

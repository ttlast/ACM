#include <iostream>
using namespace std;
const int maxn = 1299710;
bool noprim[maxn] = {0};
int num[100006],len;
void init()
{
     int i,j;
     num[0] = 2;len = 1;
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
void check(int n)
{
     int l,r,mid,best;
     l = 0;r = len-1;
     while(l <= r)
     {
        mid = (l+r)>>1;
        if(num[mid] >= n)
        {
           best = mid;
           r = mid-1;
        }else l = mid+1;
     }
     if(num[best] == n) puts("0");
     else printf("%d\n",num[best]-num[best-1]);
}
int main()
{
    init();
    int n;
    while(scanf("%d",&n),n)
    {
       check(n);
    }
    return 0;
}

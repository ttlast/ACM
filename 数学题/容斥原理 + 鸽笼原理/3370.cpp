#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int maxn = 100005;
int n,c;
int num[maxn],sum[maxn];
int sign[maxn] = {0};
int main()
{
    int i,j,pos;
    bool ok;
    while(scanf("%d%d",&c,&n),n)
    {
    memset(sign,0,sizeof(sign));
    ok = false;
    for(i = 1;i <= n;i ++)
    {
         scanf("%d",&num[i]);
         sum[i] = (sum[i-1]+num[i])%c;
         if(sum[i] == 0) {ok = true;pos = i;}
    }
    if(ok)
    {
      printf("%d",1); 
      for(i = 2;i <= pos;i ++)
           printf(" %d",i);
      printf("\n");
    }else
    {
      for(i = 1;i <= n;i ++)
         if(sign[sum[i]])
         {
           j = sign[sum[i]]+1;
           printf("%d",j);
           j ++;
           for(;j <= i;j ++)
             printf(" %d",j);
           printf("\n");
           break;
         }else sign[sum[i]] = i;
    }
    }
    return 0;
}

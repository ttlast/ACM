#include <iostream>
using namespace std;
const int maxn = 10005;
int n;
int num[maxn],sum[maxn];
int sign[maxn] = {0};
int main()
{
    int i,j,pos;
    bool ok;
    scanf("%d",&n);
    for(i = 1;i <= n;i ++)
    {
         scanf("%d",&num[i]);
         sum[i] = (sum[i-1]+num[i])%n;
         if(sum[i] == 0) {ok = true;pos = i;}
    }
    if(ok)
    {
      printf("%d\n",pos);
      for(i = 1;i <= pos;i ++) printf("%d\n",num[i]);
    }else
    {
      for(i = 1;i <= n;i ++)
         if(sign[sum[i]])
         {
           printf("%d\n",i-sign[sum[i]]);
           for(j = sign[sum[i]]+1;j <= i;j ++)
             printf("%d\n",num[j]);
         }else sign[sum[i]] = i;
    }
    return 0;
}

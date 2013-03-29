#include <iostream>
using namespace std;
const int maxn = 1005;
int v[maxn],v2[maxn],n,s;
int main()
{
    int i,j,t;
    while(scanf("%d%d",&n,&s)!=EOF)
    {
       for(i = 1;i <= n;i ++) scanf("%d",&v[i]);
       j = i = 1;
       v2[j] = 1;
       while(v[i] != 1)
       {
           v2[++j] = v[i];
           i = v[i];
       }
       t = 1;
       while(s > 0)
       {
          t = (t<<1)%n;
          s --;
       }
       v[1] = j = v2[1];
       for(i = 2;i <= n;i ++)
       {
          j += t;
          if(j > n) j -= n;
          v[j] = v2[i];
       }
       for(i = 1;i < n;i ++) v2[v[i]] = v[i+1];
       v2[v[n]] = v[1];
       for(i = 1;i <= n;i ++) printf("%d\n",v2[i]);
    }
    return 0;
}

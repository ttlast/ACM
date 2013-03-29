#include <iostream>
using namespace std;
const int maxn = 1000;
struct Node
{
    int u,v,d;
};
int num[maxn],n,m,em,dis[maxn];
Node eda[maxn*10];
void add(int u,int v,int d)
{
     eda[em].u = u;eda[em].v = v;
     eda[em++].d = d;
}
bool BellmanFord()
{
     int i,j;bool sign;
     for(i = 1;i <= n;i ++) dis[i] = 0;
     for(i = 1;i < n;i ++)
     {
        sign = true;
        for(j = 0;j < em;j ++)
          if(dis[eda[j].v] < dis[eda[j].u]+eda[j].d)
             dis[eda[j].v] = dis[eda[j].u] + eda[j].d,sign = false;
        if(sign) break;
     }
     for(j = 0;j < em;j ++)
        if(dis[eda[j].v] < dis[eda[j].u]+eda[j].d) return false;
     return true;
}
int main()
{
    int i,j,ncase = 0,a,b;
    char com[5];
    while(scanf("%d",&n),n)
    {
       for(i = 1;i <= n;i ++) scanf("%d",&num[i]);
       em = 0;
       while(scanf("%s",com))
       {
          if(com[0] == '#') break;
          scanf("%d%d",&a,&b);
          if(com[0] == 'S')
          {
              if(com[2] == 'S')
              {
                add(b,a,0);
              }else
              {
                add(b,a,num[b]);
              }
          }
          else
          {
              if(com[2] == 'S')
              {
                add(b,a,-num[a]);
              }else
              {
                add(b,a,num[b]-num[a]);
              }
          }
       }
       ncase ++;
       printf("Case %d:\n",ncase);
       if(BellmanFord())
       {
         for(i = 1;i <= n;i ++)
           printf("%d %d\n",i,dis[i]);
       }else puts("impossible");
       puts("");
    }
    return 0;
}

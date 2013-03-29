#include <iostream>
using namespace std;
const int maxn = 1000;
const int inf = 1000000000;
struct Node
{
   int u,v,d;
};
Node eda[maxn];
int em,n,m,dis[maxn];
void add(int u,int v,int d)
{
     eda[em].u = u;eda[em].v = v;
     eda[em++].d = d;
}
bool BellmanFord()
{
     int i,j;
     bool sign;
     for(i = 1;i <= n;i ++) dis[i] = inf;
     dis[0] = 0;
     for(i = 0;i < n;i ++)
     {
        sign = true;
        for(j = 0;j < em;j ++)
           if(dis[eda[j].v] > dis[eda[j].u]+eda[j].d) 
             dis[eda[j].v] = dis[eda[j].u]+eda[j].d,sign = false;
        if(sign) break;
     }
     for(j = 0;j < em;j ++)
           if(dis[eda[j].v] > dis[eda[j].u]+eda[j].d)  return false;
     return true;
}
int main()
{
    int a,b,c,i;
    char cor[10];
    while(scanf("%d",&n),n)
    {
       scanf("%d",&m);
       for(i = em = 0;i < m;i ++)
       {
         scanf("%d%d%s%d",&a,&b,cor,&c);
         b ++;
         if(cor[0] == 'g')
         {
           add(a+b,a,-c-1);
         }else  add(a,a+b,c-1);
       } 
       if(BellmanFord()) puts("lamentable kingdom");
         else puts("successful conspiracy");
    }
    return 0;
}

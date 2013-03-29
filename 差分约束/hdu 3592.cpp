#include <iostream>
using namespace std;
const int maxn = 40000;
const int inf = 1000000000;
struct Node
{
    int u,v,d;
    Node *next;
};
Node mat[maxn];
Node *eda[1005];
int n,em,dis[1005];
void add(int u,int v,int d)
{
     mat[em].u = u;
     mat[em].v = v;mat[em].d = d;
     mat[em].next = eda[u];
     eda[u] = &mat[em++];
}
bool BellmanFord()
{
     int i,j;
     for(i = 1;i <= n;i ++) dis[i] = inf;
     dis[1] = 0;
     bool sign;
     for(i = 1;i < n;i ++)
     {
        sign = true;
        for(j = 0;j < em;j ++)
          if(dis[mat[j].v] > dis[mat[j].u]+mat[j].d) dis[mat[j].v] = dis[mat[j].u]+mat[j].d,sign = false;
        if(sign) break;
     }
     for(j = 0;j < em;j ++)
          if(dis[mat[j].v] > dis[mat[j].u]+mat[j].d) return false;
     return true;
}
int main()
{
    int t,x,y,i,a,b,c;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d%d%d",&n,&x,&y);
       for(i = em = 0;i < x;i ++)
       {
          scanf("%d%d%d",&a,&b,&c);
          if(a > b) swap(a,b);
          add(a,b,c);
       }
       for(i = 0;i < y;i ++)
       {
          scanf("%d%d%d",&a,&b,&c);
          if(a > b) swap(a,b);
          add(b,a,-c);
       }
       if(BellmanFord())
       {
         if(dis[n] == inf) puts("-2");
         else printf("%d\n",dis[n]);
       }else puts("-1");
    }
    return 0;
}


#include <iostream>
using namespace std;
const int maxn = 1005;
const int inf = 1000000000;
struct Node
{
    int u,v,d;
    Node *next;
};
Node mat[maxn*205];
Node *eda[maxn];
int em,n,m,dis[maxn];
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
     bool sign;
     for(i = 1;i <= n;i ++) dis[i] = 0;
     for(i = 1;i < n;i ++)
     {
       sign = true;
       for(j = 0;j < em;j ++)
         if(dis[mat[j].v] < dis[mat[j].u] + mat[j].d)
           dis[mat[j].v] = dis[mat[j].u] + mat[j].d,sign = false;
       if(sign) break;
     }  
     for(j = 0;j < em;j ++)
        if(dis[mat[j].v] < dis[mat[j].u] + mat[j].d) return false;
     return true;
}
int main()
{
    int i,j,a,b,c;char cor[5];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
       for(i = em = 0;i < m;i ++)
       {
         scanf("%s",cor);
         if(cor[0] == 'P')
         {
           scanf("%d%d%d",&a,&b,&c);
           add(b,a,c);add(a,b,-c);
         }else
         {
           scanf("%d%d",&a,&b);
           add(b,a,1);
         }
       }
       if(BellmanFord()) puts("Reliable");
       else puts("Unreliable");
    }
    return 0;
}

#include <iostream>
using namespace std;
const int maxn = 505;
const int maxe = 255000;
struct Node { int v,d,next;};
Node mat[maxe],mat2[maxe];
int eda[maxn],eda2[maxn],scur,sink,em,n,m;
int h[maxn],gap[maxn];
void init()
{
     em = 0;
     memset(eda,-1,sizeof(eda));
     memset(eda2,-1,sizeof(eda2));
}
void insert(int u,int v,int d)
{
     mat[em].v = v; mat[em].d = d;
     mat[em].next = eda[u];
     eda[u] = em;
     mat2[em].v = v; mat2[em].d = d;
     mat2[em].next = eda2[u];
     eda2[u] = em++;
     swap(u,v);
     mat[em].v = v; mat[em].d = d;
     mat[em].next = eda[u];
     eda[u] = em;
     mat2[em].v = v; mat2[em].d = d;
     mat2[em].next = eda2[u];
     eda2[u] = em++;
}
int dfs(int u,int d)
{
    int j,v,mind,minh = n-1,lv = d;
    for(j = eda[u];j != -1;j = mat[j].next)
    {
        v = mat[j].v;
        if(mat[j].d > 0)
        {
            if(h[v]+1 == h[u])
            {
               if(lv > mat[j].d) mind = mat[j].d;
               else mind = lv;
               mind = dfs(v,mind);
               mat[j].d -= mind;
               mat[j^1].d += mind;
               lv -= mind;
               if(h[scur] >= n) return d - lv;
               if(lv == 0) break;
            }
            if(h[u] > minh) minh = h[u];
        }
    }
    if(lv == d)
    {
      --gap[h[u]];
      if(gap[h[u]] == 0) h[scur] = n;
      h[u] = minh+1;
      ++gap[h[u]];
    }
    return d - lv;
}
int isap(int st,int ed)
{
    memset(h,0,sizeof(h));
    memset(gap,0,sizeof(gap));
    gap[st] = n;
    int v = 0;
    while(h[st] < n)
    {
      v += dfs(st,INT_MAX);
    }
    return v;
}
int main()
{
    int i,a,b,c,v1,v2;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
       init();
       for(i = 0;i < m;i ++)
       {
          scanf("%d%d%d",&a,&b,&c);
          insert(a,b,c);
       }
       v1 = isap(0,n-1);
       printf("%d\n",v1+v2);
    }
    return 0;
}

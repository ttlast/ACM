#include <iostream>
using namespace std;
const int maxn = 16;
const int maxe = 2005;
struct Node
{
    int v,d,next;
};
int eda[maxn],em,scur,sink,n,m;
int h[maxn],gap[maxn];
Node mat[maxe];
void insert(int u,int v,int d)
{
     mat[em].v  = v;mat[em].d = d;
     mat[em].next = eda[u];
     eda[u] = em++;
     swap(u,v);
     mat[em].v  = v;mat[em].d = 0;  //debug
     mat[em].next = eda[u];
     eda[u] = em++;
}
void init(int n)
{
     em = 0;
     int i;
     for(i = 0;i <= n;i ++) eda[i] = -1;
}
int dfs(int u,int d)
{
    int lv = d,minh = n-1,mind,j,v;
    if(u == sink) return d;   //debug
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
            if(minh > h[v]) minh = h[v];
        }
    }
    if(d == lv)
    {
       --gap[h[u]];
       if(gap[h[u]] == 0) h[scur] = n;
       h[u] = minh + 1;
       ++gap[h[u]];
    }
    return d - lv;
}
int isap(int st,int ed)
{
    int v = 0;
    scur = st;sink = ed;
    memset(h,0,sizeof(h));
    memset(gap,0,sizeof(gap));
    gap[st] = n;
    while(h[st] < n)
    {
       v += dfs(st,INT_MAX);
    }
    return v;
}
int main()
{
    int t,i,a,b,c,v,ncase = 0;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d%d",&n,&m);
       init(n);
       for(i = 0;i < m;i ++)
         scanf("%d%d%d",&a,&b,&c),insert(a,b,c);
       v = isap(1,n);
       ncase ++;
       printf("Case %d: %d\n",ncase,v);
    }
    return 0;
}

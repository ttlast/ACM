//最小割点集 
#include <iostream>
using namespace std;
const int inf = 1000000000;
const int maxn = 5005;
const int maxe = 120005;
struct Node
{
   int v,next,d;
};
Node mat[maxe];
int eda[maxn],em,n,m,val[maxn],scur,sink;
int h[maxn],gap[maxn];
bool sign[maxn];
void init()
{
    em = 0;int i;
    for(i = 0;i <= n;i ++) eda[i] = -1;
}
void insert(int u,int v,int d)
{
    mat[em].v = v; mat[em].d = d;
    mat[em].next = eda[u];
    eda[u] = em++;
    swap(u,v);
    mat[em].v = v; mat[em].d = 0;
    mat[em].next = eda[u];
    eda[u] = em++;
}
void dfs(int u)
{
    if(u == sink) return ;
    sign[u] = true;
    int j;
    for(j = eda[u];j != -1;j = mat[j].next)
    {
       if(mat[j].d > 0 && !sign[mat[j].v])
         dfs(mat[j].v);
    }
}
int dfs(int u,int d)
{
    int j,v,mind,minh = n,lv = d;
    if(u == sink) return d;
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
            if(h[scur] > n) return d - lv;
            if(lv == 0) break;
          }
          if(minh > h[v]) minh = h[v];
        }
    }
    if(d == lv)
    {
      --gap[h[u]];
       if(gap[h[u]] == 0) h[scur] = n+1;
       h[u] = minh + 1;
       ++gap[h[u]];
    }
    return d - lv;
}
__int64 isap(int st,int ed)
{
    scur = st;sink = ed;
    __int64 v = 0;
    memset(h,0,sizeof(h));
    memset(gap,0,sizeof(gap));
    gap[st] = n+1;
    while(h[st] <= n)
    {
      v += dfs(st,inf);
    }
    return v;
}
int main()
{
    int i,a,b,ss;
	__int64 sum;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
       n ++;
       init();
       for(i = 1,sum = 0;i < n;i ++)
       {
         scanf("%d",&val[i]);
         if(val[i] > 0) insert(0,i,val[i]),sum += val[i];
         else insert(i,n,-val[i]);
       }
       for(i = 1;i <= m;i ++)
       {
         scanf("%d%d",&a,&b);
         insert(a,b,inf);
       }
       __int64 s = isap(0,n);
       memset(sign,false,sizeof(sign));
       dfs(0);
       for(i = 1,ss = 0;i <= n;i ++) if(sign[i]) ss++;
       printf("%d %I64d\n",ss,sum - s);
    }
    return 0;
}

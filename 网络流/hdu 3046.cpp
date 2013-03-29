#include <iostream>
using namespace std;
const int inf = 1000000000;
const int maxn = 50000;
const int maxe = 250000;
int dir[2][2] = {{1,0},{0,1}};
struct Node
{
    int v,d,next;
};
int n,m;
int eda[maxn],scur,sink,em,al;
int h[maxn],gap[maxn];
Node mat[maxe];
bool safe(int x,int y)
{
	if(x >= 0 && x < n && y >= 1 && y <= m) return true;
	return false;
}
void insert(int u,int v,int d) 
{
     mat[em].v = v; mat[em].d = d;
     mat[em].next = eda[u];
     eda[u] = em ++;
     swap(u,v);
     mat[em].v = v; mat[em].d = d;
     mat[em].next = eda[u];
     eda[u] = em ++;
}
void init()
{
    em = 0;
    memset(eda,-1,sizeof(eda));
}
int dfs(int u,int d)
{
    int lv = d,minh = al-1,mind,j,v;
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
              if(h[scur] >= al) return d - lv;
              if(lv == 0) break;
            }
            if(minh > h[v]) minh = h[v];
        }
    }
    if(d == lv)
    {
       --gap[h[u]];
       if(gap[h[u]] == 0) h[scur] = al;
       h[u] = minh + 1;
       ++gap[h[u]];
    }
    return d - lv;
}
int isap()
{
    memset(h,0,sizeof(h));
    memset(gap,0,sizeof(gap));
    gap[scur] = al;
    int v = 0;
    while(h[scur] < al)
    {
       v += dfs(scur,INT_MAX);
    }    
    return v;
}
int main()
{
    int i,j,v,ma,ncase = 0,t1,t2; 
    scur = 0;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
       init();
       al = n*m+2;
       if(n > m) ma = n;
       else ma = m+1;
       sink = n*ma+m;
       for(i = 0;i < n;i ++)
       {
          for(j = 1;j <= m;j ++)
          {
              t1 = i*ma+j;
              scanf("%d",&v);
              if(v == 1)
              {
                insert(scur,t1,inf);
              }
              else if(v == 2)
              {
                insert(t1,sink,inf);
              }
			  if(safe(i+1,j))
			  {
              t2 = (i+1)*ma+j;
              insert(t1,t2,1);
			  }
			  if(safe(i,j+1))
			  {
              t2 = t1+1;
              insert(t1,t2,1);
			  }
          }
       }
       ncase ++;
       printf("Case %d:\n",ncase);
       v = isap();
       printf("%d\n",v); 
    } 
    return 0;
}

#include <iostream>
using namespace std;
const int maxn = 3000;
const int maxe = 120000;
struct Node
{
    int v,d,next;
};
Node mat[maxe];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int n,m,eda[maxn],em,val[maxn][maxn],scur,sink,km;
int h[maxn],gap[maxn],al;
void add(int u,int v,int d)
{
     mat[em].v = v; mat[em].d = d;
     mat[em].next = eda[u];
     eda[u] = em++;
     swap(u,v);
     mat[em].v = v; mat[em].d = 0;
     mat[em].next = eda[u];
     eda[u] = em++;
}
bool safe(int x,int y)
{
     if(x >= 0 && x < n && y >= 0 && y < m) return true;
     return false;
}
void init()
{
    em = 0;
    if(n > m) km = n;
    else km = m;
    scur = km*km;sink = scur+1;
    memset(eda,-1,sizeof(eda));
}
int dfs(int u,int d)
{
    if(u == sink) return d;
    int j,v,minh = al-1,mind,lv = d;
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
           if(h[scur] > al) return d - lv;
           if(lv == 0) break;
         }
         if(h[v] < minh) minh = h[v];
       }
    }    
    if(d == lv)
    {
      --gap[h[u]];
      if(gap[h[u]] == 0) h[scur] = al;
      h[u] = minh+1;
      ++gap[h[u]];
    }
    return d - lv;
}
int isap()
{
    int v = 0;
    al = n*m+2;
    memset(gap,0,sizeof(gap));
    memset(h,0,sizeof(h));
    gap[scur] = al;
    while(h[scur] < al)
    {
      v += dfs(scur,INT_MAX);
    }
    return v;
}
int main()
{
    int i,j,u,v,k,x,y,s1,s2;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
       init();
       for(i = s1 = 0;i < n;i ++)
         for(j = 0;j < m;j ++)
         {
            scanf("%d",&val[i][j]);
            s1 += val[i][j];
         }
       for(i = 0;i < n;i ++)
        for(j = 0;j < m;j ++)
        {
          u = i*km+j;
          if(i%2 == j%2)
          {
             add(scur,u,val[i][j]);
             for(k = 0;k < 4;k ++)
             {
               x = i+dir[k][0]; y = j+dir[k][1];
               if(safe(x,y))
               {
                 v = x*km+y;
                 add(u,v,val[i][j]);
               }
             }
          }else add(u,sink,val[i][j]);
        }
        s2 = isap();
        printf("%d\n",s1-s2);
    }
    return 0;
}

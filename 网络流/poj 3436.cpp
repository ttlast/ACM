#include <iostream>
using namespace std;
const int maxn = 150;
const int maxe = 30000;
const int inf = INT_MAX;
typedef int LL;
struct Node{
    int v,next;
    LL d;
};
struct Mach{
    int num;
    int in[11],out[11];
};
int eda[maxn],eda2[maxn],em,em2,scur,sink,n,m,p;
int h[maxn],gap[maxn];
Node mat[maxe],mat2[maxe];
Mach ma[55];
bool comp(int a[],int b[]){
    int i;
    for(i = 0;i < p;i ++)
		if(a[i] != b[i] && a[i] != 2 && b[i] != 2) return false;
	return true;
}
void init(int n){
    int i;
    em = 0;em2 = 0;
    for(i = 0;i <= n;i ++) eda[i] = eda2[i] = -1;
}
void insert(int u,int v,LL d = 0){
    mat[em].v = v;mat[em].d = d;
    mat[em].next = eda[u];
    eda[u] = em++;
    mat2[em2].v = v;mat2[em2].d = d;
    mat2[em2].next = eda2[u];
    eda2[u] = em2++;
    swap(u,v);
    mat[em].v = v;mat[em].d = 0;
    mat[em].next = eda[u];
    eda[u] = em++;
    mat2[em2].v = v;mat2[em2].d = 0;
    mat2[em2].next = eda2[u];
    eda2[u] = em2++;
}
LL dfs(int u,LL d){
    int lv = d,minh = n-1,mind,j,v;
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
               mat[j].d -= mind; mat[j^1].d += mind;
               lv -= mind;
               if(h[scur] >= n) return d-lv;
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
      ++ gap[h[u]];
    }
    return d - lv;
}
LL isap(int st,int ed)
{
    LL v = 0;
    scur = st,sink = ed;
    memset(h,0,sizeof(h));
    memset(gap,0,sizeof(gap));
    gap[st] = n;  //所有定点数+1
    while(h[st] < n){
        v += dfs(st,inf); //or max
    }
    return v;
}
int main()
{
    int i,j;
    LL maxflow,nedage;
    while(scanf("%d%d",&p,&n)!=EOF)
    {
        init(n*2+2);
        for(i = 0;i < n;i ++){
           scanf("%d",&ma[i].num);
           for(j = 0;j < p;j ++) scanf("%d",&ma[i].in[j]);
           for(j = 0;j < p;j ++) scanf("%d",&ma[i].out[j]);
        }
        for(i = 0;i < n;i ++)
        {
           insert(i,i+n,ma[i].num);
           for(j = i+1;j < n;j ++){
            if(comp(ma[i].out,ma[j].in)) insert(i+n,j,inf);
            if(comp(ma[i].in,ma[j].out)) insert(j+n,i,inf);
           }
           for(j = 0;j < p;j ++)
            if(ma[i].in[j] == 1) break;
           if(j >= p) insert(n*2,i,inf);
           for(j = 0;j < p;j ++)
            if(ma[i].out[j] == 0) break;
           if(j >= p) insert(i+n,n*2+1,inf);
        }
        n = n*2+2;
        maxflow = isap(n-2,n-1);
        n = n/2-1;
        for(i = n,nedage = 0;i < n*2;i ++)
          for(j = eda[i];j != -1;j = mat[j].next)
            if(mat[j].v >= n||i-n == mat[j].v) continue;
            else if(mat[j].d < mat2[j].d) nedage ++;
        printf("%d %d\n",maxflow,nedage);
        for(i = n,nedage = 0;i < n*2;i ++)
          for(j = eda[i];j != -1;j = mat[j].next)
            if(mat[j].v >= n||i-n == mat[j].v) continue;
            else if(mat[j].d < mat2[j].d)  printf("%d %d %d\n",i-n+1,mat[j].v+1,mat2[j].d - mat[j].d);
    }
    return 0;
}

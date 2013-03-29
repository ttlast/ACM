#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int inf = 1000000000;
const int maxn = 1000;
//思考了下，发现Tarjan原理和spfa合用，可以加速。现在验证一下
//3666用常规的spfa等算法老是tle.
struct Node
{
    int v;
    double d;
    Node *next; 
};
Node mat[400*400*10];
bool sign[maxn],in[maxn];
Node *eda[maxn];
int n,m,u,l,em;
double dis[maxn];
void add(int u,int v,double d)
{
     mat[em].v = v;mat[em].d = d;
     mat[em].next = eda[u];
     eda[u] = &mat[em++]; 
}
bool spfa(int u)  //dfs
{
     Node *mp;
     sign[u] = true;
	 if(in[u]) return false;
	 in[u] = true;
     int v;
     mp = eda[u];
     while(mp)
     {
       v = mp->v;
       if(dis[mp->v] < dis[u]+mp->d)
       {
         dis[mp->v] = dis[u]+mp->d;
         if(!spfa(mp->v)) return false;
       }
       mp = mp->next;
     }
	 in[u] = false;
     return true;
}
bool rq()
{
    int i,j,al = n+m;
    for(i = 1;i <= al;i ++) dis[i] = 0;
	memset(in,false,sizeof(in));
    memset(sign,false,sizeof(sign));
    for(i = 1;i <=  al;i ++)
    {
       if(!sign[i])
       {
          if(!spfa(i))  return false; 
       }
    } 
    return true; 
}
int main()
{
    int i,j,c,al;
    double lgl,lgu;
    while(scanf("%d%d%d%d",&n,&m,&l,&u)!=EOF)
    {
       lgl = log(l*1.0); lgu = log(u*1.0);
	   al = n+m;
	   for(i = 1;i <= al;i ++) eda[i] = NULL;
       for(i = 1,em = 0;i <= n;i ++)
         for(j = 1;j <= m;j ++)
         {
          scanf("%d",&c);
          add(i,j+n,log(1.0*c)-lgu);
          add(j+n,i,lgl-log(1.0*c)); 
         }
       if(rq()) puts("YES");
       else puts("NO");
    } 
    return 0;
}


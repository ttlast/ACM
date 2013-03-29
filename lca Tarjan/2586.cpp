#include <iostream>
using namespace std;
const int maxn = 85008;
int n,m,em,em2;
struct Node
{
     int u,v,d;
     Node *next;
};
Node *eda[maxn];
Node *eda2[maxn];
Node mat[maxn];
Node mat2[maxn];
bool sign[maxn];
int dis[maxn],fa[maxn],fu[maxn];
int find(int u)
{
 	if(u != fa[u]) fa[u] = find(fa[u]);
 	return fa[u];
}
void Tarjan(int u)
{
 	 Node *mp;
 	 fa[u] = u;
	 sign[u] = true;
 	 mp = eda2[u];
 	 while(mp)   //¾«»ªµÄ±ßdfs£¬±àÕÒ 
 	 {
	   if(sign[mp->v])
	        fu[mp->d] = find(mp->v);
	   mp = mp->next;
	 }
 	 mp = eda[u];
 	 while(mp)
 	 {
	   if(!sign[mp->v])
	   {
		  dis[mp->v] = dis[u]+mp->d;
		  Tarjan(mp->v);
		  fa[mp->v] = u;
	   }
	   mp = mp->next;
	 }
}
int main()
{
 	int t,i,j,a,b,c;
 	scanf("%d",&t);
 	while(t--)
 	{
      scanf("%d%d",&n,&m);
      em = em2 = 0;
      for(i = 1;i <= n;i ++) eda[i] = eda2[i] = NULL;
      for(i = 1;i < n;i ++)
      {
		  scanf("%d%d%d",&a,&b,&c);
		  mat[em].u = a; mat[em].v = b;
		  mat[em].next = eda[a];
		  eda[a] = &mat[em];
		  mat[em++].d = c;
		  mat[em].u = b; mat[em].v = a;
		  mat[em].next = eda[b];
		  eda[b] = &mat[em];
		  mat[em++].d = c;
	  }      
      for(i = 0;i < m;i ++)
      {
 		  scanf("%d%d",&a,&b);
 		  mat2[em2].u = a; mat2[em2].v = b;
 		  mat2[em2].next = eda2[a];
 		  eda2[a] = &mat2[em2];
          mat2[em2++].d = i;
		  mat2[em2].u = b; mat2[em2].v = a;
 		  mat2[em2].next = eda2[b];
 		  eda2[b] = &mat2[em2];
          mat2[em2++].d = i;
	  }      
      memset(sign,false,sizeof(sign));
      memset(dis,0,sizeof(dis));
      Tarjan(1);
      for(i = 0;i < m;i ++)
      {
 		  printf("%d\n",dis[mat2[i*2].u]+dis[mat2[i*2].v]-dis[fu[i]]-dis[fu[i]]);
 	  }
 	  puts(""); 
  	}
 	return 0;
}

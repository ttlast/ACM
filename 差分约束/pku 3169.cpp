#include <iostream>
using namespace std;
const int inf = 1000000000;
const int maxn = 1005;
const int maxe = 40005;
//最远，求最短路 
int n,ml,md,em;
struct Node
{
    int u,v,d;
};
Node mat[maxe];
void add(int u,int v,int d)
{
 	 mat[em].u = u;mat[em].v = v;
 	 mat[em++].d = d;
}
int dis[maxn];
bool BellmanFord()
{
 	 int u,v,i,j;
 	 for(i = 1;i <= n;i ++) dis[i] = inf;
 	 dis[1] = 0;
 	 bool sign;
 	 for(i = 1;i < n;i ++)
 	 {
        sign = true;
        for(j = 0;j < em;j ++)
          if(dis[mat[j].v] > dis[mat[j].u] + mat[j].d)
            dis[mat[j].v] = dis[mat[j].u] + mat[j].d,sign = false;
        if(sign) break;
   	 }
   	 for(j = 0;j < em;j ++)
          if(dis[mat[j].v] > dis[mat[j].u] + mat[j].d) return false;
     return true;
}
int main()
{
 	int i,a,b,c;
 	while(scanf("%d%d%d",&n,&ml,&md)!=EOF)
 	{
      for(i = em = 0;i < ml;i ++)
      {
		  scanf("%d%d%d",&a,&b,&c);
		  if(a > b) swap(a,b);
		  add(a,b,c);
	  }
	  for(i = 0;i < md;i ++)
	  {
 		  scanf("%d%d%d",&a,&b,&c);
 		  if(a > b) swap(a,b);
 		  add(b,a,-c);
	  }
	  for(i = 1;i < n;i ++)
	  		add(i+1,i,0);
	  if(BellmanFord())
	  {
        if(dis[n] == inf) puts("-2");
        else printf("%d\n",dis[n]);
   	  }else puts("-1");
    }
 	return 0;
}

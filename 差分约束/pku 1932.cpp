#include <iostream>
#include <stack>
using namespace std;
const int maxn = 10005;
//还得考虑1 和 n是否联通 
struct Node
{
    int u,v;
    Node *next;
};
Node mat[maxn*10];
Node *eda[maxn];
int n,em;
int sign[maxn];
int dis[maxn],val[maxn];
int h;

void dfs(int u)
{
	int v;
    sign[u] = 1;
    Node *mp;
	mp = eda[u];
	while(mp)
	{
		v = mp->v;
		if(!sign[v]) dfs(v);
		mp = mp->next;
	}
}

void add(int u,int v)
{
    mat[em].u = u; mat[em].v = v;
    mat[em].next = eda[u];
    eda[u] = &mat[em++];
}
bool BellmanFord()
{
    int i,j;
    bool sign;
    memset(dis,0,sizeof(dis));
    dis[1] = 100;
    for(i = 1;i < n;i ++)
    {
       sign = false;
       for(j = 0;j < em;j ++)
         if(dis[mat[j].v] < dis[mat[j].u]+val[mat[j].v] && dis[mat[j].u] > 0)
            dis[mat[j].v] = dis[mat[j].u]+val[mat[j].v],sign = true;
       if(!sign) break;
    }
    for(j = 0;j < em;j ++)
		if(dis[mat[j].v] < dis[mat[j].u]+val[mat[j].v] && dis[mat[j].u] > 0) { h = mat[j].v; return false;}
    return true;
}
int main()
{
    int i,k,t;
    while(scanf("%d",&n))
    {
      if(n < 0) break;
      em = 0;
      for(i = 1;i <= n;i ++) eda[i] = NULL; 
      for(i = 1;i <= n;i ++)
      {
          scanf("%d",&val[i]);
          scanf("%d",&k);
          while(k--)
          {
            scanf("%d",&t);
            add(i,t);
            
          }
      }
      if(BellmanFord())
      {
        if(dis[n] > 0) puts("winnable");
        else puts("hopeless");
      }else 
      {
	    memset(sign,false,sizeof(sign));
	    dfs(h);
		if(sign[n]) puts("winnable");
		else puts("hopeless");
      }
    }
    return 0;
}
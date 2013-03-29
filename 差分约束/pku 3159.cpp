#include <iostream>
#include <stack>
using namespace std;
const int inf = 1000000000;
const int maxn = 30005;
const int maxe = 150005;
int n,m,em;
struct Node
{
    int v,d;
    Node *next;
};
Node *eda[maxn];
Node mat[maxe];
int dis[maxn];
bool in[maxn];
void add(int u,int v,int d)
{
    mat[em].v = v; mat[em].d = d;
    mat[em].next = eda[u];
    eda[u] = &mat[em++];
}
void spfa()
{
    int u;
    Node *mp;
    stack<int> s;
    for(u = n;u >= 1;u --)
    {
 	    in[u] = true; dis[u] = inf;
 	    s.push(u);
	}
	dis[1] = 0;
	while(!s.empty())
	{
       u = s.top();s.pop();
       //if(u == n) break;
       in[u] = false;
       mp = eda[u];
       while(mp)
       {
	     if(dis[mp->v] > dis[u]+mp->d)
	     {
		   dis[mp->v] = dis[u]+mp->d;
		   if(!in[mp->v])
		   {
               in[mp->v] = true;
               s.push(mp->v);
 		   }
 		 }
	      mp = mp->next;
	   }
 	}
 	printf("%d\n",dis[n]);
}
int main()
{
 	int i,j,a,b,c;
 	while(scanf("%d%d",&n,&m)!=EOF)
 	{
      for(i = em = 0;i < m;i ++)
      {
		 scanf("%d%d%d",&a,&b,&c);
		 add(a,b,c);
	  }
	  spfa();
  	}
 	return 0;
}

#include <iostream>
#include <stack>
using namespace std;
const int inf = 1000000000;
const int maxn = 50005;
int st,ed,em;
struct Node
{
    int v,d;
    Node *next;
};
Node *eda[maxn];
Node mat[maxn*10];
int dis[maxn];
bool in[maxn];
void add(int u,int v,int d)
{
 	 mat[em].v = v;mat[em].d = d;
 	 mat[em].next = eda[u];
 	 eda[u] = &mat[em++];
}
void spfa()
{
 	 int u,v,i;
 	 Node *mp;
 	 stack<int> s;
 	 for(i = st;i <= ed;i ++)
 	 {
         dis[i] = 0; in[i] = true;
         s.push(i);
   	 }
 	 while(!s.empty())
 	 {
	     u = s.top();s.pop();
	     in[u] = false;
	     mp = eda[u];
	     while(mp)
	     {
		  	 if(dis[mp->v] < dis[u]+mp->d)
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
 	 printf("%d\n",dis[st]);
}
int main()
{
 	int n,i,a,b,c;
 	while(scanf("%d",&n)!=EOF)
 	{
      for(i = 0;i < maxn;i ++) eda[i] = NULL;
      for(i = em = ed = 0,st = maxn;i < n;i ++)
      {
		 scanf("%d%d%d",&a,&b,&c);
		 b ++;
		 add(b,a,c);
		 if(b > ed) ed = b;
		 if(a < st) st = a;
	  }
	  for(i = st;i < ed;i ++)
	  {
 		 add(i+1,i,0);
 		 add(i,i+1,-1);
	  }
	  spfa();
  	}
 	return 0;
}

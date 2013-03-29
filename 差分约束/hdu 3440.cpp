#include <iostream>
#include <stack>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 1005;
const int inf = 1000000000;
//出发点不同的最短路。 很好的差分约束题目
struct Node
{
    int u,v,d;
    Node *next;
};
Node mat[maxn*10];
Node *eda[maxn];
int n,em,d,dis[maxn],sc,ed,in[maxn];
struct house
{
    int num,pos;
};
house num[maxn];
void add(int u,int v,int d)
{
     mat[em].u = u;
 	 mat[em].v = v; mat[em].d = d;
 	 mat[em].next = eda[u];
 	 eda[u] = &mat[em++];
}
bool comp(const house & t1,const house & t2)
{
 	 return t1.num < t2.num;
}
/* 
bool BellmanFord()
{
 	 int i,j;
 	 bool sign;
 	 for(i = 0;i <= n;i ++) dis[i] = inf;
	 dis[sc] = 0;
 	 for(i = 1;i < n;i ++)
 	 {
        sign = true;
        for(j = 0;j < em;j ++)
          if(abs(dis[mat[j].v]) > abs(dis[mat[j].u]+mat[j].d))
             dis[mat[j].v] = dis[mat[j].u]+mat[j].d,sign = false;
        if(sign) break;
   	 }
   	 for(j = 0;j < em;j ++)
          if(dis[mat[j].v] > dis[mat[j].u]+mat[j].d) return false;
 	 return true;
}*/
bool spfa()
{
 	 int u,v,i;
 	 Node *mp;
 	 queue<int> q;
 	 for(i = 0;i < n;i ++) dis[i] = inf,in[i] = 0;
 	 dis[sc] = 0;
 	 q.push(sc);
 	 while(!q.empty())
 	 {
	    u = q.front();q.pop();
	    mp = eda[u];
	    while(mp)
	    {
	 	   if(dis[mp->v] > dis[u]+mp->d)
	 	   {
              in[mp->v] ++;
              if(in[mp->v] > n) return false;
              q.push(mp->v);
              dis[mp->v] = dis[u]+mp->d;
		   }
		   mp = mp->next;
		}
	 }
 	 return true;
}
int main()
{
 	int t,i,ncase = 0;
 	scanf("%d",&t);
 	while(t--)
 	{
       scanf("%d%d",&n,&d);
       for(i = 0;i < n;i ++)
       {
          scanf("%d",&num[i].num);
          num[i].pos = i;
          eda[i] = NULL;
  	   }
  	   sort(num,num+n,comp);
	   sc = num[0].pos;ed = num[n-1].pos;
	   if(sc > ed) swap(sc,ed);
  	   for(i = 1, em = 0;i < n;i ++)
	   {
  	   	  if(num[i-1].pos<num[i].pos) add(num[i-1].pos,num[i].pos,d);
		  else add(num[i].pos,num[i-1].pos,d);
	   }
	   for(i = 1;i < n;i ++)
	         add(i,i-1,-1);
  	   ncase ++;
  	   //if(BellmanFord())  printf("Case %d: %d\n",ncase,dis[ed]);
  	   if(spfa())  printf("Case %d: %d\n",ncase,dis[ed]);
	   else printf("Case %d: -1\n",ncase);
  	}
 	return 0;
}

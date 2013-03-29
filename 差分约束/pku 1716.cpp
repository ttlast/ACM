#include <iostream>
using namespace std;
const int maxn = 90005;
const int inf = 1000000000;
int dis[maxn];
int n,m,em,st,ed;
struct Node
{
    int u,v,d;
};
Node edage[maxn]; 
bool BellmanFord(int src)
{
 	 int i,j,u,v;
 	 for(i = st;i <= ed;i ++) dis[i] = -inf;
 	 dis[src] = 0;
	 bool sign ;
	 for(i = st;i < ed;i ++) //进行n-1次松弛操作.
	 {
         sign = true;
         for(j = 0;j < em;j ++)
		 {
            u = edage[j].u;
            v = edage[j].v;
            if(dis[v]  < dis[u] + edage[j].d) { dis[v] = dis[u]+ edage[j].d; sign = false;}
   		 }
   		 if(sign) break;  //此轮没有松弛，那么下一回合也不会有的了。
  	 }
  	 for(j = 0;j < em;j ++)  //判断负的回路。
	{
         u = edage[j].u;
         v = edage[j].v;
         if(dis[v] < dis[u] + edage[j].d) return false;
   	} 
  	 return true;
}
void read()
{
 	 int i,x,y;
 	 n = maxn;
 	 while(scanf("%d",&m)!=EOF)
 	 {
         em = 0;
         for(i =0, st = maxn, ed = 0;i < m;i ++)
         {
           scanf("%d%d",&x,&y);
		   y ++;  //因为点数还包括初始点。 
		   if(x < st) st = x;
           if(y > ed) ed = y;
           edage[em].u = x; edage[em].v = y;  // y - x >= 2; 求最小。 
           edage[em++].d = 2;
   		 }
		 for(i = st+1;i <= ed;i ++)
		 {
		   edage[em].u = i-1; edage[em].v = i;
           edage[em++].d = 0;
		   edage[em].u = i; edage[em].v = i-1;
           edage[em++].d = -1;
		 }
   		 BellmanFord(st);
   		 printf("%d\n",dis[ed]);
	 }
}

int main()
{
    read();
    return 0;
}

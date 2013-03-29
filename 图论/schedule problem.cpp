#include <iostream>
using namespace std;
#define inf 0
const int maxn = 10000;
int val[maxn];
int dis[maxn];
int n,m,em;
struct Node
{
    int u,v,d;
};
Node edage[maxn*10]; 
bool BellmanFord(int src)
{
 	 int i,j,u,v;
 	 for(i = 1;i <= n;i ++) dis[i] = inf;
 	 dis[src] = 0;
	 bool sign ;
	 for(i = 1;i < n;i ++) //进行n-1次松弛操作.
	 {
         sign = true;
         for(j = 0;j < em;j ++)
		 {
            u = edage[j].u;
            v = edage[j].v;
            if(dis[v] < dis[u] + edage[j].d) { dis[v] = dis[u]+ edage[j].d; sign = false;}
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
void insert(int u,int v,int d)
{
	edage[em].u = u;edage[em].v = v;
	edage[em++].d = d;
}
int main()
{
	char c[10];
	int a,b,i,ncase = 1;
	while(scanf("%d",&n),n)
	{
		em = 0;
		for(i = 1;i <= n;i ++) scanf("%d",&val[i]);
		while(scanf("%s",c))
		{
			if(c[0] == '#') break;
			scanf("%d%d",&a,&b);
			if(c[0] == 'S')
			{
				if(c[2] == 'S')
				{
					insert(b,a,0);
				}else if(c[2] == 'F')
				{
					insert(b,a,val[b]);
				}
			}else if(c[0] == 'F')
			{
				if(c[2] == 'S')
				{
					insert(b,a,-val[a]);
				}else if(c[2] == 'F')
				{
					insert(b,a,val[b]-val[a]);
				}
			}
		}
		printf("Case %d:\n",ncase++);
		if(BellmanFord(1))
		{
		for(i = 1;i <= n;i ++)
			printf("%d %d\n",i,dis[i]);
		}else puts("impossible");
		printf("\n");
	}
	return 0;
}
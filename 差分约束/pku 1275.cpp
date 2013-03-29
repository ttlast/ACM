#include <iostream>
using namespace std;
const int inf = 1000000000;
const int maxe = 4000;
//求最长路 最少 
struct Node
{
    int u,v,d;
};
Node eda[maxe];
int peo[30],num[30],sum,em,dis[30];
void add(int u,int v,int d)
{
 	 eda[em].u = u;
 	 eda[em].d = d;
 	 eda[em++].v = v;
}
void rebuild(int ans)
{
 	 em = 48;
 	 int i;
 	 for(i = 1;i <= 24;i ++)
 	 {
       if(i > 8) add(i,i-8,num[i]);
       else add(i,i+16,num[i]-ans);
   	 }
   	 add(24,0,ans);
}
bool BellmanFord()
{
 	 int i,j;
 	 bool sign;
 	 for(i = 0;i <= 24;i ++) dis[i] = 0;
 	 for(i = 1;i <= 24;i ++)
 	 {
         sign = true;
         for(j = 0;j < em;j ++)
         {
           if(dis[eda[j].v] < dis[eda[j].u]+eda[j].d)
             dis[eda[j].v] = dis[eda[j].u]+eda[j].d,sign = false;
   		 }
   		 if(sign) break;
   	 }
   	 for(j = 0;j < em;j ++)
   	     if(dis[eda[j].v] < dis[eda[j].u]+eda[j].d) return false;
     return true;
}
void df()
{
 	 int l = 0,r = sum,mid,ans = inf;
 	 while(l <= r)
 	 {
		 mid = (l+r)>>1;
		 rebuild(mid);
		 if(BellmanFord())
		 {
		    if(ans > mid) ans = mid;
		    r = mid - 1;
		 }else l = mid+1;
	 }
	 if(ans == inf) puts("No Solution");
	 else printf("%d\n",ans);
} 
int main()
{
 	int t,i,tm,n;
 	scanf("%d",&t);
 	while(t--)
 	{
       memset(peo,0,sizeof(peo));
       for(i = 1,sum = 0;i <= 24;i ++)
       {
         scanf("%d",&num[i]); //需求 
         sum += num[i];
	   }
       scanf("%d",&n);
       if(sum > n) sum = n;
       for(i = 0;i < n;i ++)
       {
		  scanf("%d",&tm);
		  tm ++;
		  peo[tm] ++;
	   }
	   for(i = 1,em = 0;i <= 24;i ++)
	   {
 		  add(i,i-1,0);
 		  add(i-1,i,-peo[i]);
	   }
	   df();
  	}
 	return 0; 
}

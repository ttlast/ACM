#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;
const int maxn = 20001;
const int maxe = 50003;
struct Node{
	 int v,next;
};
int eda[maxn],em,n;
bool dy;
Node mat[maxe];
stack <int> ss;
int sign[20001],low[20001],dfn[20001],index,color,co[20001],w[maxn];
void Tarjan(int n)
{
 	 int i,j,t1,t2;
 	 sign[n] = 1;
	 int cn = 0;
 	 ss.push(n);
 	 low[n] = dfn[n] = index ++;
	 for(i = eda[n];i != -1;i = mat[i].next)
 	 {
       t2 = mat[i].v;
	   if(w[t2]) dy = true;  //访问访问过
       if(sign[t2] == 2) continue;
	   else if(sign[t2] == 0) {
		   Tarjan(t2);
		   if(low[t2] > dfn[n]) dy = true;
		   if(low[n] >= low[t2]) low[n] = low[t2];
		   if(dfn[n] > low[t2]) cn ++;
	   }else{
			low[n] = min(low[n],dfn[t2]);  //一个环中增加一条边。
			cn ++;
	   }
	 }
	 if(low[n] == dfn[n])
	 {
  	   color ++;
  	   do
  	   {
	     t1 = ss.top();
	     ss.pop();
	     co[t1] = color;
	     sign[t1] = 2;
	   	}while(t1 != n);
	  }
	 w[n] = 1; //访问过
	 if(cn >= 2) dy = true;
}

void insert(int u,int v)  //单向边
{
	mat[em].v = v;
	mat[em].next = eda[u];
	eda[u] = em++;
}
void init(int n)
{
   int i;
   em = 0;
   for(i = 0;i <= n;i ++) sign[i] = 0,eda[i] = -1,w[i] = 0;
   index = 1;color = 0; 
}
int main()
{
	int t,i,j,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		init(n);
		while(1){
			scanf("%d%d",&a,&b);
			if(a == 0 && b == 0) break;
			if(a == b) continue;
			insert(a,b);
		}
		dy = false;
		for(i = 0;i < n;i ++)
		   if(!sign[i]) Tarjan(i);
		if(color > 1 || dy ) puts("NO");
       else puts("YES");
	
	}
	return 0;
}
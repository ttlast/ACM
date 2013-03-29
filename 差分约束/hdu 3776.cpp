#include <iostream>
using namespace std;
const int maxn = 400;
const int maxm = 100000;
int n,m,em;
char c[200];
struct Node
{
     int u,v,d;
};
Node mat[maxm];
int dis[maxn];
void add(int u,int v,int d)
{
     mat[em].u = u; mat[em].v = v;
     mat[em++].d = d;
}
bool BellmanFord()
{
     int i,j;bool sign;
	 for(i = 1;i <= n;i ++) dis[i] = 1;
     for(i = 1;i < n;i ++)
     {
        sign = true;
        for(j = 0;j < em;j ++)
          if(dis[mat[j].v] < dis[mat[j].u]+mat[j].d)
            dis[mat[j].v] = dis[mat[j].u]+mat[j].d,sign = false;
        if(sign) break;
     }
     for(j = 0;j < em;j ++)
        if(dis[mat[j].v] < dis[mat[j].u]+mat[j].d) return false;
     return true;
}
void chuli()
{
     int i,a = 0,b = 0,v = 0;
     bool in = false;
     for(i = 5;c[i] != '\0';i++)
     {
         if(c[i] <= '9' && c[i] >= '0') a = a*10 + c[i] - '0';
         else break;
     }
     for(;;i++)
       if((c[i] == 'a'&&c[i+1] == 't')||c[i] == 'w') break;
     if(c[i] == 'w') in = true;
     for(;;i++) if(c[i] <= '9' && c[i] >= '0') break;
     for(;;i++)
        if(c[i] <= '9' && c[i] >= '0') v = v*10+c[i]-'0';
        else break;
     for(;;i ++) if(c[i] <= '9' && c[i] >= '0') break;
     for(;c[i] != '\0';i ++) b = b*10+c[i]-'0';
     if(in) 
     {
      add(a,b,-v);
	  add(b,a,0);
     }else add(b,a,v);
}
int main()
{
    int t,i;
    while(scanf("%d",&n),n)
    {
    scanf("%d",&m);
    em = 0;
    gets(c);
	em = 0;
    for(i = 0;i < m;i ++)
    {
       gets(c);
       chuli();
    }
    if(BellmanFord())
    {
      for(i = 1;i <= n;i ++)
        if(i == 1)printf("%d",dis[i]);
		else printf(" %d",dis[i]);
	  puts("");
    }else puts("Impossible.");
    }
    return 0;
}

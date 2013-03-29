#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 1005;
//第一道dancing link，泪流满面。 
//knuth ，神呀。 好奇妙的想法。 
int n,m;
struct Node
{
   int l,r,u,d;  //标记上下左右。 
   int sum,x,y;  //x为行，y为列。 sum 记录每一列有多少1 
};
Node p[maxn*maxn];
int map[maxn][maxn],te[maxn];
int flag,top,stack[maxn];
int num(int x,int y)
{
    return x*1001+y;
}
void Clcol(int c)
{
     int i,j;
     p[p[c].r].l = p[c].l;
     p[p[c].l].r = p[c].r;
     i = c;
     for(i = p[c].d;i != c;i = p[i].d)
     {
         j = i;
         p[p[i].y].sum --;
         for(j = p[j].r;j != i;j = p[j].r)
         {
            p[p[j].d].u = p[j].u;
            p[p[j].u].d = p[j].d;
         }
     }
}
void Rbcol(int c)
{
     int i,j;
     p[p[c].r].l = c;
     p[p[c].l].r = c;
     i = c;
     for(i = p[c].u;i != c;i = p[i].u)
     {
         j = i;
         p[p[i].y].sum ++;
         for(j = p[j].l;j != i;j = p[j].l)
         {
            p[p[j].d].u = j;
            p[p[j].u].d = j;
         }
     }
}
bool dfs()
{
   int i,j,l,m;
   if(flag) return true;
   if(p[0].r == 0)
   {
      printf("%d",top);
      for(i = 0;i < top;i ++)
        printf(" %d",stack[i]);
      printf("\n");
      flag = 1;
      return true; 
   }
   int c = 0,Min = INT_MAX;
   for(i = p[0].r;i;i = p[i].r)
   {
      if(p[p[i].y].sum < Min)
      {
        Min = p[p[i].y].sum;
        c = i;
      }
   }
   Clcol(c);
   i = c;
   for(i = p[i].d;i != c;i = p[i].d)
   {
     stack[top++] = p[i].x;
     j = i;
     for(j = p[j].r;j != i;j = p[j].r)  //行中每一个1 
     {
       Clcol(p[j].y); 
     }
     if(dfs()) return true;
     j = i;
     for(j = p[j].l;j != i;j = p[j].l)
     {
       Rbcol(p[j].y);
     }
     top --;
   }
   Rbcol(c);
   return false; 
}
int main()
{
    int i,j,k;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(map,0,sizeof(map)); 
        for(i = 1;i <= n;i ++)  //处理行。 
        {
          scanf("%d",&k);
          for(j = 0;j < k;j ++)
          {
             scanf("%d",&te[j]);
             map[i][te[j]] = 1; 
          }
          int lf,rf;
          lf = num(i,te[0]); rf = num(i,te[k-1]);
          p[lf].l = rf; p[lf].x = i; p[lf].y = te[0];
          for(j = 1;j < k;j ++)
          {
              int cur = num(i,te[j]);
              p[num(i,te[j-1])].r = cur;
              p[cur].l = num(i,te[j-1]);
              p[cur].x = i;
              p[cur].y = te[j];
          }
          p[rf].r = lf;
        }
        p[0].r = 1;  //处理列。 
        for(i = 1;i <= m;i ++)
        {
          int No = i;
          if(i+1 <= m) p[No].r = i+1;
          else p[No].r = 0;
          p[No].l = i-1;
          p[No].x = 0;
          p[No].y = i;
          p[No].sum = 0;
          int last = No;
          for(j = 1;j <= n;j ++)
          {
              if(map[j][i] == 1)
              {
                p[last].sum ++;
                int cur = num(j,i);
                p[No].d = cur;
                p[cur].u = No;
                No = cur;
              }
          }
          p[No].d = i; //最尾标记. 
          p[i].u = No;
          if(!p[last].sum)
          {
            puts("NO\n");
            break;
          }
        }
        if(i == m+1)
        {
           flag = top = 0;
           dfs();
           if(!flag) puts("NO");
        }
    }
    return 0;
}

#include <iostream>
using namespace std;
const int maxn = 1005;
int num[maxn],n,m,d,sl;
int sign;
bool pm[maxn],noprim[10*maxn] = {0};
int len;
void init()
{
     int i,j;
     pm[0] = 2;len = 1;
     noprim[0] = noprim[1] = true;
     noprim[2] = false;
     for(i = 2;i < maxn*10;i += 2) noprim[i] = true;
     for(i = 3;i < maxn*10;i += 2)
     {
         if(!noprim[i])
         {
             for(j = i*i;j < maxn*10;j += i) noprim[j] = true;
         }
     }
}
bool check(int a,int b)
{
     int i,s = b,j;
     for(i = a-1,j = 1;i >= 0&&j < d;i --,j ++)
     {
         s += num[i];
         if(!noprim[s]) return false;
     }
     return true;
}
void dfs(int i)
{
    int j;
    if(i >= sl)
    {
       sign = 2;
       return ;
    }else
    {
       for(j = n;j <= m;j ++)
       {
          if(sign) return ;
          if((!pm[j])&&check(i,j))
          {
             pm[j] = true;num[i] = j;
             dfs(i+1);
             pm[j] = false;
          }
       }
    }
}
int main()
{
    int i,j;
    init();
    while(scanf("%d%d%d",&n,&m,&d),n)
    {
       sl = m-n+1;
       for(j = n;j <= m;j ++) pm[j] = false;
       sign = 0;
       dfs(0);
       if(sign == 2)
       {
          printf("%d",num[0]);
          for(i = 1;i < sl;i ++) printf(",%d",num[i]); printf("\n");
       }else puts("No anti-prime sequence exists.");
    }
    return 0;
}

#include <map>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 32;
int n,t,m;
struct Matrix
{
     int n,c[maxn][maxn];
};
Matrix multi(const Matrix & t1,const Matrix & t2)
{
     int i,j,k;
     Matrix t3;
     t3.n = t1.n;
     for(i = 0;i < t1.n;i ++)
      for(j = 0;j < t2.n;j ++)
      {
         t3.c[i][j] = 0;
         for(k = 0;k < t2.n;k ++)
          t3.c[i][j] = (t3.c[i][j]+t1.c[i][k]*t2.c[k][j])%m;
      }
     return t3;
}
Matrix Power(const Matrix & t1,int t)
{
     Matrix t2;
     if(t <= 1) return t1;
     t2 = Power(t1,t/2);
     if(t%2 == 0) return multi(t2,t2);
     else return multi(multi(t2,t2),t1);
}
Matrix add(const Matrix & t1,const Matrix & t2)
{
    int i,j;
    Matrix t3;
    for(i = 0;i < t1.n;i ++)
     for(j = 0;j < t2.n;j ++)
       t3.c[i][j] = (t1.c[i][j]+t2.c[i][j])%m;
    return t3;
}
Matrix Series(const Matrix & t1,int t)
{
     Matrix t3,t2,tp;
     if(t == 1) return t1;
     if(t%2 == 0)
     {
        t2 = Series(t1,t/2);
        tp = Power(t1,t/2);
        t3 = add(t2,multi(t2,tp));
     }else
     {
        t2 = Series(t1,t/2);
        tp = Power(t1,t/2);
        t3 = add(add(t2,multi(t2,tp)),Power(t1,t));
     }
     return t3;
}
int main()
{
    int i,j,k;
    Matrix t1,t2;
    while(scanf("%d%d%d",&t1.n,&t,&m)!=EOF)
    {
       n = t1.n;
       for(i = 0;i < n;i ++)
         for(j = 0;j < n;j ++)
           scanf("%d",&t1.c[i][j]);
       t2 = Series(t1,t);
       for(i = 0;i < n;i ++)
       {
         printf("%d",t2.c[i][0]);
         for(j = 1;j < n;j ++)
           printf(" %d",t2.c[i][j]);
         printf("\n");
       }
    }
    return 0;
}

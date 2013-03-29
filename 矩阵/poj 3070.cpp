#include <iostream>
using namespace std;
const int P = 10000;
const int maxn = 2;
int n;
struct Matrix
{
    int c[maxn][maxn];
};
Matrix t1;
Matrix multi(const Matrix & t1,const Matrix & t2)
{
    int i,j,k;
    Matrix t3;
    for(i = 0;i < maxn;i ++)
      for(j = 0;j < maxn;j ++)
      {
         t3.c[i][j] = 0;
         for(k = 0;k < maxn;k ++)
          t3.c[i][j] = (t3.c[i][j]+t1.c[i][k]*t2.c[k][j])%P;
      }
    return t3;
}
Matrix power(const Matrix & t1,int t)
{
    if(t <= 1) return t1;
    Matrix t2 = power(t1,t/2);
    if(t%2 == 0) return multi(t2,t2);
    else return multi(multi(t2,t2),t1);
}
int main()
{
    Matrix t2;
    t1.c[0][0] = t1.c[0][1] = t1.c[1][0] = 1;
    t1.c[1][1] = 0;
    while(scanf("%d",&n))
    {
     if(n == -1) break;
     if(n == 0) puts("0");
     else
     {
     t2 = power(t1,n);
     printf("%d\n",t2.c[0][1]);
     }
     }
    return 0;
}

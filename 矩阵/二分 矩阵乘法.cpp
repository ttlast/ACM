#include <iostream>
using namespace std;
const int p = 1000;
const int maxn = 30;
typedef int tydef;
struct Matrix
{
    int n,m;
    tydef c[maxn][maxn];
    friend Matrix multi(const  Matrix &t1,const Matrix &t2);
    friend Matrix power(const Matrix & t1,int t);
};
Matrix multi(const  Matrix &t1,const Matrix &t2)
{
    Matrix t3;
    t3.n = t1.n;t3.m = t2.m;
    int i,j,k;
    for(i = 0;i < t1.n;i ++)
      for(j = 0;j < t2.m;j ++)
      {
          t3.c[i][j] = 0;
          for(k = 0;k < t1.m;k ++)
            t3.c[i][j] += t1.c[i][k]*t2.c[k][j];
      }
    return t3;
}
Matrix power(const Matrix & t1,int t)
{
    Matrix t2;
    if(t <= 1) return t1;
    t2 = power(t1,t/2);
    if(t %2 == 0) return multi(t2,t2);
    else return multi(multi(t2,t2),t1);
}
int main()
{
    int i,j,b;
    Matrix t,t2;
    while(cin>>t.n>>t.m>>b)
    {
      for(i = 0;i < t.n;i ++)
        for(j = 0;j < t.m;j ++)
          cin>>t.c[i][j];
      t2 = power(t,b);
      for(i = 0;i < t.n;i ++)
      {
        for(j = 0;j < t.m;j ++)
          cout<<" "<<t2.c[i][j];
        cout<<endl;
      }
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 506;
int a[maxn][maxn];
int n;
int main()
{
    int max1,max2,max;
    int i,j;
    while(scanf("%d",&n)!=EOF)
    {
      max = 0;
      for(i = 1;i <= n;i ++)
      {
        for(j = i+1;j <= n;j ++)
        {
           scanf("%d",&a[i][j]);
           a[j][i] = a[i][j];
        }
        max1 = max2 = 0;
        for(j = 1;j <= n;j ++)
        {
           if(a[i][j] > max1) {max2 = max1;max1 = a[i][j];}
           else if(a[i][j] > max2) max2 = a[i][j];
        }
        if(max2 > max) max = max2;
      }
      printf("1\n%d\n",max);
    }
    return 0;
}

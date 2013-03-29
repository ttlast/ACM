#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 35;
int a[maxn][maxn];
int main()
{
    int n,i,j,ncase = 0;
    scanf("%d",&n);
    while(n--)
    {
       memset(a,0,sizeof(a));
       for(i = 0;i < 30;i ++)
           scanf("%d",&a[i][30]);
       
       
       ncase ++;
       printf("PUZZLE #%d\n",ncase);
       
    }
    return 0;
}

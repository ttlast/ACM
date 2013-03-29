#include <iostream>
using namespace std;
const int maxn = 205;
const int maxe = 25000;
int n,m,k;
struct Node { int v,d,next;};
Node mat[maxe];
int eda[maxn],em,scur,sink;
void add(int u,int v,int d)
{
     
}
int main()
{
    int t,i,a,b;
    scanf("%d",&t);
    while(t--)
    {
      scanf("%d%d%d",&n,&m,&k);
      for(i = 0;i < m;i ++)
      {
         scanf("%d%d",&a,&b);
         b += n;
      }
    }
    return 0;
}

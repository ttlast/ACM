#include <iostream>
#include <queue>
using namespace std;
const int maxn = 11000;
bool noprim[maxn] = {0};
int step[maxn];
int bas[4] = {1,10,100,1000};
void init()
{
    int i,j;
    for(i = 4;i < maxn;i += 2) noprim[i] = true;
    for(i = 3;i < maxn;i += 2)
       {
           if(!noprim[i])
           {
             for(j = i*i;j < maxn;j += i) noprim[j] = true;
           }
        }
}
int main()
{
    int t,i,j,a,b,sur,sur2,s;
    int d[4];
    init();
    queue<int> q;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d%d",&a,&b);
       while(!q.empty()) q.pop();
       q.push(a);
       memset(step,0,sizeof(step));
       while(!q.empty())
       {
          sur = q.front(); q.pop();
          if(sur == b)
          {
            s = step[sur];break;
          }
          d[0] = sur%10;  d[1] = (sur%100)/10;
          d[2] = (sur%1000)/100; d[3] = sur/1000;
          for(i = 0;i < 3;i ++)
          {
             for(j = 0;j <= 9;j ++)
             {
                if(j == d[i]) continue;
                sur2 = sur - d[i]*bas[i]+j*bas[i];
                if((!noprim[sur2])&&(!step[sur2]))
                {
                step[sur2] = step[sur]+1;
                q.push(sur2);
                }
             }
          }
          for(j = 1;j <= 9;j ++)
          {
             if(j == d[4]) continue;
             sur2 = sur%1000+j*1000;
             if((!noprim[sur2])&&(!step[sur2]))
             {
                step[sur2] = step[sur]+1;
                q.push(sur2);
             }
          }
       }
       printf("%d\n",s);
    }
    return 0;
}

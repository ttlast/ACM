#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int num[1005],dp[1005],n;
int df(int k)
{
  int i,j,te;
  memset(dp,0,sizeof(dp));
  for(i = j = 0;i < n;i ++)
  {
     te = dp[j] + num[i];
     if(te <= k) dp[j] = te;
     else
     {
           te = te - k;
           dp[j] = k;
           j ++;
           dp[j] = te;
     }
  }
  if(j <= 2) return 1;
  return 0;
}
bool comp(const int &t1,const int & t2)
{
      return t1 > t2;
}
int main()
{
     int t,i,ncase;
    int ma,sum,l,r,mid;
     while(scanf("%d",&n)!=EOF)
     {
      memset(dp,0,sizeof(dp));
      for(i = l = 0,sum = 0;i < n;i ++)
      {
        scanf("%d",&num[i]);
        sum += num[i];
        if(num[i] > l) l = num[i];
      }
     sort(num,num+n,comp);
     r = sum;
     while(l <= r)
     {
        mid = (l+r)>>1;
        if(df(mid))
        {
           ma = mid;
           r = mid -1;
           }else l = mid + 1;
     }
     printf("%d %d\n",ma,sum);
    }
     return 0;
}


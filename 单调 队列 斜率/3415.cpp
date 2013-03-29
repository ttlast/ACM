//单调队列。 
#include<iostream>
#include<deque>
using namespace std;
int a[100003];
int sum[200009];
deque<int> Q;
int main()
{
     int n,i,t,k,temp,ans,s,e;
    scanf("%d",&t);
    while(t--)
    {
      sum[0]=0;Q.clear();
      ans=-999999999;
      scanf("%d%d",&n,&k);
      temp=n+k;
      for(i=1;i<=n;i++) scanf("%d",&a[i]);
      for(i=1;i<=n;i++)  sum[i]=sum[i-1]+a[i];
      for(i=n+1;i<temp;i++) sum[i]=sum[i-1]+a[i-n];

      for(i=1;i<temp;i++)
      {
        while(!Q.empty()&&sum[Q.back()]>=sum[i-1]) Q.pop_back();
        Q.push_back(i-1);
        
        while(!Q.empty()&&i-Q.front()>k) Q.pop_front();
        
        if(sum[i]-sum[Q.front()]>ans)
        {
            ans=sum[i]-sum[Q.front()];
            s=Q.front()+1;
            e=i;
        }
      }
      if(e>n) e-=n;
      printf("%d %d %d\n",ans,s,e);
     } 
     return 0;
}

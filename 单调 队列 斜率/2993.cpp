#include <iostream>
using namespace std;
int n,m,a[100005],s[100005];
double x1,y1,x2,y2,ans;
int main()
{
    int i,j,t1,t2,head,tail;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
       for(i = 1;i <= n;i ++)
       {
          scanf("%d",&a[i]);
          a[i] += a[i-1];
       }
       head = tail = 0;
       s[0] = 0; //标记下标 
       for(ans = 0,i = m;i <= n;i ++)
       {
          while(head < tail)  //去掉集合中的上凸点。 
          {
            t1 = s[tail-1];t2 = s[tail];
            y1 = (a[t2] - a[t1]);
            y2 = (a[i-m] - a[t2]);
            if(y1*(i-m-t2) <= y2*(t2-t1)) break;;
            tail --;
          }
          s[++tail] = i-m;
          while(head < tail) //查找集合中的下凸点。 
          {
             t1 = s[head];t2 = s[head+1];
             y1 = (a[i] - a[t1]);
             y2 = (a[i] - a[t2]);
             if(y1*(i-t2) > y2*(i-t1)) break;
             head ++;
          }
          y1 = (double)(a[i] - a[s[head]])/(i - s[head]);
          if(y1 > ans) ans = y1;
       }
       printf("%.2lf\n",ans); 
    }
    return 0;
}

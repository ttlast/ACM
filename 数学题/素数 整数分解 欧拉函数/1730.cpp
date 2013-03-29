#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxn = 65540;
int gcd(int a,int b)
{
    if(a%b == 0) return b;
    return gcd(b,a%b);
}
bool noprim[maxn] = {0};
int num[6600],len;
int mat[1000],ml;
void init()
{
     int i,j;
     num[0] = 2;len = 1;
     for(i = 2;i < maxn;i += 2) noprim[i] = true;
     for(i = 3;i < maxn;i += 2)
     {
          if(!noprim[i])
          {
              for(j = i*2;j < maxn;j += i) noprim[j] = true;
              num[len] = i;len ++;
          }
     }
}
void check(long long x)
{
     ml = 0;
     int s,a,b,i;
     if(x > 0)
     {
     for(i = 0;i < len&&x > num[i];i ++)
     {
       if(x%num[i] == 0)
       {
          s = 0;
          while(x%num[i] == 0&&x>0)
          {
             s ++; x /= num[i];
          }
          mat[ml++] = s;
       }
     }
     if(x != 1) printf("1\n");
     else
     {
         if(ml <= 1) printf("%d\n",mat[0]);
         else
         {
             a = mat[0];
             for(i = 1;i < ml;i ++)
                a = gcd(a,mat[i]);
             printf("%d\n",a);
         }
     }

     }else
     {
     x = -x;
     for(i = 0;i < len&&x > num[i];i ++)
     {
       if(x%num[i] == 0)
       {
          s = 0;
          while(x%num[i] == 0&&x>0)
          {
             s ++; x /= num[i];
          }
          mat[ml++] = s;
       }
     }
     if(x != 1) printf("1\n");
     else
     {
         if(ml <= 1)
         {
              while(mat[0]%2 == 0) mat[0] /= 2;
              printf("%d\n",mat[0]);
         }
         else
         {
             a = mat[0];
             for(i = 1;i < ml;i ++)
                a = gcd(a,mat[i]);
             while(a%2 == 0) a /= 2;
             printf("%d\n",a);
         }
     }
     }
}
int main()
{
    init();
    long long x;
    while(scanf("%lld",&x),x)
    {
       check(x);
    }
    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;
typedef unsigned __int64 u64;
//typedef unsigned long long u64;
//__int64 %I64d long long %lld  unsignde long long %llu
const int maxn = 46400;
bool noprim[maxn] = {0},sign[1000005];
int prim[4800],len;
void init()
{
     int i,j;
     prim[0] = 2;len = 1;
     for(i = 4;i < maxn;i += 2) noprim[i] = true;
     for(i = 3;i < maxn;i += 2)
     {
           if(!noprim[i])
           {
              for(j = i*2;j < maxn;j += i) noprim[j] = true;
              prim[len] = i;len ++;
           }
     }
}
int main()
{
     u64 a,b,i,m,k,prev,mind,maxd,d[4];
     init();
     while(scanf("%I64d%I64d",&a,&b)!=EOF)
     {
         for(i = a;i <= b;i ++) sign[i-a] = true;
         m = sqrt(b*1.0);
         for(i = 0;prim[i] <= m;i ++)
         {
            k = a%prim[i];
            if(k == 0) k = prim[i];
            for(k = prim[i]-k;k+a <= b;k += prim[i])
            {
                if(a+k == prim[i]) continue;
                sign[k] = false;
            }
         }
         m = a;mind = 1000000000;maxd = 0;
         if(a <= 2) a = 3,prev = 2;
         else prev = 0;
		 if(a&1) i = a;
		 else i = a+1;
		 for(;i <= b;i += 2)
            if(sign[i-m])
            {
                if(prev)
                {
                  if(i - prev > maxd)
                  {
                     maxd = i - prev;
                     d[0] = prev,d[1] = i;
                  }
                  if(i -prev < mind)
                  {
                     mind = i - prev;
                     d[2] = prev,d[3] = i;
                  }
				  
                }
				prev = i;
            }
         if(maxd)
         {
           printf("%I64d,%I64d are closest, %I64d,%I64d are most distant.\n",d[2],d[3],d[0],d[1]);
         }else puts("There are no adjacent primes.");
     }
     return 0;
}

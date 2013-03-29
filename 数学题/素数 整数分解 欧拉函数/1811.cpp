#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;
typedef unsigned __int64 u64;
const int Max_k = 13;
u64 random()
{
    u64 a;
    a = rand(); a *= rand();
    a *= rand(); a *= rand();
    return a;
}
int pri[13] = {2,3,5,7,11,13,17,19,23,29,31,37,41};
u64  Mulit_mod(u64 a,u64 b,u64 n)
{
     u64 cnt = 0,temp = a;
     while(b)
     {
         if(b&1) cnt = cnt+temp;
         if(cnt > n) cnt -= n;
         temp <<= 1; if(temp > n) temp -= n;
         b >>= 1;
     }
     return cnt;
}
u64 Pow_mod(u64 a,u64 b,u64 n)
{
    u64 cnt = 1,temp = a;
    while(b)
    {
         if(b&1) cnt = Mulit_mod(cnt,temp,n);
         temp = Mulit_mod(temp,temp,n);
         b >>= 1;
    }
    return cnt;
}
bool Miller_Rabin(u64 n)
{
     int i,j;
     u64 p = n-1,m = 0,a,d;
     if(n < 2) return false;
     if(n == 2) return true;
     if(!(n&1)) return false;
     while(!(p&1)) p >>= 1,m ++;
     for(i = 0;i < Max_k;i ++)
     {
        //a = random()%(n-1)+1;
        if(pri[i] >= n) return true;
        a = Pow_mod(pri[i],p,n);
        if(a == 1) continue;
        for(j = 0;j < m;j ++)
        {
              d = Mulit_mod(a,a,n);
              if(d == 1 && a != 1 && a != n-1) return false;
              a = d;
        }
        if(d != 1) return false;
     }
     return true;
}
int count_factors = 0;
u64 all_factors[100];
u64 gcd(u64 a,u64 b)
{
    if(b == 0) return a;
    return gcd(b,a%b);
}
u64 Pollard_Rho(u64 n,int k)
{
    u64 d;
    u64 x = random()%(n-1)+1;
    u64 y = x,t = 2;
    int i = 1;
    while(1)
    {
        i ++;
        x = (Mulit_mod(x+1,x-1,n)+k)%n;
        d = gcd(y-x,n);
        if(d > 1 && d < n) return d;
        if(x == y) return n;
        if(t == i) y = x,t <<= 1;
    }
}
void Find_All_Factor(u64 n)
{
     if(Miller_Rabin(n))
     {
        all_factors[count_factors++] = n;
     }else{
        u64 factor = n,k = 10;
        while(factor >= n)
          factor = Pollard_Rho(n,k --);
        Find_All_Factor(factor);
        Find_All_Factor(n/factor);
     }
}
u64 Min_Factor(u64 n)
{
     int k;
     count_factors = 0;
	 Find_All_Factor(n);
     u64 mind = all_factors[0];
     for(k = 1;k < count_factors; k ++)
       if(mind > all_factors[k]) mind = all_factors[k];
     return mind;
}
int main()
{
    u64 n;
    int t;
    srand((unsigned) time(NULL));
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d",&n);
        if(Miller_Rabin(n)) puts("Prime");
        else
        {
           n = Min_Factor(n);
		   printf("%I64d\n",n);
        }
    }
    return 0;
}

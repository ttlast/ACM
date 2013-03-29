#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef unsigned long long u64;
const int PN = 18;  //用素数概论更大，可以更改，去掉下面数组。 
int prim[PN] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};
u64 random()
{
    //main srand((unsigned)time(NULL));
    u64 a;
    a = rand(); a *= rand();
    a *= rand(); a *= rand();
    return a;
}
u64 Mulit_mod(u64 a,u64 b,u64 n)
{
    u64 ret = 0,temp = a%n;
    while(b)
    {
       if(b&1) ret = ret + temp; 
       if(ret > n) ret -= n;
       temp <<= 1; if(temp > n) temp-= n;
       b >>= 1;
    }
    return ret;
}
u64 Pow_mod(u64 a,u64 b,u64 n)
{
    u64 ret = 1,temp = a%n;
    while(b)
    {
       if(b&1) ret = Mulit_mod(ret,temp,n);
       temp = Mulit_mod(temp,temp,n);
       b >>= 1;
    }
    return ret;
}
bool Miller_Rabin(u64 n)
{
    if(n < 2) return false;
    if(n == 2) return true;
    if(!(n&1)) return false;
    u64 a,p = n-1,d;
    int i,j,m = 0;
    while(!(p&1)) p >>= 1,m ++;
    for(i = 0;i < PN;i ++)
    {
       //a = random()%(n-1)+1; 
       if(prim[i] >= n) return true;
       a = Pow_mod(prim[i],p,n);
       if(a == 1) continue;
       for(j = 0;j < m;j ++)
       {
           d = Mulit_mod(a,a,n);
           if(d == 1 && a != 1 && a != (n-1)) return false;
           a = d;
       }
       if(d != 1) return false;
    }
    return true;
}
//Pollard_Rho分解质因子
int count_factors = 0;  //请初始化 
u64 all_factors[100];
u64 gcd(u64 a,u64 b)
{
    if(b == 0) return a;
    return gcd(b,a%b);
}
u64 Pollard_Rho(u64 n,u64 k)
{
    u64 x = random()%(n-1)+1; 
    u64 y = x,d,t = 2;
    int i = 1;
    while(1)
    {
        i ++;
        x = (Mulit_mod(x+1,x-1,n)+k)%(n-1)+1;
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
     }else
     {
         u64 factor = n,k = 100;
         while(factor >= n) factor = Pollard_Rho(n,k--);
         Find_All_Factor(factor);
         Find_All_Factor(n/factor);
     }      
}
u64 num[100];
int np[100],nlen;
u64 maxsum,bestnum;
void dfs(int k,u64 ans,u64 n)
{
     u64 temp;
	 if(ans > n/ans) return ;
	 if(ans + n/ans < maxsum) bestnum = ans,maxsum = ans + n/ans;
     if(k > nlen) return ;
     temp = Pow_mod(num[k],np[k],n);
     dfs(k+1,ans,n);
     dfs(k+1,ans*temp,n);
}
int main()
{
    srand((unsigned)time(NULL));
    int i; 
    u64 a,b,c;
    while(scanf("%llu%llu",&a,&b)!=EOF)
    {
       c = b/a;
       if(Miller_Rabin(c)||c < 2)
       {
           printf("%llu %llu\n",a,b);
       }else
       {
           count_factors = 0;
           Find_All_Factor(c);
           sort(all_factors,all_factors+count_factors);
           num[0] = all_factors[0]; nlen = 0;np[0] = 1;
           for(i = 1;i < count_factors;i ++) 
               if(all_factors[i] == num[nlen])   np[nlen] ++;
               else
               {
                   nlen ++;
                   num[nlen] = all_factors[i];
                   np[nlen] = 1;
               }
           maxsum = b;bestnum = 1;
           dfs(0,1,c);
           if(bestnum < 1) bestnum = 1;
           printf("%llu %llu\n",a*bestnum,b/bestnum);
       }
    }
    return 0;
} 

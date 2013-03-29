#include <iostream>
#include <cstdio>
using namespace std;
typedef long long u64;
int prim[14] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43};
u64 maxsum,bestnum,n;
void make(u64 num,u64 k,u64 sum,int limit)
{
    int i;u64 temp;
    if(sum > maxsum)
    {
        maxsum = sum;bestnum = num;
    }
	if(sum == maxsum && bestnum > num) bestnum = num;
    if(k >= 14) return ;
    temp = num;
    for(i = 1;i <= limit;i ++)
    {
        if(temp*prim[k] > n) break;
        temp *= prim[k];
        make(temp,k+1,sum*(i+1),i);
    }
}
int main()
{
    int i;
    while(scanf("%lld",&n)!=EOF)
    {
       maxsum = 0;
       make(1,0,1,54);
       printf("%lld\n",bestnum);
    }
    return 0;
}

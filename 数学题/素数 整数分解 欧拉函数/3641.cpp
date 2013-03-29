#include <iostream>
using namespace std;
const int maxn = 31640;
bool noprim[maxn]={0};
int num[3500],len;
void init()
{
	int i,j;
	num[0] = 2;len = 1;
	for(i = 4;i < maxn;i += 2) noprim[i] = true;
	for(i = 3;i < maxn;i += 2)
	{
		if(!noprim[i])
		{
			for(j = i*2;j < maxn;j += i) noprim[j] = true;
			num[len] = i;len ++;
		}
	}
}
bool check(int p)
{
	int i;
	for(i = 0;i < len&&num[i] < p;i ++)
		if(p%num[i] == 0) return true;
	return false;
}
int main()
{
    long long p,a,s1,s2,s;
	init();
    while(scanf("%lld%lld",&p,&a))
    {
       if(p == 0 && a == 0) break;
       s1 = p;s2 = a;s = 1;
       while(s1)
       {
           if(s1&1) s = (s*s2)%p;
           s2 = (s2*s2)%p;
           s1 >>= 1;
       }
	   if(check(p))
	   {
	   s = s%p;
       if(s == a) printf("yes\n");
       else printf("no\n");
	   }else printf("no\n");
    }
    return 0;
}

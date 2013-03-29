#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 200;
int n;
bool sign[maxn];
int a[maxn],al,b[maxn],num,best[maxn],bl,ans,mul;
void init()
{
     int i,j;
     b[num++] = 2;
     for(i = 2;i < maxn;i += 2) sign[i] = true;
     for(i = 3;i < maxn;i ++)
     {
        if(!sign[i])
        {
            b[num++] = i;
            for(j = i*i;j < maxn;j += i)
               sign[j] = true;
        }
     }
}
void dfs(int sum,int i)
{
     int j;
	 if(sum < b[i])
	 {
		 if(mul > ans)
		 {
			 ans = mul;
			 for(j = 0;j < al;j ++) best[j] = a[j];
			 bl = al;
			 while(sum > 0)
			 {
				 best[bl++] = 1;
				 sum --;
			 }
		 }
	 }else
	 {
		 dfs(sum,i+1);
		 for(j = b[i];j <= sum;j *= b[i])
		 {
			 a[al++] = j;
		     mul *= j;
			 dfs(sum - j,i+1);
			 al --;
		     mul /= j;
		 }
	 }
}
int main()
{
    int t,i,j,l;
    init();
    scanf("%d",&t);
    while(t--)
    {
        al = bl = 0;
        ans = 0;mul = 1;
        scanf("%d",&n);
        if(n == 1) puts("1 1");
        else
        {
        dfs(n,0);
        printf("%d",ans);
        sort(best,best+bl);
        for(i = 0,j = 1;i < bl;i ++)
        {
           for(l = j+1;l < j+best[i];l ++) printf(" %d",l);
           printf(" %d",j);
           j += best[i];
        }
        printf("\n");
        }
    }
}

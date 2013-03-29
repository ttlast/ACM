#include <iostream>
using namespace std;
const int maxn = 1050;
bool noprim[maxn] = {0};
int num[200],len;
int n,c;
void init()
{
     int i,j;
     num[0] = 1;num[1] = 2;len = 2;
     for(i = 2;i < maxn;i += 2) noprim[i] = true;
     for(i = 3;i < maxn;i += 2)
     {
         if(!noprim[i])
         {
            for(j = i*i;j < maxn;j += i) noprim[j] = true;
            num[len] = i;len ++;
         }
     }
}
int main()
{
    int n,c,l,r,mid,s,i,j;
    init();
    while(scanf("%d%d",&n,&c)!=EOF)
    {
        l = 0;r = len-1;
        while(l <= r)
        {
           mid = (l+r)>>1;
           if(num[mid] >= n)
           {
               s = mid;
               r = mid -1;
           }else l = mid +1;
        }
        if(num[mid] > n) mid --;
        printf("%d %d:",n,c);
        if(mid%2 == 0)
        {
            j = mid/2-c+1;
            if(j < 0) j = 0;
            for(;j < mid/2+c&&j <= mid;j ++) printf(" %d",num[j]);
            printf("\n\n");
        }else
        {
            j = mid/2-c+1;
            if(j < 0) j = 0;
            for(;j <= mid/2+c&&j <= mid;j ++) printf(" %d",num[j]);
            printf("\n\n");
        }
    }
    return 0;
}

#include <iostream>
using namespace std;
const int maxn = 30;
bool sign[maxn];
int n,a[maxn],num[maxn];
char c[maxn];
int main()
{
    int i,j,b;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",c);
        for(i = 0;i < 26;i ++)
           a[i] = c[i] - 'A',sign[i] = false,num[i] = 0;
        num[26] = 0;
        for(i = 0;i < 26;i ++)
        {
           if(!sign[i])
           {
               j = i;
               b  = 0;
               do{
                  sign[j] = true;
                  b ++;
                  j = a[j];
               }while(j != i);
               num[b] ++;
           }
        }
        for(i = 2;i <= 26;i +=2)  
            if(num[i]%2) break;
        if(i <= 26) puts("No");
        else puts("Yes");
    }
    return 0;
}

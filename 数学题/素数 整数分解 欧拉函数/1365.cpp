#include <iostream>
using namespace std;
const int maxn = 32800;
char c[100];
bool prim[maxn];
int num[maxn],len;
int fx[maxn];
void init()
{
    int i,j;
    num[0] = 2;num[1] = 3;len = 2;
    for(i =  2;i < maxn;i += 2) prim[i] = true;
    for(i = 3;i < maxn;i += 2)
       {
           if(!prim[i])
           {
               for(j = i*i;j < maxn;j += i) prim[j] = true;
               num[len] = i;
               len ++;
           }
         }
}
int Power(int a,int b)
{
    int s = 1;
    while(b > 0)
    {
       if(b&1) s *= a;
       a = a*a;  //好久没写代码，写错了这里 
       b >>= 1;
    }
    return s;
}
int main()
{
    init();
    int sum,l,i,j,p,e,sign;
    while(gets(c))
    {
        if(c[0] == '0') break;
        l = strlen(c);
        sum = 1;
        for(i = 0;i < l;)
        {
           p = 0;
           while(c[i] == ' ') i ++;
           while(c[i]>='0'&&c[i]<='9')
           {
              p = p*10+c[i]-'0';
              i ++;
           }
           while(c[i] == ' ') i ++;
           e = 0;
           while(c[i]>='0'&&c[i]<='9')
           {
              e = e*10+c[i]-'0';
              i ++;
           }
           sum = sum*Power(p,e);
        }
        sum --;
        p = 0;
        while(sum >= num[p]&&p < len)
        {
             if(sum%num[p] == 0)
             {
                e = 0;
                while(sum%num[p] == 0&&sum > 0)
                {
                   sum /= num[p];
                   e ++;
                }
                fx[p] = e;
             }else fx[p] = 0;
             p ++;
        }
        sign = 1;
        if(p >= len) printf("%d %d",sum,1),sign = 0;
        for(i = p-1;i >= 0;i --)
         if(fx[i] != 0&&sign) printf("%d %d",num[i],fx[i]),sign=0;
         else if(fx[i] != 0) printf(" %d %d",num[i],fx[i]);
        printf("\n");
    }
    return 0;
}


#include<iostream>
#include<cstdio>
using namespace std;

int prime[50000];
int m;

__int64 gcd(__int64 x , __int64 y)
{
    if(y == 0) return x;
    else return gcd(y , x % y);
}

void getprime()
{
    m = 1;
    prime[0] = 2;
    int i , j;
    for(i = 3;i <= 200000;i = i + 2)
    {
        for(j = 0;prime[j] * prime[j] <= i;j++)
            if(i % prime[j] == 0) break;
        if(i % prime[j] != 0) prime[m++] = i; 
    }
}

int num[5000];int p;

void di(__int64 x , __int64 y)
{
    int i;
    p = 0;
    for(i = 0;prime[i] * prime[i] <= x || prime[i] * prime[i] <= y;i++)
    {
        if(x % prime[i] == 0 && y % prime[i] == 0)
        {
            while(x % prime[i] == 0)
                x /= prime[i];
            while(y % prime[i] == 0)
                y /= prime[i];
            num[p++] = prime[i];
        }
        else if(x % prime[i] == 0)
        {
            while(x % prime[i] == 0)
                x /= prime[i];
            num[p++] = prime[i];
        }
        else if(y % prime[i] == 0)
        {
            while(y % prime[i] == 0)
                y /= prime[i];
            num[p++] = prime[i];
        }
    }
    if(x != 1 && x == y) num[p++] = x;
    else if(x != 1 && y != 1) {num[p++] = x;num[p++] = y;}
    else if(x != 1) num[p++] = x;
    else if(y != 1) num[p++] = y;
}

struct data 
{
    int ceng;
    __int64 num;
}a[1000000];int top = 0;

void build()
{
    top = 1;
    a[0].ceng = 0;
    a[0].num = 1;
    int i , j;
    for(i = 0;i < p;i++)  //2^p个数 
    {
        int temp = top;
        for(j = 0;j < temp;j++)
        {
            a[top].ceng = a[j].ceng + 1;
            a[top].num = a[j].num * num[i];
            top++;
        }
    }
}

__int64 geshu(__int64 x)
{
    __int64 ret = 0;
    for(int i = 0;i < top;i++)
    {
        if(a[i].ceng % 2 == 0) ret += x / a[i].num;
        else ret -= x / a[i].num;
    }
    return ret;
}

__int64 binary(__int64 x , __int64 y , __int64 k)
{
    di(x , y);
    build();
    __int64 left = 0;__int64 right = 10000000000;
    while(right - left > 1)  //二分 + 容斥 
    {
        __int64 temp = (left + right) / 2;
        __int64 ret = geshu(temp);
//        printf("%I64d %I64d\n" , temp , ret);
        if(ret < k) left = temp;
        else right = temp;
    }
    return right;
}

int main()
{
    getprime();
    int t;
    scanf("%d" , &t);
    for(int i = 1;i <= t;i++)
    {
        __int64 x , y , k;
        scanf("%I64d%I64d%I64d" , &x , &y , &k);
        printf("Case %d: %I64d\n" ,  i , binary(x , y , k));
    }
    return 0;
}

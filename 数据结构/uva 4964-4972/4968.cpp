#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    long long sum,y,g,t,k,l,a,d;
    while(scanf("%lld%lld%lld%lld",&g,&t,&a,&d),g+1||t+1||a+1||d+1){
        sum=t*(t-1)/2*g;
        k=g*a+d-1;
        for(l=0;k;k/=2,l++);
        y=(1LL<<l)-g*a-d;
        sum+=(1LL<<l)-1;
        printf("%lld*%lld/%lld+%lld=%lld+%lld\n",g,a,t,d,sum,y);
    }
    return 0;
}
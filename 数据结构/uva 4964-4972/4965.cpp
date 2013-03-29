#include <iostream>
#include <stdio.h>
using namespace std;
int type[1000],Anum[10000],Bnum[10000];
int calc(int x){
    int y;
    for(y=0;x;x/=10){
        y+=(x%10)*(x%10);
    }
    return y;
}
int check(int i){
    if(i==1||i==4||i==16||i==37||i==58||i==89||i==145||i==42||i==20){
        return 1;    
    }
    else return 0;
}
int main(){
    int u,v,Acnt,Bcnt,delt,ans,t,p,q;
    type[1]=-1,type[4]=0,type[16]=1,type[37]=2,type[58]=3,type[89]=4,type[145]=5,type[42]=6,type[20]=7;
    while(scanf("%d%d",&u,&v),u||v){
        p=u,q=v;
        for(Acnt=0;;){
            Anum[Acnt++]=u;
            if(check(u)) break;
            t=calc(u);
            u=t;
        }
        for(Bcnt=0;;){
            Bnum[Bcnt++]=v;
            if(check(v)) break;
            t=calc(v);
            v=t;
        }
        if(type[Anum[Acnt-1]]==-1&&type[Bnum[Bcnt-1]]==-1){
            while(Acnt-1&&Bcnt-1&&Anum[Acnt-2]==Bnum[Bcnt-2]) Acnt--,Bcnt--;
            ans=Acnt+Bcnt;
        }else if(type[Anum[Acnt-1]]+1&&type[Bnum[Bcnt-1]]+1){
            delt=type[Anum[Acnt-1]]-type[Bnum[Bcnt-1]];
            if(delt<0) delt+=8;
            if(delt>4) delt=8-delt;
            while(Acnt-1&&Bcnt-1&&Anum[Acnt-2]==Bnum[Bcnt-2]) Acnt--,Bcnt--;
            ans=Acnt+Bcnt+delt;
        }else{
            ans=0;
        }
        printf("%d %d %d\n",p,q,ans);
    }
    return 0;
}
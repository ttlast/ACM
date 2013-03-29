#include <iostream>
#include <stdio.h>
using namespace std;
char key[40000];

bool get(int &i,int x){
	bool ans=x;
	for(++i;key[i];i++){
		if(key[i]==')'){
			return ans;
		}else if(key[i]=='F'){
			if(x)ans&=0;
			else ans|=0;
		}else if(key[i]=='T'){
			if(x)ans&=1;
			else ans|=1;
		}else if(key[i]=='('){
			if(x)ans&=get(i,x^1);
			else ans|=get(i,x^1);
		}else{
			while(1)puts("kero");
		}
	}
}
int main(){
    int i,tem,dep,T=0;
    while(scanf("%s",key)){
    	tem=dep=0;
    	for(i=0;key[i];i++){
			if(key[i]=='('){
				tem++;
				dep=max(dep,tem);
			}else if(key[i]==')')
				tem--;
		}
		if(dep==1 && i==2)break;
		i=0;
		printf("%d. %s\n",++T,get(i,dep%2)?"true":"false");
    }
    return 0;
}
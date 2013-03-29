#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char str[100],ans[100];
int eye[100],key[100],c[100];
void mul(int a[],int b[], int n){int i;
	for(i=0;i<n;i++)
		c[i]=a[b[i]];
	for(i=0;i<n;i++)a[i]=c[i];
}
int main(){
    int i,tem,dep,T=0,j,k,m;
    while(scanf("%d",&m),m){
    	scanf("%s",str);
    	int n=strlen(str);
    	for(i=0;i<n;i++)key[i]=i;
    	for(i=0;i<n;i++){
			for(j=0;j<n;j++)if(key[j]==i)break;
			for(k=0;k<i+1;k++){
				if(j!=n-1){
					swap(key[j],key[j+1]);
					j++;
				}else{
					for(int ii=n-1;ii>0;ii--)
						key[ii]=key[ii-1];
					key[0]=i;j=0;
				}
			}
		}
		//puts("$$");
		int tt=m/n;
		for(i=0;i<n;i++)eye[i]=i;
		while(tt){
			if(tt&1)mul(eye,key,n);
			mul(key,key,n);
			tt/=2;
		}
		//puts("$$");
		for(i=0;i<n;i++)ans[i]=str[eye[i]];
		tt=m%n;
		
		for(i=0;i<n;i++)key[i]=i;
    	for(i=0;i<tt;i++){
    		
			for(j=0;j<n;j++)if(key[j]==i)break;
			for(k=0;k<i+1;k++){
				if(j!=n-1){
					swap(key[j],key[j+1]);
					j++;
				}else{
					for(int ii=n-1;ii>0;ii--)
						key[ii]=key[ii-1];
					key[0]=i;j=0;
				}
			}
		}//puts("$$");
		for(i=0;i<n;i++)str[i]=ans[key[i]];
		printf("%d. %s\n",++T,str);
    }
    return 0;
}
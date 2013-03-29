#include <iostream>
#include <cstdio>
#include <cstdlib>
#include<vector>
#include <cstring>
#include<queue>
using namespace std;
typedef long long ll;
const ll inf = 0x3ffffffffffffff;

int key[1000100][5],mark[1000100][5];
ll dp[1000100][5];

ll getdp(int x,int y){
	if(mark[x][y]!=0)return dp[x][y];
	mark[x][y]=1;
	if(x==0){
		if(y==0)return dp[x][y]=inf;
		if(y==1)return dp[x][y]=key[x][y];
		if(y==2)return dp[x][y]=key[x][y]+key[x][y-1];
	}
	ll temp=inf;
	if(y==0){
		temp = min(temp,getdp(x-1,0));
		temp = min(temp,getdp(x-1,1));
	}else if(y==1){
		temp = min(temp,getdp(x-1,0));
		temp = min(temp,getdp(x-1,1));
		temp = min(temp,getdp(x-1,2));
		temp = min(temp,getdp(x,0));
	}else{
		temp = min(temp,getdp(x-1,2));
		temp = min(temp,getdp(x-1,1));
		temp = min(temp,getdp(x,1));
	}
	return dp[x][y]=temp+key[x][y];
}

int main(){
	int n,i,j,T=0;
	while(scanf("%d",&n),n){
		for(i=0;i<n;i++)for(j=0;j<3;j++)
			scanf("%d",&key[i][j]);
		for(i=0;i<n;i++)for(j=0;j<3;j++)
			dp[i][j]=inf;
		dp[0][1]=key[0][1];
		for(i=0;i<n;i++)for(j=0;j<3;j++)
			if(dp[i][j]!=inf){
				if(j==0){
					dp[i][1]=min(dp[i][1],dp[i][0]+key[i][1]);
					dp[i+1][1]=min(dp[i+1][1],dp[i][0]+key[i+1][1]);
					dp[i+1][0]=min(dp[i+1][0],dp[i][0]+key[i+1][0]);
				}else if(j==1){
					dp[i][2]=min(dp[i][2],dp[i][1]+key[i][2]);
					dp[i+1][1]=min(dp[i+1][1],dp[i][1]+key[i+1][1]);
					dp[i+1][0]=min(dp[i+1][0],dp[i][1]+key[i+1][0]);
					dp[i+1][2]=min(dp[i+1][2],dp[i][1]+key[i+1][2]);
				}else{
					dp[i+1][1]=min(dp[i+1][1],dp[i][2]+key[i+1][1]);
					dp[i+1][2]=min(dp[i+1][2],dp[i][2]+key[i+1][2]);
				}
			}
		printf("%d. %lld\n",++T,dp[n-1][1]);
	}
}
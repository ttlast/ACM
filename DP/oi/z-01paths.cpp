//http://z-trening.com/tasks.php?show_task=5000000355
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 10000000;
const int maxn = 90;
typedef __int64 LL;
LL dp[maxn][4];
int n,k;
char s[maxn];
void dfs(int len,int k,int st)
{
	if(len == 0)
	{
		s[n] = '\0';
	}else
	{
		if(st == 0)  //a 先考虑 c  , b
		{
			if(k <= dp[len-1][2])
			{
				s[n - len] = '0';
				dfs(len-1,k,2);
			}else 
			{
				s[n - len] = '1';
				dfs(len-1,k-dp[len-1][2],1);
			}
		}else if(st == 1) //b 先考虑 d , a
		{
			if(k <= dp[len-1][3])
			{
				s[n - len] = '0';
				dfs(len-1,k,3);
			}else 
			{
				s[n - len] = '1';
				dfs(len-1,k-dp[len-1][3],0);
			}
		}else if(st == 2) //c 先考率 a , d
		{
			if(k <= dp[len-1][0])
			{
				s[n - len] = '0';
				dfs(len-1,k,0);
				
			}else 
			{
				s[n - len] = '1';
				dfs(len-1,k-dp[len-1][0],3);
				
			}
		}else{   // d 先考虑 b , c
			if(k <= dp[len-1][1])
			{
				s[n - len] = '0';
				dfs(len-1,k,1);
				
			}else 
			{
				s[n - len] = '1';
				dfs(len-1,k-dp[len-1][1],2);			
			}
		}
	}
}
int main()
{
	int i,j,t;
	char c[5];
	while(scanf("%s%d%d",c,&n,&k)!=EOF)
	{
		t = c[0] - 'A';
		dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 0;
		dp[0][t] = 1;
		for(i = 1;i <= n;i ++)
		{
			dp[i][0] = dp[i-1][1] + dp[i-1][2];  //a 1 + b,0 + c;   
			dp[i][1] = dp[i-1][0] + dp[i-1][3]; //b 1 + a,0 + d;    
			dp[i][2] = dp[i-1][0] + dp[i-1][3]; //c 0 + a,1 + d;    
			dp[i][3] = dp[i-1][1] + dp[i-1][2]; //d 0 + b,1 + d;   
		}
		if(k <= dp[n][0])
		{
			dfs(n,k,0);
			printf("%s\n",s);
		}else printf("impossible\n");
	}
	return 0;
}
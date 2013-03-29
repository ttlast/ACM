//参考了维基百科
#include <iostream>
#include <cstring>
#include <string> 
using namespace std;
const int maxn = 1050;
int dp[maxn][maxn],dp2[maxn][maxn],t1,t2;
int min(int a,int b,int c)
{
 	int t = a;
 	t = t > b? b:t;
 	t = t > c? c:t;
 	return t;
}
int max(int a,int b,int c)
{
 	int t = a;
 	t = t > b? t:b;
 	t = t > c? t:c;
 	return t;
}
void ldis(const char *st,const char *ed) //scanf("%s%s",st+1,ed+1);
{
 	int n,m,i,j;
 	n = strlen(st+1);m = strlen(ed+1);
 	memset(dp2,0,sizeof(dp2));
 	//dp[i][j] 表示st[0...i] -> ed[0...j]所需要的最少步骤。 
 	for(i = 1;i <= n;i ++) dp[i][0] = i;  //i次del 
 	for(i = 1;i <= m;i ++) dp[0][i] = i;  //i次add 
 	for(i = 1;i <= n;i ++)
	  for(j = 1;j <= m;j ++)
	  {
 		 if(st[i] == ed[j])
 		 {
 		   dp[i][j] = dp[i-1][j-1];
 		   dp2[i][j] = max(dp2[i-1][j-1]+1,dp2[i-1][j],dp2[i][j-1]);
		 }
	     else
	     {   //分别表示 del insert add; 
		  	 dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1;
		  	 dp2[i][j] = max(dp2[i-1][j],dp2[i][j-1]);
		 }
	  } 
 	t1 = dp2[n][m];
 	t2 = dp[n][m];
}
int main()
{
 	int t,ncase = 0; 
 	char a[maxn],b[maxn];
 	scanf("%d",&t);
 	while(t--)
 	{
        scanf("%s%s",a+1,b+1);
        ldis(a,b);
		ncase ++;
		printf("Case %d: LCS=%d EditStep=%d\n",ncase,t1,t2);
	}
 	return 0;
} 

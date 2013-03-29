//参考了维基百科
/*
一个字符串经过 增 删 替 
得到另外一个字符串的最小次数。 
*/
#include <iostream>
#include <cstring>
#include <string> 
using namespace std;
const int maxn = 1050;
int dp[maxn][maxn];
int min(int a,int b,int c)
{
 	int t = a;
 	t = t > b? b:t;
 	t = t > c? c:t;
 	return t;
}
int ldis(const char *st,const char *ed) //scanf("%s%s",st+1,ed+1);
{
 	int n,m,i,j;
 	n = strlen(st+1);m = strlen(ed+1);
 	//dp[i][j] 表示st[0...i] -> ed[0...j]所需要的最少步骤。 
 	for(i = 1;i <= n;i ++) dp[i][0] = i;  //i次del 
 	for(i = 1;i <= m;i ++) dp[0][i] = i;  //i次add 
 	for(i = 1;i <= n;i ++)
	  for(j = 1;j <= m;j ++)
	  {
 		 if(st[i] == ed[j])
 		   dp[i][j] = dp[i-1][j-1];
	     else
	     {   //分别表示 del i insert j add ; 
		  	 dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1;
		 }
	  } 
 	return dp[n][m];
}
int main()
{
 	char a[maxn],b[maxn];
 	while(scanf("%s%s",a+1,b+1)!=EOF)
 	{
		cout<<ldis(a,b)<<endl;
	}
 	return 0;
} 

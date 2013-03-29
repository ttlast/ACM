#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <math.h>
using namespace std;
const int maxn = 405;
char c[maxn],c1[maxn],c2[maxn];
int dp[maxn][maxn];
bool check()
{
	memset(dp,0,sizeof(dp));
	int i,j,cl1,cl2,cl;
	cl1 = strlen(c1+1);
	cl2 = strlen(c2+1);
	cl = strlen(c+1);
	if(cl1 + cl2 != cl) return false;
	dp[0][0] = 1;
	if(c[2] == c1[1]) dp[1][0] = 1;
	if(c[2] == c2[1]) dp[0][1] = 1;
	for(i = 0;i <= cl1;i ++)
		for(j = 0;j <= cl2;j ++)
		{
			if(i != 0 && c[i+j] == c1[i])
				dp[i][j] += dp[i-1][j];
			if(j != 0 && c[i+j] == c2[j])
				dp[i][j] += dp[i][j-1];
		}
	if(dp[cl1][cl2]) return true;
	else return false;
}
int main()
{
	int t,ncase = 1;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%s%s%s",c1+1,c2+1,c+1);
		printf("Data set %d: ",ncase++);
		if(check()) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
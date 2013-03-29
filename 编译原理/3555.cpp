#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef  __int64 u64;
const int maxn = 100;
u64 dp[3][maxn],n;
int data[maxn],len;
void cls(){
	memset(dp,0,sizeof(dp));
}
int getnstate(int curs,int d){
	if(curs == 0){
		if(d == 4) return 1;
		return 0;
	}else if(curs == 1){
		if(d == 4) return 1;
		else if(d == 9) return 2;
		return 0;
	}else return 2;
}
int main()
{
	u64 tmp,ans;
	int t,i,j,k,l,cur,nc;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%I64d",&n);
		n ++;
		tmp = n;len = 0;
		while(tmp) data[len++] = tmp%10,tmp /= 10;
		cur = 0; nc = 0;ans = 0;
		for(i = len-1;i >= 0;i --)
		{
			for(j = 0;j < data[i];j ++)
			{
				cls();
				k = getnstate(cur,j);
				dp[k][nc] = 1;
				for(l = nc+1;l < len;l ++)
				{
				   dp[0][l] = dp[0][l-1]*9 + dp[1][l-1]*8;
				   dp[1][l] = dp[0][l-1]+dp[1][l-1];
				   dp[2][l] = dp[2][l-1]*10+dp[1][l-1];
				}
				ans += dp[2][len-1];
			}
			nc ++;
			cur = getnstate(cur,data[i]);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
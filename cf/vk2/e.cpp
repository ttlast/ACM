#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
typedef __int64 LL;
const int maxn = 100005;

struct Node{
	int c,s,num;
};
bool comp(const Node & t1,const Node & t2)
{
	if(t1.c != t2.c) return t1.c < t2.c;
	if(t1.s != t2.s) return t1.s > t2.s;
	return t1.num < t2.num;
}
Node mat[maxn];
LL dp[2][maxn];
int star[2][maxn];
int co[2][maxn];
int n;
int main()
{
	int i,j,l;
	LL ans = 0;
	int top,mid,tnum = 0,xnum = 0;
	scanf("%d",&n);
	for(i = 0;i < n;i ++)
	{
		scanf("%d%d",&mat[i].c,&mat[i].s);
		mat[i].num = i+1;
	}
	sort(mat,mat+n,comp);   //nlogn
	dp[0][0] = mat[0].s;
	l = 0;
	for(i = 1;i < n;i++)
	{
		if(mat[i].c != mat[i-1].c)
		{
			if(dp[1][l] < dp[0][l]) //上个数据存入
			{
				dp[1][l] = dp[0][l];
				co[1][l] = co[0][l];
				star[1][l] = star[0][l];
			}
			//处理先
			l = 0;
			star[0][0] = i;
			dp[0][0] = mat[i].s;
			co[0][0] = mat[i].c;
			
			if(dp[1][l] > 0 && dp[0][l]+dp[1][l] > ans)
			{
				ans = dp[0][l] + dp[1][l];
				top = star[0][l];
				mid = star[1][l];
				tnum = xnum = 1;
			}
			if(dp[1][l+1] > 0 && dp[0][l] + dp[1][l+1] > ans)
			{
				ans = dp[0][l] + dp[1][l+1];
				top = star[1][l+1];
				mid = star[0][l];
				tnum = 2;
				xnum = 1;
			}
		}else{
			l ++;
			star[0][l] = star[0][l-1];
			dp[0][l] = dp[0][l-1]+mat[i].s;
			co[0][l] = mat[i].c;
			
			if(dp[1][l-1] > 0 && dp[0][l]+dp[1][l-1] > ans)  // >
			{
				ans = dp[0][l]+dp[1][l-1];
				top = star[0][l];
				mid = star[1][l-1];
				tnum = l+1;
				xnum = l;
			}
			if(dp[1][l] > 0 && dp[0][l]+dp[1][l] > ans)  //==
			{
				ans = dp[0][l] + dp[1][l];
				top = star[0][l];
				mid = star[1][l];
				tnum = l+1;
				xnum = l+1;
			}
			if(dp[1][l+1] > 0 && dp[0][l] + dp[1][l+1] > ans) // < 
			{
				ans = dp[0][l] + dp[1][l+1];
				top = star[1][l+1];
				mid = star[0][l];
				tnum = l+2;
				xnum = l+1;
			}

			if(dp[1][l-1] < dp[0][l-1])
			{
				dp[1][l-1] = dp[0][l-1];
				co[1][l-1] = co[0][l-1];
				star[1][l-1] = star[0][l-1];
			}
		}
	}
	printf("%I64d\n",ans);
	printf("%d\n",tnum+xnum);
	for(i = 0;i < tnum+xnum;i ++)
	{
		if(i == 0) {printf("%d",mat[top].num);top ++;}
		else
		{
			if(i&1) {printf(" %d",mat[mid].num); mid ++;}
			else {printf(" %d",mat[top].num);top ++;}
		}
	}
	printf("\n");
	return 0;
}
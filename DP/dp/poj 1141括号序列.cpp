#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int inf = 1000000000;
const int maxn = 105;
char np[] = {'(',')','[',']'};
int dp[maxn][maxn];
int dpc[maxn][maxn];
char c[maxn];
bool pipei(char x,char y)
{
	if(x == '(' && y == ')') return true;
	else if(x == '[' && y == ']') return true;
	else return false;
}
int fh(char x)
{
	if(x == '(') return 1;
	else if(x == ')') return 0;
	else if(x == '[') return 3;
	else if(x == ']') return  2;
	else return 4;
}
void print(int l,int r)
{
	int t;
	if(l > r) return ;
	else if(l == r)
	{
		t = fh(c[l]);
		if(t == 0 || t == 2)
		{
			printf("%c%c",np[t],c[l]);
		}else printf("%c%c",c[l],np[t]);
	}else
	{
		if(dp[l][r] == dp[l][r-1] + 1)
		{
			print(l,r-1);
			t = fh(c[r]);
			if(t == 0 || t == 2)
			{
				printf("%c%c",np[t],c[r]);
			}else printf("%c%c",c[r],np[t]);
		}else if(dp[l][r] == dp[l+1][r] + 1)
		{
			t = fh(c[l]);
			if(t == 0 || t == 2)
			{
				printf("%c%c",np[t],c[l]);
			}else printf("%c%c",c[l],np[t]);
			print(l+1,r);
		}else if(dp[l][r] == dp[l+1][r-1])
		{
			printf("%c",c[l]);
			print(l+1,r-1);
			printf("%c",c[r]);
		}else
		{
			print(l,dpc[l][r]);
			print(dpc[l][r]+1,r);
		}
	}
}
int main()
{
	int i,j,l,k;
	while(gets(c))
	{
		l = strlen(c);
		memset(dp,0,sizeof(dp));
		memset(dpc,0,sizeof(dpc));
		for(i = 0;i < l;i ++) 
		{
			dp[i][i] = 1;
		}
		for(i = 1;i < l;i ++)
		{
			for(j = 0;j < l-i;j ++)
			{
				if(pipei(c[j],c[j+i]))
				{
					dp[j][j+i] = dp[j+1][j+i-1];
				}else dp[j][j+i] = inf;
				for(k = j;k < j+i;k ++)
				{
					if(dp[j][j+i] > dp[j][k] + dp[k+1][j+i])
					{
						dp[j][j+i] = dp[j][k] + dp[k+1][j+i];
						dpc[j][j+i] = k;
					}
				}
			}
		}
		//printf("%d\n",dp[0][l-1]);
		print(0,l-1);
		printf("\n");
		
	}
	return 0;
}
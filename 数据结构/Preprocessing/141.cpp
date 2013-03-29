#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 55;

int map[1000][maxn][maxn],len;

int cur[maxn][maxn],n;

bool check()
{
	int i,j,k;
	memcpy(map[len],cur,sizeof(cur));
	for(i = 0;i < len;i ++)
	{
		for(j = 1;j <= n;j ++)
		{
			for(k = 1;k <= n;k ++)
			{
				if(map[i][j][k] != cur[j][k])
					break;
			}
			if(k <= n) break;
		}
		if(j > n) return true;
		//trun 
		for(j = 1;j <= n;j ++)
		{
			for(k = 1;k <= n;k ++)
			{
				if(map[i][j][k] != cur[k][j])
					break;
			}
			if(k <= n) break;
		}
		if(j > n) return true;
		//trun  
		for(j = 1;j <= n;j ++)
		{
			for(k = 1;k <= n;k ++)
			{
				if(map[i][j][k] != cur[n-j+1][n-k+1])
					break;
			}
			if(k <= n) break;
		}
		if(j > n) return true;
		//trun 
		for(j = 1;j <= n;j ++)
		{
			for(k = 1;k <= n;k ++)
			{
				if(map[i][j][k] != cur[n-k+1][j])
					break;
			}
			if(k <= n) break;
		}
		if(j > n) return true;
		//trun 
		for(j = 1;j <= n;j ++)
		{
			for(k = 1;k <= n;k ++)
			{
				if(map[i][j][k] != cur[k][n-j+1])
					break;
			}
			if(k <= n) break;
		}
		if(j > n) return true;
	}
	len ++;
	return false;
}
int main()
{
	int i,j,sign,st,player;
	int x,y,tmp;
	char c[5];
	while(scanf("%d",&n),n)
	{
		sign = -1;
		tmp = n<<1;
		memset(cur,0,sizeof(cur));
		st = 0;
		len = 0;
		player = 0;
		for(i = 0;i < tmp;i ++)
		{
			scanf("%d%d%s",&x,&y,c);
			if(c[0] == '+')
			{
				cur[x][y] = 1;
			}else if(c[0] == '-')
			{
				cur[x][y] = 0;
			}
			if(check()&&player == 0)
			{
				sign = 0;
				if(i&1)
					player = 1;
				else
					player = 2;
				st = i+1;
			}
		}
		if(sign == -1)
			printf("Draw\n");
		else if(sign == 0)
			printf("Player %d wins on move %d\n",player,st);
	}
	return 0;
}
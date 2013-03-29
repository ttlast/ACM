#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 105;
int n,m;
char c[maxn][maxn];
int hash[maxn][10];
int main()
{
	int i,j,k,num,al,sum;

	scanf("%d%d",&n,&m);
	for(i = 0;i < n;i ++)
	{
		scanf("%s",c[i]);
		for(j = 0;j < m;j ++)
		{
			num = c[i][j] - '0';
			hash[j][num] ++;
		}
	}
	for(j = 0;j < m;j ++)
		for(i = 8;i >= 0;i --)
			hash[j][i] += hash[j][i+1];
	sum = 0;
	for(i = 0;i < n;i ++)
	{
		for(j = 0;j < m;j ++)
		{
			num = c[i][j] - '0';
			if(num == 9) {sum ++;break;}
			else if(hash[j][num+1] == 0) {sum ++;break;}
		}
	}
	printf("%d\n",sum);
	return 0;
}
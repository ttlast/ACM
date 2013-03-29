#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;
#define __abs(x) (x) > 0 ? (x):(-(x))
#define maxinf 100000000
#define inf 0.000001
typedef long long LL;
const int maxn = 1005;

struct Node{
	int x,y,z;
};
Node mat[maxn];
double dis[maxn][maxn];
int cost[maxn][maxn];
int n;

bool sign[maxn];
int s[maxn];
double d[maxn];
double prime(double x)
{
	int i,j,k;
	double cst,dist,mind,tmp;
	cst = dist = 0;
	for(i = 1;i < n;i ++)
	{
		sign[i] = false;
		s[i] = 0;
		d[i] = cost[0][i] - x*dis[0][i];
	}
	sign[0] = true;
	for(i = 1;i < n;i ++)
	{
		mind = maxinf;
		for(j = 1;j < n;j ++)
		{
			if(sign[j]) continue;
			if(d[j] < mind)
				k = j,mind = d[j];
		}
		sign[k] = true;
		cst += cost[s[k]][k];
		dist += dis[s[k]][k];
		for(j = 1;j < n;j ++)
		{
			if(sign[j]) continue;
			tmp = cost[k][j] - x*dis[k][j];
			if(tmp < d[j])
			{
				d[j] = tmp;
				s[j] = k;
			}
		}
	}
	return cst/dist;
}
int main()
{
	int i,j;
	double a,b;
	while(scanf("%d",&n),n)
	{
		for(i = 0;i < n;i ++)
			scanf("%d%d%d",&mat[i].x,&mat[i].y,&mat[i].z);
		for(i = 0;i < n;i ++)
		{
			for(j = i+1;j < n;j ++)
			{
				dis[i][j] = dis[j][i] = sqrt(1.0*(mat[i].x-mat[j].x)*(mat[i].x-mat[j].x) + (mat[i].y-mat[j].y)*(mat[i].y-mat[j].y));
				cost[i][j] = cost[j][i] =  __abs(mat[i].z - mat[j].z);
			}
		}
		b = 0;
		do{
			a = b;
			b = prime(a);
		}while(__abs(b-a) > inf);
		printf("%.3f\n",b);
	}
	return 0;
}
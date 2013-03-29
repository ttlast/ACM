#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;
#define inf 0.000001
typedef long long LL;
const int maxn = 1005;

struct Node{
	LL a,b;
	double c;
};
bool comp(const Node & t1,const Node & t2)
{
	return t1.c > t2.c;
}
Node mat[maxn];
double k;
int n,m;
bool check(double val)
{
	double ans;
	int i;
	for(i = 0;i < n;i ++)
		mat[i].c = mat[i].a - mat[i].b*val;
	sort(mat,mat+n,comp);
	ans = 0;
	for(i = 0;i < m;i ++)
	{
		ans += mat[i].c;
	}
	if(ans >= -inf) return true;
	return false;
}
void bf()
{
	double l,r,mid;
	l = 0;r = 1.0;
	while(r-l >= inf)
	{
		mid = (l+r)/2;
		if(check(mid))
		{
			l = mid + inf;
			k = mid;
		}
		else r = mid - inf;
	}
}
int main()
{
	int i,j;
	while(scanf("%d%d",&n,&m),n|m)
	{
		m = n-m;
		for(i = 0;i < n;i ++)
			scanf("%I64d",&mat[i].a);
		for(i = 0;i < n;i ++)
			scanf("%I64d",&mat[i].b);
		bf();
		printf("%.f\n",k*100);
	}
	return 0;
}
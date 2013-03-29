#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;
#define inf 0.001
const int maxn = 1005;

int n,m;
struct Node{
	double h,l;
};
Node na[maxn],nb[maxn];
double r1,r2;
int main()
{
	int i,j;
	double ans,tm;
	while(scanf("%d",&n)!=EOF)
	{
		for(i = 0;i < n;i ++)
			scanf("%lf%lf",&na[i].h,&na[i].l);
		scanf("%d",&m);
		for(i = 0;i < m;i ++)
			scanf("%lf%lf",&nb[i].h,&nb[i].l);
		ans = -1;
		r1 = r2 = 0;
		i = j = 0;
		while(1)
		{
			if(i >= n && j >= m) break;
			if(i >= n){
				if(ans < 0 || ans > nb[j].h) ans = nb[j].h;
				j ++;
			}else if(j >= m){
				if(ans < 0 || ans > na[i].h) ans = na[i].h;
				i ++;
			}else{
				if(na[i].h > nb[j].h) tm = na[i].h;
				else tm = nb[j].h;
				if(ans < 0 || ans > tm) ans = tm;
				if(fabs(r1 + na[i].l - r2 - nb[j].l) <= inf)
				{
					r2 += nb[j].l;
					j ++;
					r1 += na[i].l;
					i ++;
				}else	if(r1 + na[i].l > r2 + nb[j].l)
				{
					r2 += nb[j].l;
					j ++;
				}else{
					r1 += na[i].l;
					i ++;
				}
			}
		}
		if(ans >= inf) printf("%.3f\n",ans);
		else printf("0\n");
	}
	return 0;
}
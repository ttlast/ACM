#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 105;
int a[maxn],sg[maxn];
int v[maxn],ss[maxn],maxs;
void getsg(int num,int cs,int val,int step)  //’“µ»º€¿‡
{
	int i,j,ret;
	if(cs == 1)
	{
		v[step] = num;
		ret = 0;
		for(j = 0;j <= step;j ++)
			ret ^= sg[v[j]];
		ss[ret] = 1;
		if(ret > maxs) maxs = ret;
	}else{
		for(i = 0;(val+i)*cs <= num;i ++)
		{
			v[step] = val+i;
			getsg(num-val-i,cs-1,val+i,step+1);
		}
	}
}

int main()
{
	int t,n,m,i,j,maxd,ans;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d%d",&n,&m);
		maxd = 0;
		for(i = 0;i < n;i ++)
		{
			scanf("%d",&a[i]);
			if(a[i] > maxd) maxd = a[i];
		}
		for(i = 0;i < m;i ++) sg[i] = 0;
		sg[m] = 1;
		for(i = m+1;i <= maxd;i ++)
		{
			for(j = 0;j <= maxs;j ++) ss[j] = 0;
			getsg(i,m,1,0);
			for(j = 0;;j ++)
				if(ss[j] == 0) break;
			sg[i] = j;
		}
		ans = 0;
		for(i = 0;i < n;i ++)
			ans ^= sg[a[i]];
		if(ans) printf("Win\n");
		else printf("Lose\n");
	}
	return 0;
}
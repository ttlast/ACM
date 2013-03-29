#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 21000;

int wa[maxn],wb[maxn],wv[maxn],wn[maxn];
bool Comp(int *r,int a,int b,int l)
{
	return r[a] == r[b] && r[a+l] == r[b+l];
}
//n 是队列的长度 + 1
//每次用时，要清空r的第n元素（队列从0开始）

void Da(int *r,int *sa,int n,int m) 
{
	int i,j,p,*x,*y,*t;
	r[n-1] = 0;
	x = wa; y = wb;
	for(i = 0;i <= m;i ++) wn[i] = 0;
	for(i = 0;i < n;i ++) wn[x[i]=r[i]] ++;
	for(i = 1;i <= m;i ++) wn[i] += wn[i-1];
	for(i = n-1;i >= 0;i --) sa[--wn[x[i]]] = i;

	for(j = 1,p = 1;p < n;j <<= 1,m = p)
	{
		for(i = n-j,p = 0;i < n;i ++) y[p++] = i;
		for(i = 0;i < n;i ++) if(sa[i] >= j) y[p++] = sa[i] - j;

		for(i = 0;i < n;i ++) wv[i] = x[y[i]];
		for(i = 0;i <= m;i ++) wn[i] = 0;
		for(i = 0;i < n;i ++) wn[wv[i]] ++;
		for(i = 1;i <= m;i ++) wn[i] += wn[i-1];
		for(i = n-1;i >= 0;i --) sa[--wn[wv[i]]] = y[i];

		t = x; x = y; y = t;
		for(x[sa[0]] = 0,i = 1,p = 1;i < n;i ++)
			x[sa[i]] = Comp(y,sa[i-1],sa[i],j) ? p-1:p++;
	}
}

//height[i] 排好序的后缀i与i-1的最长公共前缀
//rank[i] suffix(i) 的排名
int height[maxn],rank[maxn];

void CallHeight(int *r,int *sa,int n)
{
	int i,j,k = 0;
	for(i = 1;i <= n;i ++) rank[sa[i]] = i;

	for(i = 0;i < n;height[rank[i++]] = k)
		for(k?k--:0,j = sa[rank[i]-1];r[i+k] == r[j+k];k ++);
}

int n,a[maxn],tsa[maxn];

bool Possable(int val)
{
	int i,j,mins,maxs;
	for(i = 2;i <= n;i ++)
	{
		if(height[i] >= val)
		{
			mins = min(mins,tsa[i-1]);
			mins = min(mins,tsa[i]);
			maxs = max(maxs,tsa[i-1]);
			maxs = max(maxs,tsa[i]);
			if(maxs-mins > val) return true;
		}else 
		{
			mins = maxn;
			maxs = -1;
		}
	}
	return false;
}

int BFind(int len)
{
	int l,r,mid,best;
	l = best = 0; r = len/2;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(Possable(mid)) 
		{
			best = mid;
			l = mid + 1;
		}else r = mid - 1;
	}
	if(best < 4) return 0;
	return best+1;
}
int main()
{
	int i,j,x,y,s;
	while(scanf("%d",&n))
	{
		if(n == 0) break;
		scanf("%d",&x);
		for(i = 1;i < n;i ++)
		{
			scanf("%d",&y);
			a[i-1] = y-x+90;
			x = y;
		}	
		Da(a,tsa,n,200);
		CallHeight(a,tsa,n-1);
		s = BFind(n-1);
		printf("%d\n",s);
	}
	return 0;
}
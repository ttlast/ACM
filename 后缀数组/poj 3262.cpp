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

void Da(int *r,int *sa,int n,int m)
{
	int i,j,p,*x,*y,*t;
	r[n-1] = 0;
	x = wa; y = wb;
	for(i = 0;i <= m;i ++) wn[i] = 0;
	for(i = 0;i < n;i ++) wn[x[i]=r[i]]++;
	for(i = 1;i <= m;i ++) wn[i] += wn[i-1];
	for(i = n-1;i >= 0;i --) sa[--wn[x[i]]] = i;

	for(j = 1,p = 1;p < n;j <<= 1,m = p)
	{
		for(i = n-j,p = 0;i < n;i ++) y[p++] = i;
		for(i = 0;i < n;i ++)
			if(sa[i] >= j) y[p++] = sa[i]-j;

		for(i = 0;i < n;i ++) wv[i] = x[y[i]];

		for(i = 0;i <= m;i ++) wn[i] = 0;
		for(i = 0;i < n;i ++) wn[wv[i]] ++;
		for(i = 1;i <= m;i ++) wn[i] += wn[i-1];
		for(i = n-1;i >= 0;i --)  sa[--wn[wv[i]]] = y[i];

		t = x; x = y; y = t;
		for(x[sa[0]] = 0,i = 1,p = 1;i < n;i ++)
			x[sa[i]] = Comp(y,sa[i],sa[i-1],j) ? p-1:p ++;
	}
}

int height[maxn],rank[maxn];

void CallHeight(int *r,int *sa,int n)
{
	int i,j,p,k = 0;
	for(i = 1;i <= n;i ++) rank[sa[i]] = i;

	for(i = 0;i < n;height[rank[i++]] = k)
		for(k ? k--:0,j = sa[rank[i]-1];r[i+k] == r[j+k];k ++);
}

int n,k;
int a[maxn],sa[maxn];

bool checkok(int val,int k)
{
	int i,t;
	t = 0;
	for(i = 2;i <= n;i ++)
	{
		if(height[i] >= val) t ++;
		else t = 0;
		if(t+1 >= k) return true;
	}
	return false;
}

int check(int n,int k)
{
	int l,r,mid,best;
	l = best = 0,r = n-1;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(checkok(mid,k))
		{
			l = mid + 1;
			best = mid;
		}else r = mid - 1;
	}
	return best;
}
int main()
{
	int i,j;
	scanf("%d%d",&n,&k);
	for(i = 0;i < n;i++)
		scanf("%d",&a[i]);
	Da(a,sa,n+1,200);
	CallHeight(a,sa,n);
	printf("%d\n",check(n,k));
	return 0;
}
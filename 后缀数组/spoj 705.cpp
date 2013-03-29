#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned int uint;
const int maxn = 50005;

int wa[maxn],wb[maxn],wv[maxn],wn[maxn];
bool Comp(int *r,int a,int b,int l)
{
	return r[a] == r[b] && r[a+l] == r[b+l];
}
//n 是队列的长度+ 1
//每次用时，要清空r的第n元素（队列从开始）
//sa[1]…sa[n] 排名第一…..的后缀从那里开始

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

char c[maxn];
int a[maxn],sa[maxn];
int main()
{
	int t,i,n;
	int sum;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%s",c);
		n = strlen(c);
		for(i = 0;i < n;i ++)
			a[i] = c[i];
		Da(a,sa,n+1,260);
		CallHeight(a,sa,n);
		if(n&1) sum = n*((n+1)>>1);
		else sum = (n>>1)*(n+1);
		for(i = 2;i <= n;i ++)
			sum -= height[i];
		printf("%d\n",sum);
	}
	return 0;
}
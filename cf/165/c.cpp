#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
typedef __int64 LL;
const int maxn = 1000005;

int bit[maxn],cl;
char c[maxn];

int lsearch(int val)
{
	int l,r,mid;
	l = 0;r = cl;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(bit[mid] >= val) r = mid - 1;
		else l = mid + 1;
	}
	return l; //left >= val
}
int rsearch(int val)
{
	int l,r,mid;
	l = 0;r = cl;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(bit[mid] > val) r = mid - 1;
		else l = mid + 1;
	}
	return r;//right <= val
}
int main()
{
	int k,pos,ak,i;
	int minl,minr,maxl,maxr;
	LL ans,l;
	scanf("%d",&k);
	scanf("%s",c);
	cl = strlen(c);
	for(i = 0;i < cl;i ++)
	{
		if(c[i] == '1') bit[i+1] = bit[i]+1;
		else bit[i+1] = bit[i];
	}
	ans = 0;
	if(k != 0)
	{
		ak = k;
		while(ak <= bit[cl])
		{
			minl = lsearch(ak-k);
			minr = rsearch(ak-k);
			maxl = lsearch(ak);
			maxr = rsearch(ak);
			ans += (LL) ((LL) minr-minl+1)*((LL) maxr-maxl+1);
			ak ++;
		}
	}else{
		ak = k;
		while(ak <= bit[cl])
		{
			minl = lsearch(ak);
			maxr = rsearch(ak);
			l = maxr - minl;
			ans += l*(l+1)/2;
			ak ++;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}
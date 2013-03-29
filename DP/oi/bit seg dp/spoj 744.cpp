#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int maxn = 100005;
int n,a[maxn];
int one[maxn],len;
bool lhash[maxn],rhash[maxn];
int l[maxn],r[maxn];
int maxl[maxn],maxr[maxn];
int maxtl[maxn],maxtr[maxn];
void checkl(int pos)
{
	int i,maxd;
	maxd = 0;
	for(i = pos-1;i >= l[pos];i --)
	{
		if(lhash[a[i]]) break;
		lhash[a[i]] = true;
		if(a[i] > maxd) maxd = a[i];
		maxl[i] = maxd;
	}
	l[pos] = i+1;
}
void checkr(int pos)
{
	int i,maxd;
	maxd = 0;
	for(i = pos+1;i <= r[pos];i ++)
	{
		if(rhash[a[i]]) break;
		rhash[a[i]] = true;
		if(a[i] > maxd) maxd = a[i];
		maxr[i] = maxd;
	}
	r[pos] = i-1;
}
int  getlans(int pos)
{
	int ans = 0,i,j,pr,tmp,maxd = 0;
	pr = r[pos];
	for(i = l[pos];i < pos;i ++)
	{
		while(pr > pos && maxr[pr] >= maxl[i]) pr --;
		maxtl[i] = pr;
	}
	pr = 1;
	for(i = l[pos];i < pos;i ++)
	{
		
		//if(maxl[i] > maxd) maxd = maxl[i];
		while(pr+pos <= r[pos] && (!lhash[a[pr+pos]]))
			++pr;

		tmp = min(pr,maxtl[i]-pos+1) + pos - i;
		if(tmp == maxl[i] && tmp > ans)
			ans = tmp;
		lhash[a[i]] = false;
	}
	//for(i = 1;i <= maxd;i ++) lhash[i] = false;
	return ans;
}
int  getrans(int pos)
{
	int ans = 0,i,pl,tmp,maxd = 0;
	pl = l[pos];
	for(i = r[pos];i > pos;i --)
	{
		while(pl < pos && maxl[pl] >= maxr[i]) pl ++;
		maxtr[i] = pl;
	}
	pl = 1;
	for(i = r[pos];i > pos;i --)
	{
		//if(maxr[i] > maxd) maxd = maxr[i];
		while(pos-pl >= l[pos] && (!rhash[a[pos-pl]]))
			++pl;

		tmp = min(pl,pos-maxtr[i]+1) + i - pos;
		if(tmp == maxr[i] && tmp > ans) 
			ans = tmp;
		rhash[a[i]] = false;
	}
	//for(i = 1;i <= maxd;i ++) rhash[i] = false;
	return ans;
}
int scan()
{
	int num = 0;
	char c;
	do
	{
		c = getchar();
	}while(c < '0' || c > '9');
	num = c - '0';
	do
	{
		c = getchar();
		if(c < '0' || c > '9') break;
		num = num*10 + c - '0';
	}while(1);
	return num;
}

int main()
{
	int i,j,ans = 1;
	len = 1;
	//scanf("%d",&n);
	n = scan();
	one[0] = 0;
	for(i = 0;i <= n;i ++)
	{
		lhash[i] = rhash[i] = false;
	}
	for(i = 1;i <= n;i ++)
	{
		//scanf("%d",&a[i]);
		a[i] = scan();
		if(a[i] == 1) one[len++] = i;
	}
	if(len <= 1) printf("0\n");
	else
	{
		for(i = 1;i < len;i ++)
		{
			l[one[i]] = one[i-1]+1;
			r[one[i]] = one[i+1]-1;
		}
		r[one[len-1]] = n;
		for(i = 1;i < len;i ++)
		{
			checkl(one[i]);
			checkr(one[i]);
			ans = max(ans,getlans(one[i]));
			ans = max(ans,getrans(one[i]));
		}
		printf("%d\n",ans);
	}
	return 0;
}


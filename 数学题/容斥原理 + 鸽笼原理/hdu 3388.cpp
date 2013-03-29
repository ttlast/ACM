#include <iostream>
using namespace std;
#define inf 8000000000
const int maxn = 120000;
bool noprim[maxn] = {0};
typedef __int64 LL;
int m,n,k;
int prim[12000],len;
void init()
{
	int i,j;
	len = 1;prim[0] = 2;
	for(i = 4;i < maxn;i += 2) noprim[i] = true;
	for(i = 3;i < maxn;i += 2)
	{
		if(!noprim[i])
		{
			for(j = i*2;j < maxn;j += i) noprim[j] = true;
			prim[len++] = i;
		}
	}
}
int num[100],nlen;
void fprim(int x,int y)
{
	int i;
	nlen = 0;
	for(i = 0;i < len;i ++)
	{
		if(x < prim[i] && y < prim[i]) break;
		if(x%prim[i] == 0 && y%prim[i] == 0)
		{
			while(x%prim[i] == 0){
				x /= prim[i];
			}
			while(y%prim[i] == 0){
				y /= prim[i];
			}
			num[nlen++] = prim[i];
		}else if(x%prim[i] == 0)
		{
			while(x%prim[i] == 0){
				x /= prim[i];
			}
			num[nlen++] = prim[i];
		}else if(y%prim[i] == 0)
		{
			while(y%prim[i] == 0){
				y /= prim[i];
			}
			num[nlen++] = prim[i];
		}
	}
	if(x != 1 && x == y) num[nlen++] = x;
	else if(x != 1 && y != 1) {num[nlen++] = x;num[nlen++] = y;}
	else if(x != 1) num[nlen++] = x;
	else if(y != 1) num[nlen++] = y;
}
struct Node{
	int nflag;
	LL num;
};
int top;
Node a[1200000];
void Build()
{
	int i,tmp,j;
	top = 1;
	a[0].nflag = 0;
	a[0].num = 1;
	for(i = 0;i < nlen;i ++)
	{
		tmp = top;
		for(j = 0;j < tmp;j ++)
		{
			a[top].nflag = a[j].nflag + 1;
			a[top].num = a[j].num * num[i];
			top ++;
		}
	}
}
LL check(LL d)
{
	int i;
	LL ret = 0;
	for(i = 0;i < top;i ++)
	{
		if(a[i].nflag&1) ret -= d/a[i].num;
		else ret += d/a[i].num;
	}
	return ret;
}
LL bsearch(int m,int  n,int k)
{
	LL ret = 0;
	fprim(m,n);
	Build();
	LL l,r,mid,best;
	l = 1;r = inf;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(check(mid) >= k)
		{
		   best = mid;
		   r = mid-1;
		}else l = mid+1;
	}
	return best;
}
int main()
{
	int t,ncase = 1;
	init();
	printf("%d\n",len);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&m,&n,&k);
		printf("Case %d: %I64d\n",ncase++,bsearch(m,n,k));
	}
	return 0;
}

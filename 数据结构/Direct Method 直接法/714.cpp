#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
using namespace std;
const int maxn = 550;
typedef long long LL;

int n,k;
LL v[maxn],al;
int sign[maxn];
bool check(LL val)
{
	int num,i,pk;
	LL tmp = 0;
	pk = 0;
	for(i = n-1;i >= 0;i --)
	{
		if(v[i]+tmp <= val)
		{
			tmp += v[i];
		}else{
			tmp = v[i];
			pk ++;
		}
	}
	if(pk < k) return true;
	return false;
}

LL dbsearch(LL v)
{
	LL l,r,mid;
	l = v;r = al;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(check(mid))
			r = mid -1;
		else l = mid + 1;
	}
	return l;
}

int main()
{
	int t,i,j;
	LL val,tmp;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d%d",&n,&k);
		al = 0;
		for(i = 0;i < n;i ++)
		{
			sign[i] = 0;
			scanf("%lld",&v[i]);
			al += v[i];
			if(i == 0) val = v[i];
			else val = max(val,v[i]);
		}
		val = dbsearch(val);
		tmp = 0;
		for(i = n-1;i >= 0;i --)
		{
			if(i < k)
			{
				if(tmp + v[i] > val)
				{
					tmp = v[i];
					sign[i+1] = 1;
					k --;
				}else{
					k --;
					sign[i] = 1;
					tmp = 0;
				}
				continue;
			}
			if(tmp + v[i] == val)
			{
				k --;
				sign[i] = 1;
				tmp = 0;
				
			}else if(tmp + v[i] > val){
				k --;
				sign[i+1] = 1;
				tmp = v[i];
				
			}else tmp += v[i];
		}
		
		for(i = 0;i < n;i ++)
		{
			if(i == 0) printf("%lld",v[i]);
			else{
				if(sign[i] == 1) printf(" /");
				printf(" %lld",v[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
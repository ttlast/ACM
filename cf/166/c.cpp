#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <ctime>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 10000;
int a[maxn],n;


int main()
{
	int x,i,l,r,mid,pos,ans;
	l = r = mid = 0;
	scanf("%d%d",&n,&x);
	for(i = 0;i < n;i ++)
	{
		scanf("%d",&a[i]);
		if(a[i] < x) l ++;
		else if(a[i] == x) mid ++;
		else r ++;
	}
	if(mid == 0) ans = 1,mid = 1;
	else ans = 0;
	if(mid == 1){
		if(l < r) ans += (r-1-l);
		else ans += (l-r);
	}else{
		if(l < r){
			if(l + mid < r) ans += (r-l-mid);
		}else{
			if(r + mid < l) ans += (l+1-r-mid);
		}
	}
	printf("%d\n",ans);
	return 0;
}
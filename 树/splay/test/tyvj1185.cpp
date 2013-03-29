#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <set>
using namespace std;
#define _abs(x) (x) > 0 ? (x):(-(x))
const int maxn = 1000010;
typedef long long LL;
int main()
{
	LL sum;
	int i,n,tmp,mind,maxd;
	set<int> ss;
	set<int>::iterator ia;
	scanf("%d",&n);
	scanf("%d",&tmp);
	sum = tmp;
	maxd = tmp;
	ss.insert(tmp);
	for(i = 1;i < n;i ++)
	{
		scanf("%d",&tmp);
		ia = ss.lower_bound(tmp);
		mind = maxn;
		if(ia != ss.end())
		{
			mind = _abs(*ia - tmp);
			ia --;
		}
		if(ia != ss.end())
			mind = min(_abs(tmp - *ia),mind);
		if(mind == maxn)
			sum += _abs(tmp-maxd);
		else sum += mind;
		if(tmp > maxd) maxd = tmp;
		ss.insert(tmp);
	}
	printf("%lld\n",sum);
	return 0;
}


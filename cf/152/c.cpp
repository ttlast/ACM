#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
typedef __int64 LL;
const int mod = 1000000007;
const int maxn = 105;

string c[maxn];
int hash[300];
int main()
{
	int n,m,i,j,k,cnt;
	LL sum;
	cin>>n>>m;
	for(i = 0;i < n;i ++)
		cin>>c[i];
	sort(c,c+n);
	sum = 1;
	for(i = 0;i < m;i ++)
	{
		for(j = 0;j < 300;j ++) hash[j] = 0;
		for(j = 0;j < n;j ++)
			hash[c[j][i]] = 1;
		cnt = 0;
		for(j = 0;j < 300;j ++)
			if(hash[j]) cnt ++;
		sum = LL(sum*cnt);
		sum %= mod;
	}
	printf("%I64d\n",sum);
	return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <ctime>
#include <queue>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn = 55;

struct Node{
	int p,t;
};
bool comp(const Node  t1,const Node & t2)
{
	if(t1.p != t2.p) return t1.p > t2.p;
	return t1.t < t2.t;
}
Node mat[maxn];
int n,k;
int main()
{
	int i,j,ans;
	scanf("%d%d",&n,&k);
	ans = 1;
	for(i = 0;i < n;i ++)
		scanf("%d%d",&mat[i].p,&mat[i].t);
	sort(mat,mat+n,comp);
	for(i = k-2;i >= 0;i --)
		if(mat[i].p == mat[k-1].p && mat[i].t == mat[k-1].t) ans ++;
		else break;
	for(i = k;i < n;i ++)
		if(mat[i].p == mat[k-1].p && mat[i].t == mat[k-1].t) ans ++;
		else break;
	printf("%d\n",ans);

	return 0;
}
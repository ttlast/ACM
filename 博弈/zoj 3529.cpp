#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 100005;
const int maxe = 5000005;
int hash[maxe];
int v[maxn];
void init()
{
	int i,j,tmp;
	hash[1] = 0;
	for(i = 2;i < maxe;i += 2)
	{
		tmp = i;
		while(!(tmp&1))
		{
			hash[i] ++;
			tmp >>= 1;
		}
	}
	for(i = 3;i < maxe;i += 2)
	{
		if(hash[i] == 0)
		{
			for(j = i;j < maxe;j += i){
				tmp = j;
				while(tmp%i == 0){
					hash[j] ++;
					tmp /= i;
				}
			}
		}
	}
}
int main()
{
	int n,i,ans,ncase = 0;
	init();
	while(scanf("%d",&n)!=EOF)
	{
		ans = 0;
		for(i = 0;i < n;i ++)
		{
			scanf("%d",&v[i]);
			v[i] = hash[v[i]];
			ans ^= v[i];
		}
		ncase ++;
		printf("Test #%d: ",ncase);
		if(ans){
			for(i = 0;i < n;i ++)
				if((ans^v[i]) < v[i]) break;
			printf("Alice %d\n",i+1);
		}else printf("Bob\n");
	}
	return 0;
}
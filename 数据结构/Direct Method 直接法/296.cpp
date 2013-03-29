#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
using namespace std;
const int maxn = 10005;
#define ___min(a,b) (a)>(b)?(b):(a)

struct Node{
	int v,c,d;
	int hash[10],vn[4];
	void set()
	{
		int i;
		for(i = 0;i < 10;i ++)
			hash[i] = 0;
	}
};
Node mat[20];
int len,num[maxn],n,hash[4];

void clsh()
{
	int i;
	for(i = 0;i < 4;i ++)
		hash[i] = 0;
}

bool check(int val)
{
	int i,j,k,vn[4],tm,co,cd;
	
	vn[0] = vn[1] = vn[2] = vn[3] = 0;
	j = 0;
	while(j < 4){
		tm = val%10;
		vn[j] = tm;
		j ++;
		val /= 10;
	}
	for(i = 0;i < n;i ++)
	{
		co = cd = 0;
		clsh();
		for(j = 0;j < 4;j ++)
		{
			if(vn[j] == mat[i].vn[j]) co ++;
			else{
				for(k = 0;k < 4;k ++)
					if(vn[k] != mat[i].vn[k] && vn[j] == mat[i].vn[k] && hash[k] == 0)
					{
						cd ++;
						hash[k] = 1;
						break;
					}
			}
		}
		if(co != mat[i].c || cd != mat[i].d)
			return false;
	}
	return true;
}
int main()
{
	int t,i,j,tm;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d",&n);
		len = 0;
		for(i = 0;i < n;i ++)
		{
			scanf("%d%d/%d",&mat[i].v,&mat[i].c,&mat[i].d);
			mat[i].set();
			tm = mat[i].v;
			j = 0;
			while(j < 4)
			{
				mat[i].vn[j] = tm%10;
				tm /= 10;
				j ++;
			}
		}
		for(i = 0;i < 10000;i ++)
		{
			if(check(i))
				num[len++] = i;
		}
		if(len == 1) printf("%04d\n",num[0]);
		else if(len > 1) printf("indeterminate\n");
		else printf("impossible\n");
	}
	return 0;
}
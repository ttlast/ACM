#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 100;

int mat[maxn][maxn];
struct Node{
	int x,pos;
};
Node a[maxn];
Node tm[maxn];
bool operator < (const Node & t1,const Node & t2)
{
	return t1.x < t2.x;
}
int main()
{
	int t,ncase = 0,i,j,k,n;
	bool sign;
	Node tmp,ctmp;
	priority_queue<Node> pq;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d",&n);
		for(i = 0;i < n;i ++)
		{
			scanf("%d",&a[i].x);
			a[i].pos = i;
			pq.push(a[i]);
		}
		for(i = 0;i < n;i ++)
			for(j = 0;j < n;j ++)
				mat[i][j] = 0;
		sign = false;
		while(!pq.empty())
		{
			tmp = pq.top();
			pq.pop();
			k = 0;
			while(k < tmp.x)
			{
				tm[k] = pq.top();
				mat[tmp.pos][tm[k].pos] = mat[tm[k].pos][tmp.pos] = 1;
				pq.pop();
				tm[k].x --;
				if(tm[k].x < 0) sign = true;
				k ++;
			}
			while(k > 0)
			{
				pq.push(tm[k-1]);
				k --;
			}
		}
		if(ncase) printf("\n");
		ncase ++;
		if(sign) printf("NO\n");
		else{
			printf("YES\n");
			for(i = 0;i < n;i ++)
			{
				for(j = 0;j < n;j ++)
					if(j) printf(" %d",mat[i][j]);
					else printf("%d",mat[i][j]);
				printf("\n");
			}
		}
	}
	return 0;
}
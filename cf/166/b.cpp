#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <ctime>
#include <queue>
#include <cstring>
using namespace std;
typedef __int64 LL;
const int maxn = 200000;

struct Node{
	int x,y;
};
LL cross(Node o,Node t1,Node t2)  //比赛的时候没有用LL,错了
{
	return (LL) (t1.x-o.x)*(t2.y-o.y) - (LL) (t1.y-o.y)*(t2.x-o.x);
}
bool comp(const Node & t1,const Node &t2)
{
	if(t1.y == t2.y) return t1.x < t2.x;
	else return t1.y < t2.y;
}
Node mat[maxn],bag[maxn],ba[maxn];
int n,m,len,an;
void make_bag()
{
	int i,j;
	bag[0] = mat[0];
	len = 1;
	for(i = 1;i < n;i ++){
		while(len >= 2 && cross(bag[len-2],bag[len-1],mat[i]) < 0) len --;
		bag[len++] = mat[i];
	}
	j = len + 1;
	for(i = n-2;i >= 0;i --)
	{
		while(len >= j && cross(bag[len-2],bag[len-1],mat[i]) < 0) len --;
		bag[len++] = mat[i];
	}
	len --;
}

int main()
{
	int i,j,k;
	scanf("%d",&n);
	for(i = 0;i < n;i ++)
	{
		scanf("%d%d",&mat[i].x,&mat[i].y);
		ba[i] = mat[i];
	}
	an = n;
	scanf("%d",&m);
	for(i = 0;i < m;i ++)
		scanf("%d%d",&mat[i+n].x,&mat[i+n].y);
	n += m;
	sort(mat,mat+n,comp);
	make_bag();
	if(len != an) printf("NO\n");
	else{
		for(i = 0;i < len;i ++)
			if(bag[i].x == ba[0].x && bag[i].y == ba[0].y) break;
		if(i >= len) printf("NO\n");
		else{
			for(j = 0,k = i;j < an;j ++,k --)
			{
				if(k < 0) k += an;
				if(bag[k].x != ba[j].x || bag[k].y != ba[j].y) break;
			}
			if(j >= an) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
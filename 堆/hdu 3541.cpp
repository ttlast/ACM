#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
typedef long long LL;
#define INF 1000000000000LL
const int maxn = 200005;

LL a[maxn];
int n,k;
int heap[maxn],pre[maxn],next[maxn],link[maxn],len;

void swap(int  x,int  y)
{
	int tm;
	link[heap[x]] = y;
	link[heap[y]] = x;
	tm = heap[x];
	heap[x] = heap[y];
	heap[y] = tm;
}

void Up(int k)
{
	while(k != 1 && a[heap[k>>1]] > a[heap[k]])
	{
		swap((k>>1),k);
		k >>= 1;
	}
}

void Down(int k)
{
	int j;
	while(heap[k<<1] + heap[(k<<1)+1] != 0)
	{
		j = k << 1;
		if(heap[j] == 0) j ++;
		if(a[heap[(k<<1)+1]] < a[heap[j]] && heap[(k<<1)+1] != 0)
			j = (k << 1) + 1;
		if(a[heap[j]] < a[heap[k]])
			swap(k,j);
		else break;
		k = j;
	}
}

void Add(int x)
{
	len ++;
	heap[len] = x;
	link[x] = len;
	Up(len);
}

void Del(int x)
{
	x = link[x];
	link[heap[len]] = x;
	heap[x] = heap[len];
	Down(x);
	Up(x);
	heap[len] = 0;
	len --;
}

int main()
{
	LL ans;
	int i,j,t,pos;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		len = 0;
		for(i = 1;i <= n;i ++)
			scanf("%lld",&a[i]);
		sort(a+1,a+n+1);
		n --;
		for(i = 1;i <= n;i ++)
		{
			a[i] = a[i+1] - a[i];
			pre[i] = i-1;
			next[i] = i+1;
			Add(i);
		}
		ans = 0;
		for(i = 1;i <= k;i ++)
		{
			pos = heap[1];
			ans += a[pos];
			if(pre[pos] != 0 && next[pos] <= n)
			{
				Del(pre[pos]);
				Del(next[pos]);
				Del(pos);
				a[pos] = a[pre[pos]] + a[next[pos]] - a[pos];
				a[pre[pos]] = INF;
				a[next[pos]] = INF;
				Add(pos);
				pre[pos] = pre[pre[pos]];
				next[pre[pos]] = pos;
				next[pos] = next[next[pos]];
				pre[next[pos]] = pos;
			}else{
				Del(pos);
				if(pre[pos] == 0)
				{
					Del(next[pos]);
					pre[next[next[pos]]] = 0;
				}else if(next[pos] == n+1)
				{
					Del(pre[pos]);
					next[pre[pre[pos]]] = n+1;
				}
			}
		}		
		printf("%lld\n",ans);
		memset(heap,0,sizeof(heap));
	}
	return 0;
}

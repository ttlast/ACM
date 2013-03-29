#include <iostream>
using namespace std;
const int maxn = 235;
const int maxe = 53000;
const int inf = 1000000;
int k,c,m;
int p[maxn][maxn];
struct Node{
	int v,d,next;
};
Node mat[maxe];
int eda[maxn],em,scur,sink,n,gap[maxn],h[maxn];
void init(int n){
	em = 0;
	int i;
	for(i = 0;i <= n;i ++) eda[i] = -1;
}
void insert(int u,int v,int d)
{
	mat[em].v = v;mat[em].d = d;
	mat[em].next = eda[u];
	eda[u] = em++;
	swap(u,v);
	mat[em].v = v;mat[em].d = 0;
	mat[em].next = eda[u];
	eda[u] = em++;
}
int dfs(int u,int d)
{
	int lv = d,minh = n-1,mind,v,j;
	if(u == sink) return d;
	for(j = eda[u];j != -1;j = mat[j].next)
	{
		v = mat[j].v;
		if(mat[j].d > 0)
		{
			if(h[v]+1 == h[u])
			{
				if(lv > mat[j].d) mind = mat[j].d;
				else mind = lv;
				mind = dfs(v,mind);
				mat[j].d -= mind;mat[j^1].d += mind;
				lv -= mind;
				if(h[scur] >= n) return d - lv;
				if(lv == 0) break;
			}
			if(h[v] < minh) minh = h[v];
		}
	}
	if(d == lv)
	{
		--gap[h[u]];
		if(gap[h[u]] == 0) h[scur] = n;
		h[u] = minh +1;
		++gap[h[u]];
	}
	return d - lv;
}
int isap(int st,int ed)
{
	int v = 0;
	scur = st;sink = ed;
	memset(h,0,sizeof(h));
	memset(gap,0,sizeof(gap));
	gap[st] = n;
	while(h[st] < n)
	{
		v += dfs(st,inf);
	}
	return v;
}
void build(int dis)
{
	int i,j;
	init(n);
	for(i = 0;i < k;i ++)
		insert(i,n,m);  //机器到终点
	for(i = k;i < n-1;i ++)
		insert(n-1,i,1);  //起点到牛
	for(i = 0;i < k;i ++)
		for(j = k;j < n-1;j ++)
			if(p[i][j] != 0 &&p[i][j] <= dis) insert(j,i,1);
}
void df()
{
	int l,r,mid,best;
	l = 1;r = inf;
	n++;
	while(l <= r)
	{
		mid = (l+r)>>1;
		build(mid);
		if(isap(n-1,n)>=c)
		{
		   best = mid;
		   r = mid-1;
		}else l = mid + 1;
	}
	printf("%d\n",best);
}
int main()
{
    int i,j,l;
    while(scanf("%d%d%d",&k,&c,&m)==3)
    {
       n = k+c;
       for(i = 0;i < n;i ++)
         for(j = 0;j < n;j ++) scanf("%d",&p[i][j]);
       for(i = 0;i < n;i ++)
          for(j = 0;j < n;j ++)
			if(j != i)
            for(l = 0;l < n;l ++)
				if(l != j&&l != i)
					if(p[j][i] != 0 && p[i][l] != 0 && (p[j][l] == 0||p[j][l] > p[j][i]+p[i][l]))
						p[j][l] = p[j][i]+p[i][l];
        df();
    }
    return 0;
}

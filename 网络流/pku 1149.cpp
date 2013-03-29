#include <iostream>
using namespace std;
const int maxn=1010;
const int maxe=4010;
const int inf = 1000000000;
struct Node{
	int v,d,next;
};
int g[1100];
Node mat[maxe];
int eda[maxn],em,scur,sink,n,m,gap[maxn],h[maxn],ph[maxn];
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
	n ++;
	gap[st] = n;  //总点数+1 
	while(h[st] < n)
	{
		v += dfs(st,inf);
	}
	return v;
}
int main()
{
    int i,j,k,v1,v,dm,dn,num;
    while(scanf("%d%d",&dm,&dn)==2)
    {
        n = dn+1;
        init(n);
        for(i = 0;i < dm;i ++) 
             scanf("%d",&ph[i]);
		memset(g,0,sizeof(g));
        for(i = 0;i < dn;i ++)
        {
           scanf("%d",&num);
           v = 0;
           for(j = 0;j < num;j ++) 
           {
               scanf("%d",&v1);
			   v1 --;
			   if(g[v1]) insert(g[v1]-1,i,inf);  //上一个连接到此点，不加入 
			   else                              //起点 
			   {
               v += ph[v1];
			   }
			   g[v1] = i+1;
           }
           insert(n-1,i,v);
		   //if(i+1 < dn) insert(dm+i,dm+i+1,inf);
           //for(j = i+1;j < dn;j ++) insert(dm+i,dm+j,inf);
           scanf("%d",&num);
           insert(i,n,num);
        }
        v = isap(n-1,n);
        printf("%d\n",v);
    }
    return 0;
}

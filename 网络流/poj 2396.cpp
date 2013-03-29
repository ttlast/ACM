#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
//上下限流
const int maxn = 250;
const int maxe=40000;
const int inf = 0x3fffffff;
struct Node{
	int v,d,next;
};
Node mat[maxe];
int eda[maxn],em,scur,sink,gap[maxn],h[maxn],ph[maxn],n;
//poj 2395
int dn,dm;
int row_hight[maxn],row_low[maxn],col_hight[maxn],col_low[maxn];
int mat_hight[205][25],mat_low[205][25],out[205][25],all;  //上下限必须
//
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
	gap[st] = n;
	while(h[st] < n)
	{
		v += dfs(st,inf);
	}
	return v;
}
bool check(){
	int i,j;
	memset(row_low,0,sizeof(row_low));
	memset(col_low,0,sizeof(col_low));
	for(i = 1;i <= dm;i ++)
	{
		for(j = 1;j <= dn;j ++)
		{
			if(mat_hight[i][j] < mat_low[i][j]) return false;
			row_low[i] += mat_low[i][j];
			col_low[j] += mat_low[i][j];
		}
		if(row_low[i] > row_hight[i]) return false;
	}
	for(j = 1;j <= dn;j ++) if(col_low[j] > col_hight[j]) return false;
	return true;
}
void build()
{
	int i,j;
	n = dm+dn+1;scur = 0;sink = n;
	init(n);
	for(i = 1;i <= dm;i ++)
		for(j = 1;j <= dn;j ++)
			insert(i,j+dm,mat_hight[i][j] - mat_low[i][j]);
	all = 0;
	for(i = 1;i <= dm;i ++)
	{
		j = row_hight[i] - row_low[i];
		all += j;
		insert(scur,i,j);
	}
	for(i = 1;i <= dn;i ++)
		insert(i+dm,sink,col_hight[i]-col_low[i]);
}
inline void renew(int a,int b,int d,char ch){
	if(ch == '<'){
		if(mat_hight[a][b] > d-1) mat_hight[a][b] = d-1;
	}else if(ch == '='){
		if(mat_low[a][b] < d) mat_low[a][b] = d;
		if(mat_hight[a][b] > d) mat_hight[a][b] = d;
	}else{
		if(mat_low[a][b] < d+1) mat_low[a][b] = d+1;
	}
}
int main()
{
	int t,i,j,k,c,a,b,d;
	char s;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&dm,&dn);
		for(i = 1;i <= dm;i ++){
			scanf("%d",&row_hight[i]);
			for(j = 1;j <= dn;j ++) mat_hight[i][j] = inf,mat_low[i][j] = 0;
		}
		for(i = 1;i <= dn;i ++){
			scanf("%d",&col_hight[i]);
		}
		scanf("%d",&c);
		for(i = 0;i < c;i ++)
		{
			scanf("%d%d %c%d",&a,&b,&s,&d);
			if(a == 0&& b == 0){
				for(j = 1;j <= dm;j ++)
					for(k = 1;k <= dn;k ++) renew(j,k,d,s);
			}else if(a == 0){
				for(j = 1;j <= dm;j ++) renew(j,b,d,s);
			}else if(b == 0){
				for(k = 1;k <= dn;k ++) renew(a,k,d,s);
			}else renew(a,b,d,s);
		}
		if(!check()){
			puts("IMPOSSIBLE");
			if(t) printf("\n");
			continue;
		}else{
			build();
			d = isap(0,n);
			if(all > d)
			{
				puts("IMPOSSIBLE");
				if(t) printf("\n");
				continue;
			}
			for(i = 1;i <= dm;i ++)
				for(j = eda[i];j != -1;j = mat[j].next)
				   if(mat[j].v > 0) //此处得判断是否远点交接。否则会溢出。
					out[i][mat[j].v-dm] = mat_low[i][mat[j].v-dm] + mat[j^1].d;
			for(i = 1;i <= dm;i ++)
			{
				printf("%d",out[i][1]);
				for(j = 2;j <= dn;j ++)
					printf(" %d",out[i][j]);
				printf("\n");
			}
		}
		if(t) printf("\n");
	}
	return 0;
}

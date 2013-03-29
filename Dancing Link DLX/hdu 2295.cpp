#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define eps 1e-7
#define inf 1418
const int maxn = 100;
struct Node{
	double x,y;
};
int n,m,k;
Node city[55],station[55];
int flag;
//模板原型部分来自hdu hh的模板
typedef long long LL;
#define FF(i,A,s) for(int i = A[s];i != s;i = A[i])
const int maxm = 10400;
struct DLX{
	int R[maxm],L[maxm],U[maxm],D[maxm];
	int col[maxm],row[maxm];
	int s[maxn];bool hash[maxn]; //重复覆盖
	int pre,first,sz,NV,limit;
	void init(int n)  //列的数目
	{
		int i;
		for(i = 0;i <= n;i ++)
		{
			U[i] = i;D[i] = i;
			col[i] = i;   //
			L[i] = i-1,R[i] = i+1;
		}
		NV = n;sz = n+1;pre = -1;first = 0;
		memset(s,0,sizeof(s));
	}
	void insert(int i,int j)    //一行一行的插入数据i行j列
	{
		if(i != pre)  //pre表示前一行，如果不同，就更新前面那行的左右
		{
			R[sz-1] = first;L[first] = sz -1;
			pre = i;first = sz;
		}
		L[sz] = sz - 1;R[sz] = sz+1;  //可以将j列看做矩阵的最底部.
		D[U[j]] = sz;
		D[sz] = j;U[sz] = U[j];U[j] = sz;
		row[sz] = i,col[sz] = j,s[j] ++;
		sz ++;
	}
	void finish() { R[sz-1] = first;L[first] = sz - 1;}
	void EXremove(int c){    //删除c列,而且与c有重复的行精确覆盖
		L[R[c]] = L[c];R[L[c]] = R[c];
		FF(i,D,c) FF(j,R,i) U[D[j]] = U[j],D[U[j]] = D[j],--s[col[j]];
	}
	void EXresume(int c){   //恢复c列,而且与c有重复的行
		FF(i,U,c) FF(j,L,i) ++s[col[j]],U[D[j]] = j,D[U[j]] = j;
		L[R[c]] = c;R[L[c]] = c;
	}
	//选择行，使每一列仅有一个
	bool dfs(const int &k) //精确覆盖，选择了k行了。
	{
		if(k >= flag) return false;
		if(R[0] == 0)
		{
			if(flag > k) flag = k;
			return true;
		}
		//if(R[0] == 0) return true; //找到解
		int idx = R[0],i;
		for(i = R[0] ;i != 0;i = R[i]) if(s[idx] > s[i]) idx = i;
		EXremove(col[idx]);
		FF(i,D,idx){
			FF(j,R,i) EXremove(col[j]);
			dfs(k+1);  //查找下一个。
			FF(j,L,i) EXresume(col[j]);
		}
		EXresume(col[idx]);
		return false;
	}
	//重复覆盖,选择最少行，所有的列被覆盖,后来添加的。
	void remove(int & c) { FF(i,D,c) L[R[i]] = L[i],R[L[i]] = R[i]; } //去掉某列
	void resume(int & c) { FF(i,U,c) L[R[i]] = i,R[L[i]] = i; }
	int h(){  //f启发函数
		int ret = 0;
		memset(hash,false,sizeof(hash));
		for(int c = R[0];c != 0;c = R[c]) if(!hash[c]){ //可以修改c !=  0部分
			hash[c] = true;  ret ++;
			FF(i,D,c)
				FF(j,R,i) hash[col[j]] = true;
		}
		return ret;
	}
	//重复覆盖，只删除列不删除行
	bool dfs(const int & k,int & limit)
	{
		if(k+h() > limit) return false;
		if(R[0] == 0)
		{
			if(k < limit) limit = k; return true;
		}
		int idx = R[0],i;
		for(i = R[0] ;i != 0;i = R[i]) if(s[idx] > s[i]) idx = i;
		FF(i,D,idx){
			remove(i);
			FF(j,R,i) remove(j);
			if(dfs(k+1,limit)) return true;
			FF(j,L,i) resume(j);
			resume(i);
		}
		return false;
	}
	int astar()  //or 二分。
	{
		limit = h();
		while(!dfs(0,limit)&&limit<=m) limit ++;  //修改点
		return limit;
	}
};
DLX dlx;
double dis[55][55],minr,maxr;
double dist(Node & p1,Node &p2)
{
	return sqrt((p1.x - p2.x)*(p1.x - p2.x)+(p1.y - p2.y)*(p1.y - p2.y));
}
void makegrap(double r)
{
	dlx.init(n);
	double d;
	int i,j;
	for(i = 0;i < m;i ++)
		for(j = 0;j < n;j ++)
		{
			if(r - dis[i][j] > -eps)
			{
				dlx.insert(i+1,j+1);
			}
		}
	dlx.finish();
}
void basearch()
{
	double l,r,mid,br;
	l = minr;r = br = maxr;
	while(r-l >= -eps)
	{
		mid = (l+r)/2.0;
		makegrap(mid);
		if(dlx.astar() <= k)
		{
		   br = mid;
		   r = mid-eps;
		}else l = mid+eps;
	}
	printf("%.6f\n",br);
}
int main()
{
	int t,i,j;
	int num = 0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(i = 0;i < n;i ++)
			scanf("%lf%lf",&city[i].x,&city[i].y);
		for(i = 0;i < m;i ++)
			scanf("%lf%lf",&station[i].x,&station[i].y);
		maxr = 0;minr = inf;
		for(i = 0;i < m;i ++)
			for(j = 0;j < n;j ++)
			{
				dis[i][j] = dist(station[i],city[j]);
				if(dis[i][j] < minr) minr = dis[i][j];
				if(dis[i][j] > maxr) maxr = dis[i][j];  //此处写错了，wa了n次
			}
		basearch();
	}
	return 0;
}
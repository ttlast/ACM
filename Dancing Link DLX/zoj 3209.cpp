#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int inf = 100000000;
int flag;
//模板原型来自hdu hh
typedef long long LL;
#define FF(i,A,s) for(int i = A[s];i != s;i = A[i])
const int maxm = 1000400;
const int maxn = 906;
struct DLX{
	int R[maxm],L[maxm],U[maxm],D[maxm];
	int col[maxm],row[maxm];
	int s[maxn];bool hash[maxn]; //重复覆盖
	int pre,first,sz,NV;
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
	void insert(int i,int j)    //一行一行的插入数据
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
	void EXremove(int c){    //删除c列,而且与c有重复1的行 精确覆盖
		L[R[c]] = L[c];R[L[c]] = R[c];
		FF(i,D,c) FF(j,R,i) U[D[j]] = U[j],D[U[j]] = D[j],--s[col[j]];
	}
	void EXresume(int c){   //恢复c列,而且与c有重复1的行
		FF(i,U,c) FF(j,L,i) ++s[col[j]],U[D[j]] = j,D[U[j]] = j;
		L[R[c]] = c;R[L[c]] = c;
	}
	void remove(int & c) { FF(i,D,c) L[R[i]] = L[i],R[L[i]] = R[i]; } //去掉某列
	void resume(int & c) { FF(i,U,c) L[R[i]] = i,R[L[i]] = i; }
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
};
DLX dlx;
int map[maxn][maxn];
int n,m,p,M,sm,nt;
void addrow(int row,int x1,int y1,int x2,int y2)
{
	int i,j;
	if(sm){
		for(i = x1+1;i <= x2;i ++)
			for(j = y1;j < y2;j ++)
				map[row][j*n+i] = nt;
	}else{
		for(i = x1;i < x2;i ++)
			for(j = y1+1;j <= y2;j ++)
				map[row][i*m+j] = nt;
	}
}
int main()
{
	int t,i,j,x1,y1,x2,y2;
	nt = 0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&p);
		nt ++;
		if(n > m) sm = 1;
		else sm = 0;
		M = n*m;
		dlx.init(M);
		for(i = 1;i <= p;i ++)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			addrow(i,x1,y1,x2,y2);
		}
		for(i = 1;i <= p;i ++) 
		{
			for(j = 1;j <= M;j ++)
			{
				if(map[i][j] == nt)
				{
					dlx.insert(i,j);
				}
			}
		}
		dlx.finish();
		flag = inf;
		dlx.dfs(0);
		if(flag != inf) printf("%d\n",flag);
		else printf("-1\n");
	}
	return 0;
}

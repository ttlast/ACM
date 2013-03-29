#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int inf = 100000000;
int flag;
//模板原型部分来自hdu hh的模板
typedef long long LL;
#define FF(i,A,s) for(int i = A[s];i != s;i = A[i])
const int maxm = 804000;
const int maxn = 400;
int used[1400],sr[1400];
int sign[400];
int n,m,d;
int map[100][100];
int si[1300],ei[1300];
void init()
{
	memset(used,0,sizeof(used));
	memset(sign,0,sizeof(sign));
}

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
		//if(k >= flag) return false;
		if(flag) return true;
		if(R[0] == 0||R[0] > n*d)
		{
			//if(flag > k) flag = k;
			flag = 1;
			return true;
		}
		//if(R[0] == 0) return true; //找到解
		int idx = R[0],i;
		for(i = R[0] ;i != 0&&i <= n*d;i = R[i]) if(s[idx] > s[i]) idx = i;
		EXremove(col[idx]);
		FF(i,D,idx){
			used[row[i]] = 1;
			FF(j,R,i) EXremove(col[j]);
			if(dfs(k+1)) return true;  //查找下一个。
			FF(j,L,i) EXresume(col[j]);
			used[row[i]] = 0;
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
		if(k+h() >= limit) return false;
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
		while(!dfs(0,limit)) limit ++;  //修改点，limit最后期限
		return limit;
	}
};
DLX dlx;

int main()
{
	int i,j,k,l1,l2,a,b,nt = 0,row;
	while(scanf("%d%d%d",&n,&m,&d)!=EOF)
	{
		init();
		nt ++;
		dlx.init(n*(d+1));
		for(i = 0;i < m;i ++)
		{
			scanf("%d%d",&a,&b);
			map[a][b] = map[b][a] = nt;
		}
		/*You can choose a sub-range of the available range as the working time for each station.
		Note that you can only choose one sub-range for each available range,
		that is, once the station stops working, you cannot restart it again.
		Of course, it is possible not to use any of them.
		*/
		//第一次wa，忘记看次标语了.
		row = 1;
		for(i = 1;i <= n;i ++)
		{
			scanf("%d%d",&a,&b); //每一个村庄电机开放时间
			for(k = a;k <= b;k ++)
			{
				for(j = k;j <= b;j ++)
				{
					dlx.insert(row,n*d+i); //连接自己，确保只给选一次
					for(l1 = k;l1 <= j;l1 ++)
					{
						dlx.insert(row,(l1-1)*n+i);
						for(l2 = 1;l2 <= n;l2 ++)
						 if(map[i][l2] == nt) dlx.insert(row,(l1-1)*n+l2);
					}
					sr[row] = i;
					si[row] = k;
					ei[row++] = j;
				}
			}
		}
		dlx.finish();
		flag = 0;
		if(dlx.dfs(0))
		{
		for(i = 1;i < row;i ++)
		{
			if(used[i]) sign[sr[i]] = i;
		}
		for(i = 1;i <= n;i ++)
			if(sign[i]) printf("%d %d\n",si[sign[i]],ei[sign[i]]);
			else puts("0 0");
		}else puts("No solution");
		printf("\n");
	}
	return 0;
}
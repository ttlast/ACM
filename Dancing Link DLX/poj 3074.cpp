#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 100000000;
int flag;
typedef long long LL;
#define FF(i,A,s) for(int i = A[s];i != s;i = A[i])
const int maxm = 400400;
const int maxn = 906;
int used[maxn];
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
		if(flag) return true;
		//if(k >= flag) return false;
		if(R[0] == 0)
		{
			//if(flag > k) flag = k;
			flag = 1;
			return true;
		}
		//if(R[0] == 0) return true; //找到解
		int idx = R[0],i;
		for(i = R[0] ;i != 0;i = R[i]) if(s[idx] > s[i]) idx = i;
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
char c[100];
int map[730];
int main()
{
	int i,j,k,pos,row,cnt;
	while(gets(c))
	{
		if(c[0] == 'e') break;
		dlx.init(324);
		row = 1;
		memset(used,0,sizeof(used));
		for(i = 0;i < 9;i ++)
			for(j = 0;j < 9;j ++)
			{
				if(c[i*9+j] == '.'){
					for(k = 1;k <= 9;k ++)
					{
						dlx.insert(row,i*9+k);  //行+数字
						dlx.insert(row,81+j*9+k); //列+数
						dlx.insert(row,162+(i/3+(j/3)*3)*9+k); //小方块号号
						dlx.insert(row,243+i*9+j+1); //座位
						map[row++] = k;
					}
				}else{
					cnt = c[i*9+j] - '0';
					dlx.insert(row,i*9+cnt);  //行+数字
					dlx.insert(row,81+j*9+cnt); //列+数
					dlx.insert(row,162+(i/3+(j/3)*3)*9+cnt); //小方块号
					dlx.insert(row,243+i*9+j+1); //座位
					map[row++] = cnt;
				}
			}
			dlx.finish();
			flag = 0;
			if(dlx.dfs(0))
			{
			for(i = 0;i < row;i ++)
				if(used[i]) printf("%d",map[i]);
			printf("\n");
			}else puts("NO");
	}
	return 0;
}
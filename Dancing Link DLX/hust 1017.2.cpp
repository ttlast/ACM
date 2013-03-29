#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxn = 1001;
int Num(int r,int c)
{
	return r*1000+c;
}
struct Node
{
	int L,R,U,D,Sum,r,c;
}d[maxn*maxn];
int head = 0,flag;  //初始化flag = 0;
int stack[maxn],top;
void remove(const int &c) //exact cover ，去掉有相同的1.
{
	int i,j;
	for(i = d[c].D;i != c;i = d[i].D)
		for(j = d[i].R;j != i;j = d[j].R)
		{
			d[d[j].c].Sum --;
			d[d[j].U].D = d[j].D;
			d[d[j].D].U = d[j].U;
		}
	d[d[c].R].L = d[c].L;
	d[d[c].L].R = d[c].R;
}
void resume(const int &c)
{
	int i,j;
	for(i = d[c].U;i != c;i = d[i].U)
		for(j = d[i].L;j != i;j = d[j].L)
		{
			d[d[j].c].Sum ++;
			d[d[j].U].D = j;
			d[d[j].D].U = j;
		}
	d[d[c].R].L = c;
	d[d[c].L].R = c;
}
bool DLX(const int &k)
{
	int i,j,l,m;
	if(flag) return true;
	if(d[head].R == head)//矩阵为空，找到了解,自己添加内容
	{
		flag = 1;
		printf("%d",top);
		for(i = 0;i < top;i ++) printf(" %d",stack[i]);
		printf("\n");
		return true;
	}
	int c,mind = INT_MAX;
	for(i = d[head].R;i != head;i = d[i].R)
		if(d[d[i].c].Sum < mind) mind = d[d[i].c].Sum ,c = i;
	remove(c);              //dlx优化搜索的一步贪心，可以看做是一个标记
	for(i = d[c].D;i != c;i = d[i].D)
	{
		stack[top++] = d[i].r;         //选择第i 行,删去与它在相同列有1的列。
		for(j = d[i].R;j != i;j = d[j].R)
			remove(d[j].c);
		if(DLX(k+1)) return true;
		for(j = d[i].L;j != i;j = d[j].L)
			resume(d[j].c);
		top --;
	}
	resume(c);
	return false;
}
//初始化head = 0; d[head].R = 1;
int map[maxn][maxn],n,m,tmp[maxn];
int main()
{
	int i,j,k,t = 0,st,ed,mid;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		t ++;
		for(i = 1;i <= n;i ++)
		{
			scanf("%d",&k);
			for(j = 0;j < k;j ++)
			{
				scanf("%d",&tmp[j]);
				map[i][tmp[j]] = t;
			}
			st = Num(i,tmp[0]);
			ed = Num(i,tmp[k-1]);
			d[st].r = i;
			d[st].c = tmp[0];
			d[st].L = ed;
			for(j = 1;j < k;j ++)
			{
				mid = Num(i,tmp[j]);
				d[mid].r = i;d[mid].c = tmp[j];
				d[mid].L = Num(i,tmp[j-1]);
				d[Num(i,tmp[j-1])].R = mid;
			}
			d[ed].R = st;			
		}
		head = 0;
		d[head].R = 1;
		for(i = 1;i <= m;i ++)
		{
			st = Num(0,i);
			if(i+1 <= m) d[st].R = Num(0,i+1);
			else d[st].R = 0;
			d[st].L = Num(0,i-1);
			d[st].Sum = 0;
			d[st].r = 0; d[st].c = i;
			ed = st;
			for(j = 1;j <= n;j ++)
			{
				if(map[j][i] == t)
				{
					d[ed].Sum ++;
					mid = Num(j,i);
					d[st].D = mid;
					d[mid].U = st;
					st = mid;
				}
			}
			d[st].D = ed;
			d[ed].U = st;
			if(!d[ed].Sum)
			{
				puts("NO");
				break;
			}
		}
		if(i > m)
		{
			flag = top = 0;
			DLX(0);
			if(!flag) puts("NO");
		}
	}
	return 0;
}
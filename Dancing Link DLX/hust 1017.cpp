#include <iostream>
using namespace std;
const int maxn = 1005;
struct Node
{
	int L,R,U,D,Sum,x,y;
};
Node p[maxn*maxn];
int n,m;
int map[maxn][maxn];
int flag;
int stack[maxn],top,so[maxn];
int Num(int x,int y){
	return x*1000+y;
}
//删除c col
void CoverCol(int c)
{
	int i,j;
	p[p[c].R].L = p[c].L;
	p[p[c].L].R = p[c].R;
	i = c;
	for(i = p[i].D;i != c;i = p[i].D)
	{
		j = i;
		p[p[i].y].Sum --;
		for(j = p[j].R;j != i;j = p[j].R) //去掉一行
		{
			p[p[j].D].U = p[j].U;
			p[p[j].U].D = p[j].D;
		}
	}
}
void Release(int c)
{
	int i,j;
	p[p[c].R].L = c;
	p[p[c].L].R = c;
	i = c;
	for(i = p[i].U;i != c;i = p[i].U)
	{
		j = i;
		p[p[i].y].Sum ++;
		for(j = p[j].L;j != i;j = p[j].L)
		{
			p[p[j].D].U = j;
			p[p[j].U].D = j;
		}
	}
}
int dfs(int k)
{
	int i,j,l,m;
	if(flag) return 1;

	//链表为空，输出解
	if(p[0].R == 0)
	{
		printf("%d",top);
		for(i = 0;i < top;i ++)
			printf(" %d",stack[i]);
		printf("\n");
		flag = 1;
		return 1;
	}
	int c = 0,min = INT_MAX;
	i = c;
	for(i = p[i].R;i;i = p[i].R)   //贪心选择最小的。
	{
		if(p[p[i].y].Sum < min)
		{
			min = p[p[i].y].Sum;
			c = i;
		}
	}
	CoverCol(c);
	i = c;
	for(i = p[i].D;i != c;i = p[i].D)  //枚举每一行有1的
	{
		stack[top++] = p[i].x;
		j = i;
		for(j = p[j].R;j != i;j = p[j].R)
			CoverCol(p[j].y);
		if(dfs(k+1)) return 1;
		j = i;
		for(j = p[j].L;j != i;j = p[j].L)
			Release(p[j].y);
		top --;
	}

	Release(c);
	return 0;
}
int main()
{
	int t = 0,k;
	int i,j,lef,rig,cur,last,now;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		t ++;
		for(i = 1;i <= n;i ++)
		{
			scanf("%d",&k);
			for(j = 0;j < k;j ++)
			{
				scanf("%d",&so[j]);
				map[i][so[j]] = t;
			}
			lef = Num(i,so[0]);
			rig = Num(i,so[k-1]);
			p[lef].L = rig;
			p[lef].x = i;
			p[lef].y = so[0];
			for(j = 1;j < k;j ++)
			{
				cur = Num(i,so[j]);
				p[Num(i,so[j-1])].R = cur;
				p[cur].L = Num(i,so[j-1]);
				p[cur].x = i;
				p[cur].y = so[j];
			}
			p[rig].R = lef;
		}
		p[0].R = 1;
		for(i = 1;i <= m;i ++)
		{
			cur = Num(0,i);
			if(i+1 <= m) p[cur].R = Num(0,i+1);
			else p[cur].R = 0;
			p[cur].L = Num(0,i-1);
			p[cur].x = 0;p[cur].y = i;
			p[cur].Sum = 0;
			last = cur;
			for(j = 1;j <= n;j ++)
			{
				if(map[j][i] == t)
				{
					p[last].Sum ++;
					now = Num(j,i);
					p[cur].D = now;
					p[now].U = cur;
					cur = now;
				}
			}
			p[cur].D = last;
			p[last].U = cur;
			if(!p[last].Sum)
			{
				puts("NO");
				break;
			}
		}
		if(i > m)
		{
			flag = top = 0;
			dfs(0);
			if(!flag) puts("NO");
		}
	}
	return 0;
}
#include <iostream>
#include <queue>
using namespace std;
const int maxn = 24;
int n,m,t;
int key[] = {1,2,4,8,16,32,64,128,256,512};
bool sign[maxn][maxn][1034];
char c[maxn][maxn];
int dir[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
struct Node
{
	int x,y,key,ncount;
};
Node st;
bool safe(int x,int y)
{
	if(x>= 0 && x<n && y>=0 && y<m && c[x][y] != '*') return true;
	return false;
}
void bfs()
{
	int i,j,x,y,index;
	Node mq,tm;
	queue<Node> q;
	st.key = st.ncount = 0;
	q.push(st);
	while(!q.empty())
	{
		tm = q.front();q.pop();
		if(tm.ncount >= t) break;
		if(c[tm.x][tm.y] == '^') 
		{
			printf("%d\n",tm.ncount);
			return ;
		}
		for(i = 0;i < 4;i ++)
		{
			x = tm.x+dir[i][0];
			y = tm.y+dir[i][1];
			if(safe(x,y)&&(!sign[x][y][tm.key]))
			{
				if(c[x][y] >= 'A' && c[x][y] <= 'J')
				{
				  index = c[x][y] - 'A';
				  if((tm.key&key[index]) != 0)
				  {
					  mq.x = x; mq.y = y; mq.key = tm.key; mq.ncount = tm.ncount+1;
					  q.push(mq);
					  sign[x][y][mq.key] = true;
				  }
				}else if(c[x][y] >= 'a' && c[x][y] <= 'j')
				{
				  index = c[x][y] - 'a';
				  if(!(tm.key&key[index])) mq.key = tm.key+key[index]; //少了这句，wa了n次。
				  else mq.key = tm.key;
				  mq.x = x; mq.y = y; mq.ncount = tm.ncount+1;
				  q.push(mq);
				  sign[x][y][mq.key] = true;
				}else
				{
				   mq.x = x;mq.y = y;mq.key = tm.key;mq.ncount = tm.ncount+1;
				   q.push(mq);
				   sign[x][y][mq.key] = true;
				}
			}
		}
	}
	printf("-1\n");
}
int main()
{
	int i,j;
	while(scanf("%d%d%d",&n,&m,&t)!=EOF)
	{
	   for(i = 0;i < n;i ++)
	   {
		   scanf("%s",c[i]);
	   }
	   for(i = 0;i < n;i ++)
			for(j = 0;j < m;j ++)
				if(c[i][j] == '@')
				{
					st.x = i;st.y = j;
					break;
				}
	   memset(sign,false,sizeof(sign));
	   bfs();
	}
	return 0;
}

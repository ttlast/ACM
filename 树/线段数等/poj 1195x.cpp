#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define Max 1100
int Tree[Max*3][Max*3];
int s;

void Add_y(int rootx,int rooty,int L,int R,int y,int a)
{
	Tree[rootx][rooty] += a;
	if(L == R) return ;
	int mid = (L+R)>>1;
	if(y <= mid)
		Add_y(rootx,rooty<<1,L,mid,y,a);
	else 
		Add_y(rootx,(rooty<<1)+1,mid+1,R,y,a);
}

void Add_x(int rootx,int L,int R,int x,int y,int a)
{
	Add_y(rootx,1,0,s,y,a);
	if(L == R) return ;
	int mid = (L+R)>>1;
	if(x <= mid)
		Add_x(rootx<<1,L,mid,x,y,a);
	else
		Add_x((rootx<<1)+1,mid+1,R,x,y,a);

}

int Queue_y(int rootx,int rooty,int L,int R,int y1,int y2)
{
	if(L >= y1 && R <= y2)
		return Tree[rootx][rooty];
	else{
		int mid = (L+R)>>1;
		if(y2 <= mid)
			return Queue_y(rootx,rooty<<1,L,mid,y1,y2);
		else if(y1 > mid)
			return Queue_y(rootx,(rooty<<1)+1,mid+1,R,y1,y2);
		else{
			return Queue_y(rootx,rooty<<1,L,mid,y1,y2) + Queue_y(rootx,(rooty<<1)+1,mid+1,R,y1,y2);
		}
	}
}

int Queue_x(int rootx,int L,int R,int x1,int y1,int x2,int y2)
{
	if(L >= x1 && R <= x2)
		return Queue_y(rootx,1,0,s,y1,y2);
	else{
		int mid = (L+R)>>1;
		if(x2 <= mid)
			return Queue_x(rootx<<1,L,mid,x1,y1,x2,y2);
		else if(x1 > mid)
			return Queue_x((rootx<<1)+1,mid+1,R,x1,y1,x2,y2);
		else{
			return Queue_x(rootx<<1,L,mid,x1,y1,x2,y2) + Queue_x((rootx<<1)+1,mid+1,R,x1,y1,x2,y2);
		}
	}
}

int main()
{
	int sign,x,y,a,x1,y1,x2,y2,sum;
	while(scanf("%d",&sign)!=EOF)
	{
		if(sign == 0)
		{
			scanf("%d",&s);
			s --;
		}
		else if(sign == 1)
		{
			scanf("%d%d%d",&x,&y,&a);
			Add_x(1,0,s,x,y,a);
		}
		else if(sign == 2)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			sum = Queue_x(1,0,s,x1,y1,x2,y2);
			printf("%d\n",sum);
		}
		else break;
	}
	return 0;
}
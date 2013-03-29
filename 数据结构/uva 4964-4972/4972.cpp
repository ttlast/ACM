#include<stdio.h>
#include<string.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
typedef long long ll;
int dblcmp(int d)
{
	if (d>0)return 1;
	else if (d==0)return 0;
	return -1;
}
struct point 
{
	int x,y;
	point(){}
	point(int _x,int _y)
	{
		x=_x;
		y=_y;
	}
	void input()
	{
		scanf("%d%d",&x,&y);
	}
	point sub(point b)
	{
		return point(x-b.x,y-b.y);
	}
	int det(point b)
	{
		return x*b.y-y*b.x;
	}
	int dot(point b)
	{
		return x*y+b.x*b.y;
	}
};
struct line 
{
	point a,b;
	line(){}
	line(point _a,point _b)
	{
		a=_a;
		b=_b;
	}
	int sect(line v)
	{
		int d1=dblcmp(b.sub(a).det(v.a.sub(a)));
		int d2=dblcmp(b.sub(a).det(v.b.sub(a)));
		int d3=dblcmp(v.b.sub(v.a).det(a.sub(v.a)));
		int d4=dblcmp(v.b.sub(v.a).det(b.sub(v.a)));
		if ((d1^d2)==-2&&(d3^d4)==-2)return 2;
		return 0;
		return (d1==0&&dblcmp(v.a.sub(a).dot(v.a.sub(b)))<=0||
				d2==0&&dblcmp(v.b.sub(a).dot(v.b.sub(b)))<=0||
				d3==0&&dblcmp(a.sub(v.a).dot(a.sub(v.b)))<=0||
				d4==0&&dblcmp(b.sub(v.a).dot(a.sub(v.b)))<=0);
	}
};		
point p[11];
int a[11][11];
int main()
{
	//line u(point(0,1),point(2,1));
	//line v(point(1,2),point(1,0));
	//printf("%d\n",u.sect(v));
	int i,j,k,cc=0;
	int n,c;
	while (scanf("%d%d",&n,&c)!=EOF)
	{
		if (n==0&&c==0)break;
		for (i=0;i<n;i++)
		{
			p[i].input();
		}
		for (i=0;i<n;i++)
		{
			for (j=0;j<n;j++)scanf("%d",&a[i][j]);
		}
		int z[11];
		for (i=0;i<n;i++)z[i]=i;
		int ans=1<<30;
		line l[11];
		do 
		{
			int sum=0;
			for (i=0;i<n;i++)
			{
				sum+=a[z[i]][z[(i+1)%n]];
			}
			for (i=0;i<n;i++)
			{
				//sum+=a[p[i]][p[i+1]];
				l[i]=line(p[z[i]],p[z[(i+1)%n]]);
			}
			for (i=0;i<n;i++)
			{
				for (j=i+1;j<n;j++)
				{
					if (l[i].sect(l[j]))sum+=c;
				}
			}
			//printf("%d\n",sum);
			//if (sum==9)
			//{
				//printf("%d %d %d %d\n",z[0],z[1],z[2],z[3]);
			//}
			//system("pause");
			ans=min(ans,sum);
		}
		while (next_permutation(z,z+n));
		printf("%d. %d\n",++cc,ans);
	}
	return 0;
}
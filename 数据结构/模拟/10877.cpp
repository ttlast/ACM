#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 1005;

struct Node{
	int a,b,c,d,f,e;
	Node(){
	};
	void set(int ca,int cb,int cc,int cd,int cf,int ce)
	{
		a = ca;b = cb;c = cc;d = cd;f = cf;e = ce;
	}
	
	void right(){
		int tmp;
		tmp = b;
		b = e;e = f;f = c;
		c = tmp;
	}
	void tright(){
		int tmp;
		tmp = a;
		a = b; b = d; d = f;
		f = tmp;
	}

	void tleft()
	{
		int tmp;
		tmp = a;
		a = c;  c = d; d = e;
		e = tmp;
	}
	bool same(const Node t1)
	{
		if(a == t1.a && b == t1.b && c == t1.c && d == t1.d && e == t1.e && f == t1.f)
			return true;
		return false;
	}
};
int n,len;
Node mat[maxn];

bool pepei(Node t1)
{
	int i,j,k;
	for(i = 0;i <len;i ++)
	{
		for(j = 0;j < 4;j ++)
		{
			for(k = 0;k < 4;k ++)
			{
				if(mat[i].same(t1)) break;
				t1.right();
			}
			if(k < 4) break;
			t1.tleft();
		}
		if(j < 4) break;
		for(j = 0;j < 4;j ++)
		{
			for(k = 0;k < 4;k ++)
			{
				if(mat[i].same(t1)) break;
				t1.right();
			}
			if(k < 4) break;
			t1.tright();
		}
		if(j < 4) break;
	}

	if(i >= len) return false;
	return true;
}
int main()
{
	int i,j,k;
	Node tmp;
	while(scanf("%d",&n),n)
	{
		len = 0;
		for(i = 0;i < n;i ++)
		{
			scanf("%d%d%d%d%d%d",&tmp.a,&tmp.b,&tmp.c,&tmp.d,&tmp.e,&tmp.f);
			if(!pepei(tmp))
			{
				mat[len] = tmp;
				len ++;
			}
		}
		printf("%d\n",len);
	}
	return 0;
}
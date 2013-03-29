#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 300;

char c[maxn];
struct Node{
	char x[6];
	void build(char *c)
	{
		for(int i = 0;i < 6;i ++)
			x[i] = *(c+i);
	}
	bool eq(const Node & t2)
	{
		int i;
		for(i = 0;i < 6;i ++)
			if(x[i] != t2.x[i]) return false;
		return true;
	}
	void tleft_rotate()
	{
		int tmp;
		tmp = x[0];
		x[0] = x[3];
		x[3] = x[5];
		x[5] = x[2];
		x[2] = tmp;
	}
	void left_rotate()
	{
		int tmp;
		tmp = x[1];
		x[1] = x[3];
		x[3] = x[4];
		x[4] = x[2];
		x[2] = tmp;
	}
	void up_rotate()
	{
		int tmp;
		tmp = x[0];
		x[0] = x[1];
		x[1] = x[5];
		x[5] = x[4];
		x[4] = tmp;
	}
};
Node a,b;

bool issame()
{
	int i,j,k;
	if(b.eq(a)) return true;
	for(i = 0;i < 4;i ++)
	{
		for(j = 0;j < 4;j ++)
		{
			b.left_rotate();
			if(b.eq(a)) return true;
		}
		b.up_rotate();
		if(b.eq(a)) return true;
	}
	for(i = 0;i < 4;i ++)
	{
		for(j = 0;j < 4;j ++)
		{
			b.left_rotate();
			if(b.eq(a)) return true;
		}
		b.tleft_rotate();
		if(b.eq(a)) return true;
	}
	return false;
}
int main()
{
	int i,j;
	while(gets(c))
	{
		a.build(c);
		b.build(c+6);
		if(issame()) printf("TRUE\n");
		else printf("FALSE\n");
	}
	return 0;
}
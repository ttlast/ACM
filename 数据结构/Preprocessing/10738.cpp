#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1000005;
const int mprim = 1005;
bool nprim[mprim];
int prim[mprim],len;
void init()
{
	int i,j;
	prim[0] = 2;
	len = 1;
	for(i = 4;i < mprim;i += 2)
		nprim[i] = true;
	for(i = 3;i < mprim;i += 2)
	{
		if(!nprim[i])
		{
			prim[len++] = i;
			for(j = i*i;j < mprim;j += i)
				nprim[j] = true;
		}
	}
}
int check(int n)
{
	int ans = 0,t,i;
	for(i = 0;i < len;i ++)
	{
		if(n%prim[i] == 0)
		{
			ans ++;
			t = 0;
			while(n%prim[i] == 0)
			{
				t ++;
				n /= prim[i];
			}
			if(t >= 2) return 0;
		}
	}
	if(n > 1) ans ++;
	if(ans&1)  return -1;
	else return 1;
}
int mu[maxn],m[maxn];
int main()
{
	int n,i,j;
	init();
	mu[1] = m[1] = 1;
	for(i = 2;i < maxn;i ++)
	{
		mu[i] = check(i);
		m[i] = m[i-1] + mu[i];
	}
	while(scanf("%d",&n),n)
	{
		printf("%8d%8d%8d\n",n,mu[n],m[n]);
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
#define lowbit(x) ((x)&(-x))
const int maxk = 2010;
const int maxn = 201000;

char c[maxn];
int dp[26][maxk],k;
int num[26];

void add(int c,int p)
{
	while(p <= k)
	{
		dp[c][p] += 1;
		p += lowbit(p);
	}
}

int sum(int c,int p)
{
	int ans = 0;
	while(p > 0)
	{
		ans += dp[c][p];
		p -= lowbit(p);
	}
	return ans;
}

int main()
{
	int len,i,j,l,n,p,pos,zm,s;
	char ci[3];
	scanf("%d",&k);
	scanf("%s",c);

	l = strlen(c);
	for(i = 0;i < l;i ++)   //原始各种字母有多少个
		num[c[i]-'a'] ++;
	len = l*k;
	for(i = l;i < len;i ++)
		c[i] = c[i-l];
	c[len] = '\0';
	

	//chuli
	scanf("%d",&n);
	for(i = 0;i < n;i ++)
	{
		scanf("%d %s",&p,ci);
		zm = ci[0] - 'a';
		pos = (p-1)/num[zm] + 1;
		while(1)
		{
			s = sum(zm,pos);
			if(p+s > num[zm]*pos)  pos ++;
			else break;
		}
		s = sum(zm,pos-1);
		p = p+s - num[zm]*(pos-1);
		for(j = l*(pos-1);;j ++)
		{
			if(c[j] - 'a' == zm)
			{
			      p --;
				  if(p == 0)
				  {
					  c[j] = '0';
					  break;
				  }
			}
		}
		add(zm,pos);
	}
	for(i = 0;i < len;i ++)
		if(c[i] != '0') printf("%c",c[i]);
	printf("\n");
	return 0;
}
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 10;
string s;

int num;
map<string,int> mm;
char c[maxn];

void dfs(int i,int len)
{
	if(i == len)
	{
		c[len] = '\0';
		s = c;
		mm[s] = ++num;
		return ;
	}
	if(i == 0)
		c[i] = 'a';
	else
		c[i] = c[i-1] + 1;
	for(;c[i] <= 'z';c[i] ++)
	{
		dfs(i+1,len);
	}
}
int main()
{
	num = 0;
	dfs(0,1);
	dfs(0,2);
	dfs(0,3);
	dfs(0,4);
	dfs(0,5);
	while(cin>>s)
	{
		cout<<mm[s]<<endl;
	}
	return 0;
}
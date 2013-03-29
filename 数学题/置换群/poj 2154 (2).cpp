#include <iostream>
using namespace std;
const int maxn = 32000;
int n,m,tmp;
int p[maxn],num,a[400],b[400],ans;
bool sign[maxn];
void init()
{
	int i,j;
	num = 0;
	p[num++] = 2;
	for(i = 4;i < maxn;i += 2) sign[i] = true;
	for(i = 3;i < maxn;i ++)
	{
		if(!sign[i])
		{
			p[num++] = i;
			for(j = i*i;j < maxn;j += i)
				sign[j] = true;
		}
	}
}
void factor(int x)
{
	int i;
	tmp = 0;
	for(i = 0;i < num;i ++)
	{
		if(x < p[i]) break;
		if(x%p[i] == 0)
		{
			b[tmp] = 0;
			while(x%p[i] == 0)
			{
				x /= p[i];
				b[tmp]++;
			}
			a[tmp++] = p[i];
		}
	}
	if(x > 1) b[tmp] = 1,a[tmp++] = x;  //没有这一句就wa的？奇怪！ 
}
int euler(int x)
{
	int ret = x,i;
	for(i = 0;i < num;i ++)
	{
		if(x < p[i]) break;
		if(x%p[i] == 0)
		{
			while(x%p[i] == 0) x /= p[i];
			ret -= ret/p[i];
		}
	}
	if(x > 1) ret -= ret/x;
	return ret;
}
int pow_m(int a,int b)
{
	int ret = 1,t = a%m;
	while(b)
	{
		if(b&1) ret = (ret*t)%m;
		t = (t*t)%m;
		b >>= 1;
	}
	return ret;
}
void dfs(int dep,int sum)
{
	int i,temp;
	if(dep == tmp)
	{
		ans = (ans + (euler(n/sum)%m)*pow_m(n,sum-1))%m;
	}else
	{
		for(i = 0,temp = 1;i <= b[dep];temp*=a[dep],i ++)
			dfs(dep+1,sum*temp); 
	}
}
int main()
{
	int x;
	init();
	scanf("%d",&x);
	while(x--)
	{
		scanf("%d%d",&n,&m);
		factor(n);
		ans = 0;
		dfs(0,1);
		printf("%d\n",ans);
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>
#include <cstdlib>
using namespace std;
#define lowbit(x) ((x)&(-x))
const int maxn = 100000;
const int mod = 1000100007;  //离散化 + 唉，这个素数靠rp的。
typedef long long LL;
char c[2000006];
set <int>hash;
int p[maxn+10];
void build_hash(char * s)
{
	int hs = 0,i = 0;
	while(i < maxn && s[i])
	{
		hs = (hs + (LL)(s[i]-'a'+1)*p[i]%mod)%mod;
		i ++;
	}
	if(i >= maxn) return ;
	hs = ((LL) hs*p[maxn])%mod;
	if(hash.find(hs) == hash.end())
		hash.insert(hs);
}
int num[maxn+10],cl;
void insert(int i,int a)
{
	a %= mod;
	if(a < 0) a = (a+mod)%mod;
	while(i <= cl)
	{
		num[i] = (num[i]+a)%mod;
		i += lowbit(i);
	}
}
int sum(int i)
{
	int sl = 0;
	while(i > 0)
	{
		sl = (sl + num[i])%mod;
		i -= lowbit(i);
	}
	return sl;
}
int main()
{
	int i;
	char com[5];
	int t,n,ncase = 1,d,a,b;
	p[0] = 1;
	for(i = 1;i <= maxn;i ++)
		p[i] = ((LL) p[i-1]*27)%mod;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		hash.clear();
		for(i = 0;i < n;i ++)
		{
			scanf("%s",c);
			build_hash(c);
		}
		scanf("%s",c);
		cl = strlen(c);
		
		for(i = cl-1;i >= 0;i --)
		{
			num[i+1] = 0;
			insert(i+1,((LL)(c[i]-'a'+1)*p[i])%mod);
		}
		printf("Case #%d:\n",ncase ++);
		scanf("%d",&d);
		for(i = 0;i < d;i ++)
		{
			scanf("%s",com);
			if(com[0] == 'Q')
			{
				scanf("%d%d",&a,&b);
				int sf = ((LL)((sum(b+1)-sum(a))+ mod)%mod*p[maxn-a]%mod);
				if(hash.find(sf)!=hash.end()) printf("Yes\n");
				else printf("No\n");
			}else
			{
				scanf("%d%s",&a,com);
				int tmp = ((LL)(com[0]-c[a])*p[a])%mod;
				c[a] = com[0];
				insert(a+1,tmp);
			}
		}
	}
	return 0;
}
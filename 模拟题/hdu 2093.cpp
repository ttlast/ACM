#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int Maxn = 20;
struct People{
	char name[Maxn];
	int ts;
	int sj;
};
People p[2005];

bool comp(const People & t1,const People & t2)
{
	if(t1.ts != t2.ts)
		return t1.ts > t2.ts;
	else {
		if(t1.sj != t2.sj)
			return t1.sj < t2.sj;
		else
			return strcmp(t1.name,t2.name) < 0;
	}
}

int main()
{
	int n,m,i,j,len;
	int sj,cs;
	char c[Maxn];
	scanf("%d%d",&n,&m);
	len = 0;
	while(scanf("%s",c)!=EOF)
	{
		strcpy(p[len].name,c);
		p[len].ts = p[len].sj = 0;
		for(i = 0;i < n;i ++)
		{
			scanf("%s",c);
			if(c[0] == '-' || c[0] == '0') continue;

			sj = cs = 0;
			for(j = 0;c[j] != '(' && c[j] != '\0';j ++)
				sj = sj*10 + c[j] - '0';
			if(c[j] == '(')
				for(j = j+1;c[j] != ')' && c[j] != '\0';j ++)
					cs = cs*10 + c[j] - '0';

			p[len].ts ++;
			p[len].sj = p[len].sj + sj + cs*m;
		}
		len ++;
	}
	sort(p,p+len,comp);
	for(i = 0;i < len;i ++)
		printf("%-10s %2d %4d\n",p[i].name,p[i].ts,p[i].sj);
	return 0;
}
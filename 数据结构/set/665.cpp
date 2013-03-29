#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
const int maxn = 105;

int hash[maxn];
char ss[5];
int la[maxn],ra[maxn];
int hct[maxn];
int main()
{
	int t,nt,n,num;
	int i,j,k,ct;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d%d",&n,&nt);
		for(i = 1;i <= n;i ++)
			hash[i] = -1,hct[i] = 0;
		ct = 0;
		for(k = 0;k < nt;k ++)
		{
			scanf("%d",&num);
			for(j = 0;j < num;j ++)
				scanf("%d",&la[j]);
			for(j = 0;j < num;j ++)
				scanf("%d",&ra[j]);
			scanf("%s",ss);
			if(ss[0] == '=')  // = 1, < 2 > 3;
			{
				for(i = 0;i < num;i ++)
					hash[la[i]] = 1;
				for(i = 0;i < num;i ++)
					hash[ra[i]] = 1;
			}else if(ss[0] == '<')  
			{
				ct ++;
				for(i = 0;i < num;i ++)
					if(hash[la[i]] == -1)
						hash[la[i]] = 2,hct[la[i]] ++;
					else if(hash[la[i]] == 3)
						hash[la[i]] = 1;
					else hct[la[i]] ++;

				for(i = 0;i < num;i ++)
					if(hash[ra[i]] == -1)
						hash[ra[i]] = 3,hct[ra[i]] ++;
					else if(hash[ra[i]] == 2)
						hash[ra[i]] = 1;
					else hct[ra[i]] ++;

			}else if(ss[0] == '>')
			{
				ct ++;
				for(i = 0;i < num;i ++)
					if(hash[la[i]] == -1)
						hash[la[i]] = 3,hct[la[i]] ++;
					else if(hash[la[i]] == 2)
						hash[la[i]] = 1;
					else hct[la[i]] ++;

				for(i = 0;i < num;i ++)
					if(hash[ra[i]] == -1)
						hash[ra[i]] = 2,hct[ra[i]] ++;
					else if(hash[ra[i]] == 3)
						hash[ra[i]] = 1;
					else hct[ra[i]] ++;
			}
		}
		int bc = 0,bs = 1;
		for(i = 1;i <= n;i ++)
				if(hash[i] != 1 && hct[i] == ct)
				{
					bc ++;
					bs = i;
				}
		if(bc == 1) printf("%d\n",bs);
		else printf("0\n");
		if(t) printf("\n");
	}
	return 0;
}
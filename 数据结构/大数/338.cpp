#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;
#define _max(x,y) (x)>(y) ? (x):(y)
const int maxn = 150;

char a[maxn],b[maxn];
char sf[maxn];
int al,bl,maxl;
int num1[maxn],num2[maxn],ans[maxn],ansl;
int num[maxn][maxn],len,numl[maxn],pos[maxn];
int main()
{
	int i,j,k,tm,ncase = 0;
	int sign;
	while(scanf("%s%s",a,b)==2)
	{
		al = strlen(a);
		bl = strlen(b);
		maxl = _max(al,bl);
		for(i = al-1,j = 0;i >= 0;i --,j ++)
			num1[j] = a[i] - '0';
		for(i = bl-1,j = 0;i >= 0;i --,j ++)
			num2[j] = b[i] - '0';
		len = 0;
		sign = 1;
		for(i = 0;i < al;i ++)
			if(a[i] != '0') break;
		if(i >= al) sign = 0;
		if(sign)
		{
			for(i = 0;i < bl;i ++)
			{
				if(num2[i] == 0) continue;
				tm = 0;
				for(j = 0;j < al;j ++)
				{
					tm += num2[i]*num1[j];
					num[len][j] = tm%10;
					tm /= 10;
				}
				while(tm > 0)
				{
					num[len][j] = tm%10;
					tm /= 10;
					j ++;
				}
				pos[len] = i;
				numl[len] = j;
				len ++;
			}
		}
		ansl = 0;

		for(i = 0;i < maxn;i ++)
			ans[i] = 0;
		if(len > 1){
			for(i = 0;i < len;i ++)
			{
				for(j = 0;j < numl[i];j ++)
				{
					tm += ans[j+pos[i]]+num[i][j];
					ans[j+pos[i]] = tm%10;
					tm /= 10;
				}
				while(tm > 0){
					tm += ans[j+pos[i]];
					ans[j+pos[i]] = tm%10;
					j ++;
					tm /= 10;
				}
				ansl = max(ansl,j+pos[i]);
				maxl = ansl;
			}
		}
		if(len == 0 || len == 1)
		{
			if(len == 1) maxl = numl[0]+pos[0];
			sprintf(sf,"%%%ds\n",maxl);
			printf(sf,a);
			printf(sf,b);
			al = max(al,bl);
			for(i = al;i < maxl;i ++)
				printf(" ");
			for(i = 0;i < al;i ++)
				printf("-");
			printf("\n");
			if(len == 0) printf(sf,"0");
			else{
				for(i = numl[0]-1;i >= 0;i --)
					printf("%d",num[0][i]);
				for(i = pos[0];i > 0;i --)
					printf("0");
				printf("\n");
			}
		}else{
			sprintf(sf,"%%%ds\n",maxl);
			printf(sf,a);
			printf(sf,b);
			al = max(al,bl);
			for(i = 0;i < maxl-al;i ++)
				printf(" ");
			for(;i < maxl;i ++)
				printf("-");
			printf("\n");
			for(i = 0;i < len;i ++)
			{
				for(j = numl[i]+pos[i];j < maxl;j ++)
					printf(" ");
				for(j = numl[i]-1;j >= 0;j --)
					printf("%d",num[i][j]);
				printf("\n");
			}
			for(i = 0;i < maxl;i ++)
				printf("-");
			printf("\n");
			for(i = ansl-1;i >= 0;i --)
				printf("%d",ans[i]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
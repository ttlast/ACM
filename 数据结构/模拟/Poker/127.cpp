#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 56;

char c[maxn][maxn][4];
int num[maxn];
int len;
int main()
{
	int i,j,k;
	bool sign;
	while(scanf("%s",c[0][0])!=EOF)
	{
		if(c[0][0][0] == '#') break;
		num[0] = 1;
		for(i = 1;i < 52;i ++)
		{
			scanf("%s",c[i][0]);
			num[i] = 1;
		}
		len = 52;
		while(len > 1)
		{
			sign = true;
			for(i = 1;i < len;i ++)
			{
				if(i >= 3)
				{
					if(c[i][0][0] == c[i-3][0][0] || c[i][0][1] == c[i-3][0][1])
					{
						for(j = num[i-3];j >= 1;j --)
							strcpy(c[i-3][j],c[i-3][j-1]);
						strcpy(c[i-3][0],c[i][0]);
						num[i-3] ++;
						num[i] --;
						if(num[i] > 0)
						{
							for(j = 0;j < num[i];j ++)
								strcpy(c[i][j],c[i][j+1]);
						}else{
							len --;
							for(k = i;k < len;k ++)
							{
								num[k] = num[k+1];
								for(j = 0;j < num[k];j ++)
									strcpy(c[k][j],c[k+1][j]);
							}
						}
						sign = false;
					}
				}
				if(!sign) break;
				if(c[i][0][0] == c[i-1][0][0] || c[i][0][1] == c[i-1][0][1])
				{
					for(j = num[i-1];j >= 1;j --)
						strcpy(c[i-1][j],c[i-1][j-1]);
					strcpy(c[i-1][0],c[i][0]);
					num[i-1] ++;
					num[i] --;
					if(num[i] > 0)
					{
						for(j = 0;j < num[i];j ++)
							strcpy(c[i][j],c[i][j+1]);
					}else{
						len --;
						for(k = i;k < len;k ++)
						{
							num[k] = num[k+1];
							for(j = 0;j < num[k];j ++)
								strcpy(c[k][j],c[k+1][j]);
						}
					}
					sign = false;
				}
				if(!sign) break;
			}
			if(sign) break;
		}
		if(len != 1) printf("%d piles remaining:",len);
		else printf("%d pile remaining:",len);
		for(i = 0;i < len;i ++)
			printf(" %d",num[i]);
		printf("\n");
	}
	return 0;
}
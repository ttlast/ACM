#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
const int maxn = 105;

int p;
int num[maxn][maxn],numl[maxn];
int mat[maxn][maxn];
char c[maxn];
int main()
{
	int t,a,b,i,j,k,ans,ct;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d%d",&p,&ct);
		for(i = 1;i <= p;i ++)
			numl[i] = 0;
		for(i = 1;i <= p;i ++)
			for(j = 1;j <= ct;j ++)
				mat[i][j] = 0;
		gets(c);
		while(gets(c))
		{
			if(c[0] == '\0') break;
			
			sscanf(c,"%d%d",&a,&b);
			if(mat[a][b]) continue;
			mat[a][b] = 1;
			num[a][numl[a]] = b;
			numl[a] ++;
		}
		ans = p;
		for(i = 1;i <= p;i ++)
			sort(num[i],num[i]+numl[i]);

		for(i = 1;i <= p;i ++)
		{
			for(j = i+1;j <= p;j ++)
			{
				if(numl[i] != numl[j]) continue;
				for(k = 0;k < numl[j];k ++)
					if(num[i][k] != num[j][k]) break;
				if(k >= numl[j])
				{
					ans --;
					break;
				}
			}
		}
		printf("%d\n",ans);
		if(t) printf("\n");
	}
	return 0;
}
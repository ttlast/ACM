#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <map>
using namespace std;
#define eps 1e-6
#define MAXN 1005
#define inf 1000000000
typedef double elem_t;
double amat[MAXN][MAXN],bmat[MAXN][MAXN];
int n;
void floyd_warshall(int n,elem_t mat[][MAXN]){
	int i,j,k;
	for (k=0;k<n;k++)
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				if (mat[i][k]*mat[k][j] >= mat[i][j]||mat[i][j] <= eps)
					mat[i][j] = mat[i][k]*mat[k][j];
}
void read(){
	int i,j,k,a,b;
	while(scanf("%d",&n)!=EOF)
	{
		for(i = 0;i < n;i ++)
			for(j = 0;j < n;j ++)
				scanf("%lf",&amat[i][j]);
		
		floyd_warshall(n,amat);
		scanf("%d",&k);
		for(i = 0;i < k;i ++)
		{
			scanf("%d%d",&a,&b);
			a--;b--;
			if(amat[a][b] <= eps) puts("What a pity!");
			else printf("%.3f\n",amat[a][b]);
		}
	}
}
int main()
{
	read();
	return 0;
}
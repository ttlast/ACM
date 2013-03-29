#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int Maxn = 105;
struct Node{
	char dz[Maxn];
	char name[Maxn];
	int sm;
};

Node mat[Maxn];
int len;

void Find(const Node & tmp)
{
	int i,j;
	for(i = 0;i < len;i ++)
	{
		if(strcmp(tmp.dz,mat[i].dz) == 0 && strcmp(tmp.name,mat[i].name) == 0)
		{
			mat[i].sm += tmp.sm;
			return ;
		}
	}
	strcpy(mat[len].dz,tmp.dz);
	strcpy(mat[len].name,tmp.name);
	mat[len].sm = tmp.sm;
	len ++;
}

bool comp(const Node & t1,const Node & t2)
{
	if(strcmp(t1.dz,t2.dz) == 0)
	{
		return strcmp(t1.name,t2.name) < 0;
	}else return strcmp(t1.dz,t2.dz) < 0;
}

int main()
{
	int t,n,m,i,j;
	Node tmp;
	scanf("%d",&t);
	while(t --)
	{
		len = 0;
		scanf("%d",&n);
		for(i = 0;i < n;i ++)
		{
			scanf("%s%s%d",tmp.name,tmp.dz,&tmp.sm);
			Find(tmp);
		}
		sort(mat,mat+len,comp);
		printf("%s\n",mat[0].dz);
		printf("   |----%s(%d)\n",mat[0].name,mat[0].sm);
		for(i = 1;i < len;i ++)
		{
			if(strcmp(mat[i].dz,mat[i-1].dz) != 0)
				printf("%s\n",mat[i].dz);
			printf("   |----%s(%d)\n",mat[i].name,mat[i].sm);
		}
		if(t > 0) printf("\n");
	}
	return 0;
}
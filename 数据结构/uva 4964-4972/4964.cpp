#include<stdio.h>
int main()
{
	int i,j,k,a,b,c;
	while (scanf("%d%d%d",&a,&b,&c)!=EOF)
	{
		if (a==0&&b==0&&c==0)break;
		if (2*b==a+c)
		{
			printf("AP %d\n",c+b-a);
		}
		else 
		{
			printf("GP %d\n",c*(b/a));
		}
	}
	return 0;
}
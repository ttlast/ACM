#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 205;

char str[maxn];
int num[20],ans[20],pre[20];
void add(char c)
{
	switch(c)
	{
	case 'c':
		num[2] = 1; num[3] = 1;num[4] = 1;
		num[7] = 1; num[8] = 1;num[9] = 1;num[10] = 1;
		break;
	case 'd':
		num[2] = 1; num[3] = 1;num[4] = 1;
		num[7] = 1; num[8] = 1;num[9] = 1;
		break;
	case 'e':
		num[2] = 1; num[3] = 1;num[4] = 1;
		num[7] = 1; num[8] = 1;
		break;
	case 'f':
		num[2] = 1; num[3] = 1;num[4] = 1;
		num[7] = 1;
		break;
	case 'g':
		num[2] = 1; num[3] = 1;num[4] = 1;
		break;
	case 'a':
		num[2] = 1; num[3] = 1;
		break;
	case 'b':
		num[2] = 1;
		break;
	case 'C':
		num[3] = 1;
		break;
	case 'D':
		num[1] = 1;num[2] = 1; num[3] = 1;num[4] = 1;
		num[7] = 1; num[8] = 1;num[9] = 1;
		break;
	case 'E':
		num[1] = 1;num[2] = 1; num[3] = 1;num[4] = 1;
		num[7] = 1; num[8] = 1;
		break;
	case 'F':
		num[1] = 1;num[2] = 1; num[3] = 1;num[4] = 1;
		num[7] = 1;
		break;
	case 'G':
		num[1] = 1;num[2] = 1; num[3] = 1;num[4] = 1;
		break;
	case 'A':
		num[1] = 1;num[2] = 1; num[3] = 1;
		break;
	case 'B':
		num[1] = 1;num[2] = 1;
		break;
	}
}

int main()
{
	int t,i,j,len;
	scanf("%d",&t);
	gets(str);   //没用getswa，不知道什么问题
	while(t --)
	{
		gets(str);
		len = strlen(str);
		for(i = 1;i <= 10;i ++)
			pre[i] = num[i] = ans[i] = 0;
		for(i = 0;i < len;i ++)
		{
			add(str[i]);
			for(j = 1;j <= 10;j ++)
			{
				if(num[j] && pre[j] != num[j])
					ans[j] ++;
				pre[j] = num[j];
				num[j] = 0;
			}
		}
		printf("%d",ans[1]);
		for(i = 2;i <= 10;i ++)
			printf(" %d",ans[i]);
		printf("\n");
	}
}
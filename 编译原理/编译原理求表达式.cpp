E表示：表达式，
T表示：单项式;
F表示：因式;
i表示：一个数;
令文法G[E]为：
E→T|E+T|E-T
T→F|T*F|T/F
F→(E)|i

 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
const int maxn = 1050;

void __strrev(char *c)
{
	char tmp;
	int i,l = strlen(c)-1;
	for(i = 0;i < l;i ++,l --)
	{
		tmp = c[i];
		c[i] = c[l];
		c[l] = tmp;
	}
}
char c[maxn];
int start;
double Factor();
double Term();
double Exception();

// E = T|E+T|E-T

double Exception()
{
	double t = Term(),e;
	start --;
	if(c[start] == '+')
	{
		e = Exception();
		return e+t;
	}else if(c[start] == '-')
	{
		e = Exception();
		return e-t;
	}else
	{
		start ++;
		return t;
	}
}
// T = F|T*F|F/F
double Term()
{
	double f = Factor(),t;
	start --;
	if(c[start] == '*')
	{
		t = Term();
		return t*f;
	}else if(c[start] == '/')
	{
		t = Term();
		return t/f;
	}else{
		start ++;
		return f;
	}
}
// F = (E)|i
char cc[50];
int i,j;
double Factor()
{
	double e;
	start --;
	if(c[start] == ')')
	{
		e = Exception();
		start --;
	}else{
		for(i = 0;;i ++)
			if((c[start] >= '0' && c[start] <= '9') || c[start] == '.')
				cc[i] = c[start--];
			else break;
		start ++;
		cc[i] = '\0';
		__strrev(cc);
		sscanf(cc,"%lf",&e);
	}
	return e;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%s",c);
		start = strlen(c)-1;
		printf("%.2lf\n",Exception());
	}
	return 0;
}
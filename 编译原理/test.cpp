E：表达式
T：单项
F：因子
i：一个数

一个表达式分成两个部分，一个是+、- 另外一个是*、/.
E = T|E+T|E-T
T = F|T*F|T/F
F = (E)|i  //(E) 加括号表达式  编写的时候，自下而上


文法G[E] :

E -> T|E+T|E-T

T -> F|T*F|T/F   F is the 

F -> (E)|i.......

char str[1005];//This is the expression.......
int start;
char s[50],ss[50];int i,j;
double Term();double Expression();double Factor();

double Term()
{
	double f = factor(),t;
	--start;
	if(str[start] == '*')
	{
		t = Term();
		return t*f;
	}else if(str[start] == '/')
	{
		t = Term();
		return t/f;
	}else
	{
		++start;
		return f;
	}
}

double Expression()
{
	double t=Term(),e;
	--start;
	if(str[start] == '+')
	{
		e = Expression();
		return e;
	}else if(str[start] == '-')
	{
		e = Expression();
		return e-t;
	}else{
		++start;
		return t;
	}
}

double Factor()  //因子
{
	--start;
	double ret;
	if(str[start] == ')')
	{
		ret = Expression();
		--start;
		return ret;
	}else{
		i = 0;
		memset(ss,0,sizeof(ss));
		while((str[start] >= '0' && str[start] <= '9')||str[start] == '.')
			s[i++] = str[start--];
		for(j = 0;j < i;j ++)
		{
			ss[j] = s[i-1-j];
		}
		return atof(ss);
	}
}
int main()
{
	start = strlen(str)-1; //////
	Expression();
	return 0;
}
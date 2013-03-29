自顶向下的语法分析–递归下降分析–表达式求值
先是找到合适的正确的产生式，然后在产生式中为每个非终结符写一个递归函数即可。

比如，表达式求值，可以有以下产生式：

Expression->Term|Expression+Term|Expression-Term

Term->Factor|Term*Factor|Term/Factor

Factor->(Expression)| number

该产生或可以正确的表示表达式语法。

由于该产生式中含有左递归（如E->E+T这种形式)，直接用递归下降分析法来写程序会陷入死循环。

由于在本方法中，E->E+T与E->T+E所产生的语言的所有句子都是相同的（或者说两种文法是等价的），所以，我就认为直接把该方法改成成：

Expression->Term|Term+Expression|Term-Expression

Term->Factor|Factor*Term|Factor/Term

Factor->(Expression)| number

最后，程序写好之后测试时发现：1-2-3这种式子的结合性有问题，用上面的产生式得到的结果是：2.因为结果是它先算出了2-3=-1.
公式：(ε表示空)
A->Ab|a和A->aA2,A2->bA2|ε是等价的。。。
得到结论：并不是说两个文法等价就能说明两个文法就可以在任何时候都随意互换。

然后，用普通的消除左递归的方法写出产生式：

E->TE2
E2->+TE2 | -TE2 | ε
T->*FT2
T2->*FT2 | /FT2 |ε
F->(E) | i

然后，程序就好写了。下面的程序只处理了输入是一位数的情况：

#include<cstdio>
char expr[100]="(1+8)/(5-2)-2*3-1";
int start=0;
double T();
double T2();
double F();
double E2();
double E()
{
	return T()+E2();
}
double E2()
{
	switch(expr[start])
	{
	case '+':start++;return T()+E2();
	case '-':start++;return -T()+E2();
	default:return 0;
	}
}
double T()
{
	return F()*T2();
}
double T2()
{
	double a,b;
	switch(expr[start])
	{
	case '*':start++;return F()*T2();
	case '/':start++;a=F(),b=T2();
		return b/a;
	default:return 1;
	}

}
double F()
{
	if(expr[start]=='(')
	{
		double a;
		start++;
		a=E();
		start++;
		return a;
	}
	return expr[start++]-'0';
}

int main()
{
	printf("%f\n",E());
}

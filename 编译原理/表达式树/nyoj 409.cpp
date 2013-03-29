#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
const int maxn = 1050;

char c[maxn];
struct Node{
	char cc;
	double d;
	Node * cl,* cr;
	void set()
	{
		cc = '@';
		cl = cr = NULL;
	}
};
Node mat[maxn];
int len;
Node * newnode()
{
	mat[len].set();
	len ++;
	return mat+len-1;
}

Node * Create(int s,int e)
{
	double tm;
	int i,sign = -1,once = 1,d;

	Node * prep,* trep,* troot;
	Node * pren,* tren,* cc,* co;

	prep = trep = troot = pren = tren = cc = co = NULL;

	for(i = s;i < e;i ++)
	{
		if((c[i] >= '0' && c[i] <= '9')||c[i] == '.')
		{
			sscanf(c+i,"%lf%n",&tm,&d);
			
			i += d - 1;
			tren = newnode();
			tren->d = tm;

			pren = tren;
			if(e-s == d)
				return tren;

			if(i == e-1 && !once)
				prep->cr = tren;

		}else if(c[i] == '+' || c[i] == '-') //0
		{
			trep = newnode();
			trep->cc = c[i];

			if(sign == -1)
			{
				trep->cl = pren;
			}else if(sign == 0)
			{
				trep->cl = prep;
				prep->cr = pren;
			}else if(sign == 1)
			{
				if(co)
				{
					trep->cl = co;
					prep->cr = pren;
				}else{
					trep->cl = prep;
					prep->cr = pren;
				}
			}
			sign = 0;
			troot = trep;
			prep = trep;
			co = trep;			
		}else if(c[i] == '*' || c[i] == '/')  //1
		{
			trep = newnode();
			trep->cc = c[i];

			if(sign == -1)
			{
				trep->cl = pren;
			}else if(sign == 0)
			{
				prep->cr = trep;
				trep->cl = pren;
			}else if(sign == 1)
			{
				if(co)
				{
					co->cr = trep;
					trep->cl = prep;
					prep->cr = pren;
				}else{
					trep->cl = prep;
					prep->cr = pren;
				}
			}
			sign = 1;
			cc = trep;
			prep = trep;
		}else if(c[i] == '(')
		{
			int l,r,u;
			u = i;
			i ++;l = 1;r = 0;
			while(i < e && l != r)
			{
				if(c[i] == '(')
					l ++;
				else if(c[i] == ')')
					r ++;
				i ++;
			}
			tren = Create(u+1,i-1);

			pren = tren;
			if(u == s && i == e)
				return tren;
			i --;
			if(i == e-1 && !once)
				prep->cr = tren;
		}
		once = 0;
	}

	if(troot == NULL)
		troot = cc;
	return troot;
}

void Hdfs(Node * troot)
{
	if(troot->cc == '@')
	{
		cout<<troot->d<<" ";
		return ;
	}
	Hdfs(troot->cl);
	Hdfs(troot->cr);

	cout<<troot->cc<<" ";
}

void Pdfs(Node * troot)
{
	if(troot->cc == '@')
	{
		cout<<troot->d<<" ";
		return ;
	}
	cout<<troot->cc<<" ";
	Pdfs(troot->cl);
	Pdfs(troot->cr);	
}
double Ans(Node * troot)
{
	if(troot->cc == '@')
		return troot->d;
	double ansl,ansr;
	ansl = Ans(troot->cl);
	ansr = Ans(troot->cr);
	switch(troot->cc)
	{
		case '+':
			return ansl + ansr;
		case '-':
			return ansl - ansr;
		case '*':
			return ansl * ansr;
		case '/':
			return ansl / ansr;
	}
}

Node * root;

int main()
{
	int t,l;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%s",c);
		l = strlen(c)-1;
		len = 0;
		root = NULL;
		root = Create(0,l);
		Pdfs(root);
		printf("=\n");
		Hdfs(root);
		printf("=\n");
		printf("%.2f\n",Ans(root));
	}
	return 0;
}
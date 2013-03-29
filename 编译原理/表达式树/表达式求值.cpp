#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
/*
2
1.000+2/4=
((1+2)*5+1)/4=
*/

const int maxn = 1050;

char c[maxn];
struct Node{
	char cc;
	double s;
	Node *cl,*cr;
	void set(){
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
Node * root;

Node * create(int s,int e)
{
	int once,sign = -1,i,d; // 0 : +,-  1:*,/
	double tm;
	once = 1;
	Node *pren,*tren,*troot;
	Node * prep,* ro,* trep,* cc;
	troot = prep = pren = ro = cc = NULL;
	for(i = s;i < e;i ++)
	{
		if((c[i] >= '0' && c[i] <= '9')||c[i] == '.')
		{
			sscanf(c+i,"%lf%n",&tm,&d);
			i += d - 1;
			tren = newnode();
			tren->s = tm;
			pren = tren;

			if(e-s == d)
				return tren;
			if(i == e-1 && !once)
				prep->cr = tren;
		}else if(c[i] == '+' || c[i] == '-')
		{
			trep = newnode();
			trep->cc = c[i];
			
			if(sign== -1)
			{
				trep->cl = pren;
			}else if(sign== 1)
			{
				if(ro == NULL)
					trep->cl = prep;
				else
					trep->cl = ro;
				prep->cr = pren;
			}else if(sign== 0)
			{
				trep->cl = prep;
				prep->cr = pren;
			}
			prep = trep;
			sign= 0;
			troot = trep;
		}else if(c[i] == '*' || c[i] == '/')
		{
			trep = newnode();
			trep->cc = c[i];

			if(sign== -1)
			{
				trep->cl = pren;
			}else if(sign== 1)
			{
				if(ro)
					ro->cr = trep;
				trep->cl = prep;
				prep->cr = pren;
			}else if(sign== 0)
			{
				prep->cr = trep;
				trep->cl = pren;
				ro = prep;
			}
			sign= 1;
			cc = trep;
			prep = trep;
		}else if(c[i] == '(')
		{
			int l = 1,r = 0,u;
			i ++;
			u = i;
			while(i < e && l != r)
			{
				if(c[i] == '(')
					l ++;
				else if(c[i] == ')')
					r ++;
				i ++;
			}
			tren = create(u,i-1);
			pren = tren;
			if(u == s+1 && i == e)
				return tren;
			i --;
			if(i == e-1 && !once)
				prep->cr = tren;
		}
		once = 0;
	}
	if(troot == NULL) troot = cc;
	return troot;
}

double ans(Node *root)
{
	if(root->cc == '@')
		return root->s;
	double ansl,ansr;
	ansl = ans(root->cl);
	ansr = ans(root->cr);
	switch(root->cc)
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
int main()
{
	int t,l;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%s",c);
		l = strlen(c) - 1;
		len = 0;
		root = NULL;
		root = create(0,l);
		printf("%.2f\n",ans(root));
	}
	return 0;
}
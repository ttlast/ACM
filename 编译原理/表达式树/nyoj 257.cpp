#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;

const int maxn = 1010;

char c[maxn];
struct Node{
	char c;
	Node * cl,* cr;
	void set(){
		cl = cr = NULL;
	}
};
Node mat[maxn];
int len;
Node * newnode(char ch)
{
	mat[len].set();
	mat[len].c = ch;
	len ++;
	return mat+len-1;
}
Node * root;
Node * create(int s,int e)
{
	int i,sign = -1,once; // 0:+,- 1:*,/
	Node * tren,* pren;
	Node * prep,* trep,* cc,* co,* troot;
	once = 1;
	troot = tren = pren = prep = trep = cc = co = NULL;

	for(i = s;i < e;i ++)
	{
		if(c[i] >= '0' && c[i] <= '9')
		{
			tren = newnode(c[i]);
			pren = tren;
			if(e - s == 1) 
				return tren;
			if(e - i == 1 && !once)
				prep->cr = tren;
		}else if(c[i] == '+' || c[i] == '-')
		{
			trep = newnode(c[i]);
			if(sign == -1)
			{
				trep->cl = pren;
			}else if(sign == 1)
			{
				if(co)
					trep->cl = co;
				else
					trep->cl = prep;

				prep->cr = pren;

			}else if(sign == 0)
			{
				trep->cl = prep;
				prep->cr = pren;
			}
			sign = 0;
			co = trep;
			troot = trep;
			prep = trep;
		}else if(c[i] == '*' || c[i] == '/')
		{
			trep = newnode(c[i]);
			if(sign == -1)
			{
				trep->cl = pren;
			}else if(sign == 1)
			{
				if(co)
					co->cr = trep;
					
				trep->cl = prep;
				prep->cr = pren;
			}else if(sign == 0)
			{
				prep->cr = trep;
				trep->cl = pren;
			}
			sign = 1;
			cc = trep;
			prep = trep;
		}else if(c[i] == '(')
		{
			i ++;
			int l,r,u;
			l = 1;u = i;
			r = 0;
			while(i < e && l!= r)
			{
				if(c[i] == '(') l ++;
				else if(c[i] == ')') r ++;
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

	if(troot == NULL)
		troot = cc;
	return troot;
}

void hdfs(Node *troot)
{
	if(troot->c >= '0' && troot->c <= '9')
	{
		printf("%c",troot->c);
		return ;
	}
	hdfs(troot->cl);
	hdfs(troot->cr);
	printf("%c",troot->c);
}

int main()
{
	int t,l;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%s",c);
		l = strlen(c);
		len = 0;
		root = create(0,l);
		hdfs(root);
		printf("\n");
	}
	return 0;
}
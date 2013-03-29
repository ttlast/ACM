#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int inf = 10000000;
typedef int tyLL;
struct Node{
	tyLL  key;
	int sz,num;   //num,相同的数据出现多少次，sz：所在的子树有多少个节点
	Node * ch[2],*pre;
	Node():sz(1),pre(NULL),key(0)
	{
		ch[0] = ch[1] = NULL;
	};
	Node(tyLL tm):key(tm),sz(1),pre(NULL)
	{
		ch[0] = ch[1] = NULL;
	};
};
class Splay_Tree{
public:
	Splay_Tree():root(NULL){};
	~Splay_Tree()
	{
		cls(root);	
	}
	void cls(Node *x)
	{
		if(x->ch[0]) cls(x->ch[0]);
		if(x->ch[1]) cls(x->ch[1]);
		delete x;
	}
	void Rotate(Node * x,int c)  //旋转 ，左旋0 和右旋 1
	{
		Node * y = x->pre;

		y->ch[!c] = x->ch[c]; x->pre = y ->pre;
		if(x->ch[c] != NULL) x->ch[c]->pre = y; 
		if(y->pre != NULL)
			if(y->pre->ch[1] == y) y->pre->ch[1] = x;
			else y->pre->ch[0] = x;
		y->pre = x; x->ch[c] = y;
		//if(y == root) root = x;
	}
	void Splay(Node * x,Node * f)
	{
		while(x->pre != f)
		{
			if(x->pre->pre == f)
			{
				Rotate(x,x->pre->ch[0] == x);
			}else
			{
				Node * y = x->pre,*z = y->pre;
				if(z->ch[0] == y)
					if(y->ch[0] == x)  //都在左子树
						Rotate(y,1),Rotate(x,1);
					else 
						Rotate(x,0),Rotate(x,1);
				else
					if(y->ch[1] == x)
						Rotate(y,0),Rotate(x,0);
					else 
						Rotate(x,1),Rotate(x,0);
			}
		}
		root = x;
	}
	Node *Select(int k)
	{
		Node *p = root;
		int tmp;
		while(1)
		{
			tmp = p->ch[0]->sz;
			if(tmp + 1 == k) break;
			if(k <= tmp)
				p = p->ch[0];
			else 
				p = p->ch[1],k -= (tmp+1);
		}
		return p;
	}
	void Insert(const tyLL & x)
	{
		Node *tm = new Node(x),*p,*q;
		if(root == NULL)
			root = tm;
		else
		{
			p = root;
			do{
				q = p;
				if(p->key >= x) p = p->ch[0];
				/*
				else if(p->key == x) 
				{
					p->num ++;
					return;
				}*/
				else p = p->ch[1];
			}while(p);
			tm->pre = q;
			if(q->key >= x) q->ch[0] = tm;
			else q->ch[1] = tm;
			Splay(tm,NULL);
		}
	}
	tyLL Findmin()
	{
		tyLL ans = inf;
		Node *cl,*cr;
		cl = root->ch[0];
		cr = root->ch[1];
		if(cl)
			while(cl->ch[1]) cl = cl->ch[1];
		if(cr)
			while(cr->ch[0]) cr = cr->ch[0];
		if(cl) ans = abs(root->key - cl->key);
		if(cr) ans = min(abs(cr->key - root->key),ans);
		return ans;
	}
private:
	Node *root;
};
int n,al;
int main()
{
	int i,j,tmp,ans,mind;
	Splay_Tree sp;
	scanf("%d",&n);
	if(n == 0) printf("0\n");
	else
	{
		scanf("%d",&ans);
		sp.Insert(ans);
		while(scanf("%d",&tmp)!=EOF)
		{
			sp.Insert(tmp);
			mind = sp.Findmin();
			ans += mind;
		}
		printf("%d\n",ans);
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;
const int inf = 100000000;
typedef int tyLL;
int lk;
struct Node{
	tyLL  key;
	int sz,num;   //num,相同的数据出现多少次，sz：所在的子树有多少个节点
	Node * ch[2],*pre;
	Node():sz(1),pre(NULL),key(0),num(1)
	{
		ch[0] = ch[1] = NULL;
	};
	Node(tyLL tm):key(tm),sz(1),pre(NULL),num(1)
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

		y->sz -= x->sz;  //整颗树有多少节点，旋转
		x->sz += y->sz;
		if(x->ch[c]) y->sz += x->ch[c]->sz;

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
				p->sz ++;
				if(p->key > x) p = p->ch[0];
				else if(p->key == x) 
				{
					p->num ++;
					Splay(p,NULL);
					return;
				}
				else p = p->ch[1];
			}while(p);
			tm->pre = q;
			if(q->key >= x) q->ch[0] = tm;
			else q->ch[1] = tm;
			Splay(tm,NULL);
		}
	}
	void Erase(tyLL val)
	{
		Node *p,*q;
		q = NULL;
		p = root;
		while(p)
		{
			if(p->key < val) {q = p;p = p->ch[1];}
			else p = p->ch[0];
		}
		if(q == NULL) return ;  //所有数据都大于 val
		Splay(q,NULL);
		lk += root->num;
		if(root->ch[0]) lk += root->ch[0]->sz;
		if(q->ch[1]) q->ch[1]->pre = NULL;
		root = q->ch[1];
	}
	tyLL Check(int k)  //查找第k大数
	{
		tyLL val;
		if(root == NULL) return -inf;
		if(k > root->sz) return -inf;
		Node * p,* q;
		p = root;
		while(1)
		{
			
			if(p->ch[1])
			{
				if(k > p->ch[1]->sz)
				{
					k -= p->ch[1]->sz;
					if(k <= p->num) 
					{
						val = p->key;
						break;
					}else 
					{
						k -= p->num;
						p = p->ch[0];
					}
				}else p = p->ch[1];
			}else
			{
				if(k <= p->num) 
				{
					val = p->key;
					break;
				}
				k -= p->num;
				p = p->ch[0];
			}
		}
		return val;
	}
	
private:
	Node *root;
};
int ak,n,mind;
Splay_Tree st;
int main()
{
	int i,j;
	char c[5];
	int tmp;
	while(scanf("%d%d",&n,&mind)!=EOF)
	{
		lk = 0;ak = 0;
		for(i = 0;i < n;i ++)
		{
			scanf("%s%d",c,&tmp);
			if(c[0] == 'I')
			{
				if(tmp >= mind) 
					st.Insert(tmp - ak);
			}else if(c[0] == 'S')
			{
				ak -= tmp;
				st.Erase(mind - ak);
			}else if(c[0] == 'A')
			{
				ak += tmp;
			}else if(c[0] == 'F')
			{
				tmp = st.Check(tmp);
				if(tmp != -inf) 	printf("%d\n",tmp+ak);
				else printf("-1\n");
			}
		}
		printf("%d\n",lk);
	}
	return 0;
}

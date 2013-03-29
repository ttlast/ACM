#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 400000;
struct Node{
	Node * pre,* ch[2];
	int size;
};
struct SplayTree{
	Node * root;
	int size;
	SplayTree(){
		root = NULL;
	}
	public Rotate(Node * x,int c)  //0 左旋 1 右旋
	{
		Node * y = x->pre;
		y->ch[!c] = x->ch[c];
		if(x->ch[c] != NULL) x-ch[c]->pre = y;
		if(y->pre != NULL)
			if(y->pre->ch[0] == y) y->pre->ch[0] = x;
			else y->pre->ch[1] = x;
		x->ch[c] = y;y ->pre = x;
		if(y == root) root = x;
	}
	public Splay(Node *x,Node * f) //Splay操作，把x结点旋转到f下
	{
		for(;x->pre != f;)
			if(x->pre->pre == f){
				if(x->pre->ch[0] == x) Rotate(x,1);
				else Rotate(x,0);
			}else{
				Node *y = x->pre,*z = y->pre;
				if(z->ch[0] == y)
					if(y->ch[0] == x)
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
	void Select(int k,Node *f) //将中序遍历第k个节点，旋转到f下面
	{
		int tmp; Node * t;
		for(t = root;;){
			Push_Down(t);
			tmp = t->ch[0]->size;
			if(k == tmp+1) break; //t是所查找节点
			if(k <= tmp)
				t = t->ch[0];
			else
				k -= tmp+1,t = t->ch[1];
		}
		Splay(t,f); //执行旋转
	}

	//用户定义函数
	void Push_Down(Node *f){

	}
};
int main()
{
	return 0;
}

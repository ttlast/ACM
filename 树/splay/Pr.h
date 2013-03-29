#ifndef Merge_I
#define Merge_I
template <typename T>
class Node{
public:
	T val;
	Node *front,*next;
	Node():val(0),front(NULL),next(NULL) {};
	Node(T v):val(v),front(NULL),next(NULL) {};
};
template <typename _A1,typename _A2,typename _A3>
class binary_function{
public:
	typedef _A1 first_arg;
	typedef _A2 second_arg;
	typedef _A3 result_type;
};
template <typename T>
class less:binary_function<T,T,bool>{
public:
	bool operator()(const T & x,const T & y)const
	{
		return x < y;
	}
};
template <typename T,typename cmp = less<T> >
class Pq{
public:
	Pq(cmp __cmp = cmp());
	~Pq();
	void cls();
	bool empty() { return m_size == 0;}
	const T & front() const
	{
		return root->val;
	}
	void push(const T &val);
	void pop();
	int size(){ return m_size;}
	void Exchange(Node<T> * t1,Node<T> * t2);
	Node<T> * find(int k);
private:
	void addSort();
	void delSort();

	Node<T> *root,*fail;
	int m_size;
	cmp m_cmp;
};
template<typename T,typename cmp>
Pq<T,cmp>::Pq(cmp __cmp)
:m_size(0),m_cmp(__cmp),root(NULL),fail(NULL)
{
}
template<typename T,typename cmp>
Pq<T,cmp>::~Pq()
{
	cls();	
}
template<typename T,typename cmp>
void Pq<T,cmp>::cls()
{
	Node<T> *p;
	while(root != NULL)
	{
		p = root;
		root = root->next;
		delete p;
	}
	fail = NULL;
}
template<typename T,typename cmp>
void Pq<T,cmp>::push(const T & val)
{
	Node <T> *p = new Node<T>(val);
	if(root == NULL)
	{
		root = fail = p;
	}else
	{
		fail->next = p;
		p->front = fail;
		fail = fail->next;
	}
	m_size ++;
	addSort();
}
template<typename T,typename cmp>
void Pq<T,cmp>::pop()
{
	if(root == NULL) return;
	Node<T> *p = root;
	root = root->next;
	if(root != NULL) root->front = NULL;
	m_size --;
	delete p;
	delSort();
}
template<typename T,typename cmp>
Node<T> * Pq<T,cmp>::find(int k)
{
	if(k > m_size) return NULL;
	Node<T> *p;
	int i;
	for(i = 1,p = root;i < k;i ++)
	{
		p = p->next;
	}
	return p;
}
template<typename T,typename cmp>
void Pq<T,cmp>::Exchange(Node<T> *t1, Node<T> *t2)
{
	T tm = t1->val;
	t1->val = t2->val;
	t2->val = tm;
}
template<typename T,typename cmp>
void Pq<T,cmp>::addSort()
{
	if(m_size < 2) return ;
	int index = m_size>>1;
	Node<T> * p = fail , *q;
	while(index)
	{
		q = find(index);
		if(m_cmp(p->val,q->val))
		{
			Exchange(p,q);
			p = q;
		}else break;
		index >>= 1;
	}
}
template<typename T,typename cmp>  
void Pq<T,cmp>::delSort()
{
	if(m_size < 2) return ;
	Node<T> *cl,*cr,*p;
	p = fail->front;
	root->front = fail;
	fail->front = NULL;
	fail->next = root;
	root = fail;
	p->next = NULL;
	fail = p;
	//将最后一个移到最前
	int index = 1;
	p = root;
	cl = find(index<<1);
	cr = find((index<<1)+1);
	while(cl||cr)
	{
		if(cl&&cr)
		{
			if(m_cmp(cl->val,cr->val))
			{
				if(m_cmp(cl->val,p->val))
				{
					Exchange(cl,p);
					p = cl;
					index <<= 1;
				}else break;
			}else
			{
				if(m_cmp(cr->val,p->val))
				{
					Exchange(cr,p);
					p = cr;
					index = (index<<1) + 1;
				}else break;
			}
		}else if(cl)
		{
			if(m_cmp(cl->val,p->val))
			{
				Exchange(cl,p);
				p = cl;
				index <<= 1;
			}else break;
		}else
		{
			if(m_cmp(cr->val,p->val))
			{
				Exchange(cr,p);
				p = cr;
				index = (index<<1) + 1;
			}else break;
		}
		cl = find(index<<1);
		cr = find((index<<1)+1);
	}
}
#endif

#include "MyList.h"

Node::Node(int d, Node *n):data(d), next(n)
{
}
Node::Node(Node *n):next(n)
{
}

///////////////////////////////////////////////////////

MyList::MyList(void):m_iSize(0), m_pHead(NULL)
{
}

MyList::MyList(int size):m_iSize(size), m_pHead(NULL)
{
	Node *pTemp(NULL);
	for (int i = 0; i < m_iSize; i++)
	{
		pTemp = new Node(0);
		pTemp->next = m_pHead;
		m_pHead = pTemp;
	}
}

MyList::~MyList(void)
{
	Node *pCurrent = m_pHead;
	while (pCurrent != NULL)
	{
		pCurrent = pCurrent->next;
		delete m_pHead;
		m_pHead = pCurrent;
	}
}

void MyList::Print()
{
	Node *pCurrent(NULL);
	pCurrent = m_pHead;
	while (pCurrent != NULL)
	{
		cout <<pCurrent->data <<" ";
		pCurrent = pCurrent->next;
	}
	cout <<endl;
}

void MyList::ReGetData()
{
	srand((unsigned int)time_t(NULL));
	Node *pCurrent(NULL);
	pCurrent = m_pHead;
	while (pCurrent != NULL)
	{
		pCurrent->data = rand() % (m_iSize * 10);
		pCurrent = pCurrent->next;
	}
}

void MyList::MergeSort()
{
	recursive_merge_sort(m_pHead);
}

void MyList::recursive_merge_sort(Node * &sub_list)
{
	if (sub_list != NULL && sub_list->next != NULL)
	{
		Node *second_half = divide_from(sub_list);
		recursive_merge_sort(sub_list);
		recursive_merge_sort(second_half);
		sub_list = merge(sub_list,second_half);
	}
}

Node *MyList::divide_from(Node *sub_list)
{
	Node *position(NULL);
	Node *midpoint(NULL);
	Node *second_half(NULL);

	if ((midpoint = sub_list) == NULL)
		return NULL;

	position = midpoint->next;
	while (position != NULL)
	{
		position = position->next;
		if (position != NULL)
		{
			midpoint = midpoint->next;
			position = position->next;
		}
	}
	second_half = midpoint->next;
	midpoint->next = NULL;
	return second_half;
}

Node *MyList::merge(Node *first, Node *second)
{
	Node *last_sorted(0);
	Node combined;
	last_sorted = &combined;

	while (first != NULL && second != NULL)
	{
		if (first->data <= second->data)
		{
			last_sorted->next = first;
			last_sorted = first;
			first = first->next;
		}
		else
		{
			last_sorted->next = second;
			last_sorted = second;
			second = second->next;
		}
	}
	if (first == NULL)
		last_sorted->next = second;
	else
		last_sorted->next = first;

	return combined.next;
}
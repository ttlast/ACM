#pragma once

struct Node
{
	Node *next;
	int data;
	Node(int data, Node *next = NULL);
	Node(Node *n = NULL);
};

class MyList
{
public:
	MyList(void);
	MyList(int size);
	~MyList(void);
	void MergeSort();
public:
	void Print();
	void ReGetData();

protected:
	void recursive_merge_sort(Node * &sub_list);
	Node *divide_from(Node *sub_list);
	Node *merge(Node *first, Node *second);
protected:
	int m_iSize;
	Node *m_pHead;
};


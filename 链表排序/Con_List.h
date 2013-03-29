#pragma once

template<class T>
class Con_List
{
public:
	// Constructor. The list default size is  100
	Con_List(T *pData, int size);
	~Con_List(void);

	// 重载输出运算符
	/** 
	 * 友元函数：可以访问类私有成员的非成员函数，他是定义在类外的普通函数，
	 * 它不属于任何类，但必须在类的定义中声明。
	 */
	friend ostream &operator << (ostream &, const Con_List<T> &);
	
	void Print();
	void ReGetData();
	// The sorting methods
	void InsertSort();
	void SelectSort();
	void ShellSort();
	void QuickSort();
	void HeapSort();


protected:
	// auxiliary function
	int max_key(int low, int hight);
	void swap(int low, int hight);
	// This method will be called by shell sort
	void sort_interval(int start, int increment);
	void recursive_quick_sort(int low, int high);
	int partition(int low, int high);

	void build_heap();
	void insert_heap(const T &current, int low, int high);
protected:
	int m_iSize;
	T *m_pData;
};

//*********************************************************************************


//*********************************************************************************

template<class T>
Con_List<T>::Con_List(T *pData, int size):m_iSize(size)
{
	m_pData = pData;
}

template<class T>
Con_List<T>::~Con_List(void)
{
	if (m_pData != NULL)
		delete[] m_pData;
}

//***********************************************************
template<class T>
ostream &operator << (ostream &lcout, const Con_List<T> &list)
{
	for (int i = 0; i < list.m_iSize; i++)
		lcout <<list.m_pData[i] <<" ";
	lcout <<endl;
	return lcout;
}

template<class T>
void Con_List<T>::Print()
{
	for (int i = 0; i < m_iSize; i++)
		cout <<m_pData[i] <<" ";
	cout <<endl;
}

template<class T>
void Con_List<T>::InsertSort()
/* Post: The entries of the list have been rearranged so that the keys
 * in all the entries are sorted into nondecreasing order.
 */
{
	int first_unsorted;	// position of first unsorted entry
	int position;		// searches sorted part of list
	T current;			// holds the entry temporarily removed from list
	for (first_unsorted = 1; first_unsorted < m_iSize; first_unsorted++)
	{
		if (m_pData[first_unsorted] < m_pData[first_unsorted - 1])
		{
			position = first_unsorted;
			current = m_pData[first_unsorted];
			do {
				// Shift all entries until the proper position is found.
				m_pData[position] = m_pData[position - 1];
				position--;
			}while (position > 0 && m_pData[position - 1] > current);
			m_pData[position] = current;
		}
	}
}
	
template<class T>
void Con_List<T>::SelectSort()
{
	int max;
	for (int position = m_iSize - 1; position > 0; position--)
	{
		max = max_key(0, position);
		swap(max, position);
	}
}

template<class T>
int Con_List<T>::max_key(int low, int hight)
{
	int largest, current;
	largest = low;
	for (current = low + 1; current <= hight; current++)
	{
		if (m_pData[largest] < m_pData[current])
			largest = current;
	}
	return largest;
}

template<class T>
void Con_List<T>::swap(int low, int hight)
{
	T temp;
	temp = m_pData[low];
	m_pData[low] = m_pData[hight];
	m_pData[hight] = temp;
}

// This functio is used to make the data unordered.
template<class T>
void Con_List<T>::ReGetData()
{
	srand((unsigned int)time_t(NULL));
	for (int i = 0; i < m_iSize; i++)
		m_pData[i] = rand() % (m_iSize * 10);
}

template<class T>
void Con_List<T>::ShellSort()
{
	int increment;
	int start;
	increment = m_iSize;
	do {
		increment = increment / 3 + 1;
		for (start = 0; start < increment; start ++)
			sort_interval(start, increment);
	}while (increment > 1);
}

template<class T>
void Con_List<T>::sort_interval(int start, int increment)
{
	int first_unsorted;	// position of first unsorted entry
	int position;		// searches sorted part of list
	T current;			// holds the entry temporarily removed from list
	for (first_unsorted = start + increment; first_unsorted < m_iSize; first_unsorted += increment)
	{
		if (m_pData[first_unsorted] < m_pData[first_unsorted - increment])
		{
			position = first_unsorted;
			current = m_pData[first_unsorted];
			do {
				// Shift all entries until the proper position is found.
				m_pData[position] = m_pData[position - increment];
				position -= increment;
			}while (position > start && m_pData[position - increment] > current);
			m_pData[position] = current;
		}
	}
}

template<class T>
void Con_List<T>::QuickSort()
{
	recursive_quick_sort(0, m_iSize - 1);
}

template<class T>
void Con_List<T>::recursive_quick_sort(int low, int high)
{
	int pivot_position;
	if (low < high)
	{
		pivot_position = partition(low, high);
		recursive_quick_sort(low, pivot_position - 1);
		recursive_quick_sort(pivot_position + 1, high);
	}
}

template<class T>
int Con_List<T>::partition(int low, int high)
{
	T pivot;
	int i;
	int last_small;

	swap(low, (low + high) / 2);
	pivot = m_pData[low];
	last_small = low;

	for (i = low + 1; i <= high; i++)
		if (m_pData[i] < pivot) 
		{
			last_small = last_small + 1;
			swap(last_small, i);
		}
	swap(low, last_small);
	return last_small;
}

template<class T>
void Con_List<T>::HeapSort()
{
	T current;
	int last_unsorted;
	build_heap();

	for (last_unsorted = m_iSize - 1; last_unsorted > 0; last_unsorted--)
	{
		current = m_pData[last_unsorted];
		m_pData[last_unsorted] = m_pData[0];
		insert_heap(current, 0, last_unsorted - 1);
	}
}

template<class T>
void Con_List<T>::insert_heap(const T &current, int low, int high)
{
	int large;
	large = low * 2 + 1;
	while (large <= high)
	{
		if (large < high && m_pData[large] < m_pData[large + 1])
			large++;

		if (current >= m_pData[large])
			break;
		else
		{
			m_pData[low] = m_pData[large];
			low = large;
			large = 2 * low + 1;
		}
	}
	m_pData[low] = current;
}

template<class T>
void Con_List<T>::build_heap()
{
	int low;
	for (low = m_iSize / 2 - 1; low >= 0; low--)
	{
		T current = m_pData[low];
		insert_heap(current, low, m_iSize - 1);
	}
}
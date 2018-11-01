#include <iostream>

template <class T>
class Array
{
private:
	int m_length;
	T *m_data;
public:
	Array() :m_length(0), m_data(NULL)
	{
	}

	Array(int length)
	{
		m_length = length;
		m_data = new T[length];
	}

	T& operator[] (const int index)
	{
		return m_data[index];
	}

	int getLength() const;

	~Array()
	{
		delete m_data;
		m_data = nullptr;
		m_length = 0;
	}
};

template <class T>
int Array<T>::getLength() const
{
	return m_length;
}

class Employee
{

};

template <class T>
class LinkedList;

template <class T>
class Node
{
private:
	T m_data;
	Node *next;
public:
	friend class LinkedList<T>;
};

template <class T>
class LinkedList
{
private:
	Node<T> *m_head;
public:
	LinkedList()
	{
		m_head = NULL;
	}

	void push_back(T data);
};

template <class T>
void LinkedList<T>::push_back(T data)
{
	Node<T> *p = new Node<T>;
	p->m_data = data;
	p->next = NULL;
	if (m_head == NULL)
	{
		m_head = p;
	}
	else
	{
		p->next = m_head;
		m_head = p;
	}
}

int main()
{
	LinkedList<Employee*> employeeList;
	Employee *employee = new Employee;
	employeeList.push_back(employee);

	/*Array<int> intArray(5);
	Array<double> doubleArray(5);
	for (int i = 0; i < intArray.getLength(); i++)
	{
		intArray[i] = i;
		doubleArray[i] = i + 0.5;
	}

	for (int i = 0; i < intArray.getLength(); i++)
	{
		std::cout << intArray[i] << "  " << doubleArray[i] << std::endl;
	}*/

	system("pause");
	return 0;
}
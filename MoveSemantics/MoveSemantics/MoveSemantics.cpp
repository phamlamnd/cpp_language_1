#include <iostream>

template <class T>
class Auto_ptr2
{
private:
	T *m_ptr;
public:
	Auto_ptr2(T *ptr = NULL) :m_ptr(ptr)
	{
	}

	~Auto_ptr2()
	{
		if (m_ptr != NULL)
		{
			delete m_ptr;
			m_ptr = NULL;
		}
	}

	Auto_ptr2(Auto_ptr2& obj)
	{
		m_ptr = obj.m_ptr;
		obj.m_ptr = NULL;
	}

	Auto_ptr2& operator= (Auto_ptr2& obj)
	{
		if (this == &obj)
		{
			return *this;
		}
		delete m_ptr;
		m_ptr = obj.m_ptr;
		obj.m_ptr = NULL;
		return *this;
	}

	T& operator*() { return *m_ptr; }
	T* operator->() { return m_ptr; }
	bool isNull() { return m_ptr == NULL; }
};

class Resource
{
private:
	int m_value;
public:
	Resource(int value) :m_value(value){}
	Resource() { std::cout << "contructor\n"; }
	~Resource() { std::cout << "distructor\n"; }
	void print() { std::cout << m_value; }
};

int main()
{
	Auto_ptr2<Resource> re1(new Resource(3));
	Auto_ptr2<Resource> re2;
	std::cout << re1.isNull() << std::endl;
	std::cout << re2.isNull() << std::endl;
	re2 = re1;
	(*re2).print();
	std::cout << re1.isNull() << std::endl;
	std::cout << re2.isNull() << std::endl;

	system("pause");
	return 0;
}
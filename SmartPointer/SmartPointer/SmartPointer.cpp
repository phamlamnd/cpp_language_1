#include <iostream>

template <class T>
class Auto_Ptr1
{
private:
	T* m_ptr;
public:
	Auto_Ptr1(T* ptr = NULL) :m_ptr(ptr)
	{
	}

	~Auto_Ptr1()
	{
		if (m_ptr != NULL)
		{
			delete m_ptr;
			m_ptr = NULL;
		}
	}

	Auto_Ptr1(const Auto_Ptr1& obj)
	{
		m_ptr = new T;
		*m_ptr = *(obj.m_ptr);
	}

	Auto_Ptr1& operator= (const Auto_Ptr1& obj)
	{
		m_ptr = new T;
		*m_ptr = *(obj.m_ptr);
		return *this;
	}
	T& operator*() { return *m_ptr; }
	T* operator->() { return m_ptr; }
};

class Resource
{
public:
	Resource() { std::cout << "contructor\n"; }
	~Resource() { std::cout << "distructor\n"; }
};

void passByValue(Auto_Ptr1<Resource> res)
{

}

int main()
{
	Auto_Ptr1<Resource> re1(new Resource);
	passByValue(re1);
	system("pause");
	return 0;
}
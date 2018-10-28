#include <iostream>

template <class T>
class Auto_ptr
{
private:
	T *m_ptr;
public:
	int x;
	Auto_ptr(T *ptr = NULL) : m_ptr(ptr)
	{
	}

	~Auto_ptr()
	{
		delete m_ptr;
	}

	Auto_ptr(const Auto_ptr& obj)
	{
		std::cout << "call lvalue reference const contructor\n";
		m_ptr = new T;
		*m_ptr = *obj.m_ptr;
	}

	Auto_ptr& operator= (const Auto_ptr& obj)
	{
		std::cout << "call lvalue reference const assigned\n";
		if (this == &obj)
		{
			return *this;
		}
		delete m_ptr;
		m_ptr = new T;
		*m_ptr = *obj.m_ptr;
		return *this;
	}

	Auto_ptr(Auto_ptr&& rref) :m_ptr(rref.m_ptr)
	{
		std::cout << "call rvalue reference contructor\n";
		rref.m_ptr = NULL;
	}
	Auto_ptr& operator= (Auto_ptr&& rref)
	{
		std::cout << "call rvalue reference assigned\n";
		if (&rref == this)
		{
			return *this;
		}
		delete m_ptr;
		m_ptr = rref.m_ptr;
		rref.m_ptr = NULL;
		return *this;
	}
};

class Resource
{
public:
	Resource() { std::cout << "Constructor\n"; }
	~Resource() { std::cout << "Distructor\n"; }
};

Auto_ptr<Resource> generateResource()
{
	Auto_ptr<Resource> res(new Resource);
	return res;
}

int main()
{
	Auto_ptr<Resource> res;
	res = generateResource();
	system("pause");
	return 0;
}
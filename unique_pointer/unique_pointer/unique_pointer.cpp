#include <iostream>
#include "LinkedList.h"
#include <memory>
namespace myl
{
	template <class T>
	class unique_ptr;
	template <class T>
	unique_ptr<T> make_unique(T &obj);
}

template <class T>
class myl::unique_ptr
{
private:
	T *m_ptr;
public:
	unique_ptr(T *ptr = NULL) :m_ptr(ptr)
	{
	}
	~unique_ptr() { delete m_ptr; }
	unique_ptr(const unique_ptr& rhs) = delete;
	unique_ptr& operator= (const unique_ptr& rhs) = delete;
	unique_ptr(unique_ptr&& rhs)
	{
		m_ptr = rhs.m_ptr;
		rhs.m_ptr = NULL;
	}
	unique_ptr& operator= (unique_ptr&& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		delete m_ptr;
		m_ptr = rhs.m_ptr;
		rhs.m_ptr = NULL;
		return *this;
	}

	T& operator*() { return *m_ptr; }
	T* operator->() { return m_ptr; }
};

template<class T>
myl::unique_ptr<T> myl::make_unique(T &obj)
{

	return unique_ptr<T>(new T(obj));
}

class Employee
{
public:
	virtual void show() { std::cout << "I'm an Employee" << std::endl; }
	Employee() { std::cout << "Employee()" << std::endl;}
	virtual~Employee() { std::cout << "~Employee()" << std::endl;}
};

class Developer : public Employee
{
public:
	void show() override { std::cout << "I'm a Developer" << std::endl; }
	Developer() { std::cout << "Developer()" << std::endl;}
	virtual~Developer() { std::cout << "~Developer()" << std::endl;}
};

class Manager : public Employee
{
public:
	void show() override { std::cout << "I'm a Manager" << std::endl; }
	Manager() { std::cout << "Manager()" << std::endl; }
	virtual~Manager() { std::cout << "~Manager()" << std::endl; }
};


int main()
{
	{
		LinkedList<Employee*> employeeList;
		Employee *employee = new Developer;
		employeeList.push_back(employee);
	}
	system("pause");
	return 0;
}
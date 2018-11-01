#include "LinkedList.h"
#include <iostream>
#include "memory"
template <class T>
class unique_ptr
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
	LinkedList<Employee*> employeeList;

	Employee* employee1 = new Developer;
	employeeList.push_back(employee1);

	Employee* employee2 = new Manager;
	employeeList.push_back(employee2);

	Node<Employee*> *employeeIter = employeeList.begin();
	for (; employeeIter != employeeList.end(); employeeIter = employeeIter->getNext())
	{
		employeeIter->getData()->show();
	}

	system("pause");
	return 0;
}
#include <iostream>

class Base
{
public:
	Base() {}
	virtual ~Base() { std::cout << "Call ~Base()" << std::endl; }
};

class Derived :public Base
{
private:
	int *m_array;
public:
	Derived(int length)
	{
		m_array = new int[length];
	}
	virtual ~Derived()
	{
		std::cout << "Call ~Derived()" << std::endl;
		delete[] m_array;
	}
};

class A
{
private:
	int a;
public:
	A(){}
	virtual void getName() = 0;
};

class B : public A
{
private:
	int b;
public:
	virtual void getName() = 0;
};

class C : B
{
public:
	virtual void getName(){}
};

class Iterface
{
public:
	virtual void A(int) = 0;
	virtual void B(double) = 0;
	virtual void C(long) = 0;
	virtual void D(float) = 0;
};

int main()
{
	Base b;
	Derived d = b;
	
	std::cout << sizeof(Iterface);
	system("pause");
	return 0;
}
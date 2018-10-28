#include <iostream>
#include <string>

class Base
{
protected:
	int m_value;
public:
	Base(int value) :m_value(value)
	{
	}
	virtual const int& getValue() { return m_value; }
	virtual ~Base()
	{
		std::cout << "Base distructor\n";
	}
};

class Derived :public Base
{
protected:
	std::string m_name;
public:
	Derived(int value, std::string name)
		:Base(value), m_name(name)
	{
	}

	const std::string& getName() { return m_name; }
	virtual ~Derived()
	{
		std::cout << "Derived distructor\n";
	}
};

Base* getObject(bool bReturnDerived)
{
	if (bReturnDerived)
		return new Derived(1, "Apple");
	else
		return new Base(1);
}


int main()
{
	/*Base *b = getObject(false);
	Derived *d = dynamic_cast<Derived*>(b);
	if(d)
	std::cout << d->getName();
	delete b;*/

	Derived apple(1, "Apple"); // create an apple
	Base &b = apple; // set base reference to object
	Derived &d = dynamic_cast<Derived&>(b); // dynamic cast using a reference instead of a pointer

	std::cout << "The name of the Derived is: " << d.getName() << '\n'; // we can access Derived::getName through d

	system("pause");
	return 0;
}
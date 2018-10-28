#include <iostream>
#include <string>

class Animal
{
protected:
	std::string m_name;
	Animal(std::string name) :m_name(name)
	{
	}
public:
	std::string getName() { return m_name; }
	virtual const char* speak() = 0;
};

class Cat :public Animal
{
public:
	Cat(std::string name) :Animal(name)
	{
	}
	virtual const char*speak() { return "Wof"; }
};

class Dog :public Animal
{
public:
	Dog(std::string name) :Animal(name)
	{
	}
};

int main()
{

	system("pause");
	return 0;
}
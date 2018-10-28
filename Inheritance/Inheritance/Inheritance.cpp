#include <iostream>
#include <string>

class Person
{
protected:
	std::string m_name;
	int m_age;
public:
	Person(std::string name = "", int age = 0)
		: m_name(name), m_age(age)
	{
	}

	std::string getName() const { return m_name; }
	int getAge() const { return m_age; }
 };

//BaseballPlayer publicly inheriting Person
class BaseballPalyer : public Person
{
private:
	double m_battingAverage;
	int m_homeRuns;
public:
	BaseballPalyer(std::string name = "", int age = 0,  double battingAverage = 0.0, int homeRuns = 0)
		: Person(name, age), m_battingAverage(battingAverage), m_homeRuns(homeRuns)
	{
	}
};

//Employee pulic inherits from Person
class Employee : public Person
{
public:
	double m_hourlySalary;
	long m_employeeID;

	Employee(double hourlySalary = 0.0, long employeeID = 0)
		:m_hourlySalary(hourlySalary), m_employeeID(employeeID)
	{
	}

	void printNameAndSalary() const
	{
		std::cout << m_name << ": " << m_hourlySalary << "\n";
	}
};

//Inherittance chains
class Supervisor : public Employee
{
public:
	long m_overseeIDs[5];
	Supervisor()
	{
	}
};


class Base
{
public:
	int m_public;
protected:
	int m_protected;
private:
	int m_private;
protected:
	int m_id;
public:
	Base(int id = 0)
		: m_id(id)
	{
		std::cout << "Contructor Base" << std::endl;
	}
	~Base() 
	{
		std::cout << "Distructor Base" << std::endl;
	}
	int getID() const { return m_id; }
	void identify(int x) { std::cout << "I'm Base" << std::endl; }
protected:
	void ABC(){}
};

class Derived : public Base
{
private:
	double m_cost;
	//using Base::m_public; //change to protected
public:
	Derived(double cost = 0.0, int id = 0)
		:Base(id), m_cost(cost)
	{
		m_protected;
		m_public;
		//m_private;
		std::cout << "Contructor Derived" << std::endl;
	}
	~Derived()
	{
		m_id;
		std::cout << "Distructor Derived" << std::endl;
	}
	double getCost() const { return m_cost; }
	using Base::ABC; //changing it to public via a using declaration
	void identify() 
	{
		Base::identify(5); //Adding to existing functionality
		std::cout << "I'm Derived" << std::endl; 
	}
};

//Multiple inheritance


int main()
{
	Derived d;
	Base *b = &d;
	b->identify();
	system("pause");
	return 0;
}
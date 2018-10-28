#include <iostream>
#include <string>
#define MONEY_PER_COIN 4500
#define BASIC_SALARY 5000

class Employee
{
protected:
	std::string m_name;
	std::string m_account;
public:
	Employee(std::string name, std::string account)
		:m_name(name), m_account(account)
	{
		std::cout << "Employee()\n";
	}
	friend std::ostream& operator<< (std::ostream& out, const Employee& e)
	{
		return e.print(out);
	}
	virtual std::ostream& print(std::ostream& out) const = 0;
	const std::string& getName() const { return m_name; }
	const std::string& getAccount() const { return m_account; }
	virtual double getSalary() const = 0;
	virtual ~Employee()
	{
		std::cout << "~Employee()\n";
	}
};

class Fresher :public Employee
{
private:
	double m_gpa;
public:
	Fresher(std::string name = "", std::string account = "", double gpa = 0.0)
		:Employee(name, account), m_gpa(gpa)
	{
		std::cout << "Fresher()\n";
	}
	virtual std::ostream& print(std::ostream& out) const override
	{
		out << m_name << " " << m_account << " " << m_gpa << " " << getSalary() << "\n";
		return out;
	}
	virtual double getSalary() const override { return m_gpa * BASIC_SALARY; }
	virtual ~Fresher()
	{
		std::cout << "~Fresher()\n";
	}
};


class Developer :public Employee
{
protected:
	double m_level;
	double m_coin;
public:
	Developer(std::string name = "", std::string account = "", double level = 0.0, double coin = 0.0)
		:Employee(name, account), m_level(level), m_coin(coin)
	{
		std::cout << "Developer()\n";
	}
	virtual std::ostream& print(std::ostream& out) const override
	{
		out << m_name << " " << m_account << " " << m_level << " " << m_coin << " " << getSalary() << "\n";
		return out;
	}
	double getLevel() const { return m_level; }
	virtual double getCoin() const = 0;
	virtual ~Developer()
	{
		std::cout << "~Developer()\n";
	}
};

class Dev1 :public Developer
{
public:
	Dev1(std::string name = "", std::string account = "", double level = 0.0, double coin = 0.0)
		:Developer(name, account, level, coin)
	{
		std::cout << "Dev1()\n";
	}
	virtual double getCoin() const override { return 0.5 * m_coin; }
	virtual double getSalary() const override { return 0.5 * m_coin * MONEY_PER_COIN; }
	virtual ~Dev1()
	{
		std::cout << "~Dev1()\n";
	}
};

class Dev2 :public Developer
{
public:
	Dev2(std::string name = "", std::string account = "", double level = 0.0, double coin = 0.0)
		:Developer(name, account, level, coin)
	{
		std::cout << "Dev2()\n";
	}
	virtual double getCoin() const override { return m_coin; }
	virtual double getSalary() const override { return m_coin * MONEY_PER_COIN; }
	virtual ~Dev2()
	{
		std::cout << "~Dev2()\n";
	}
};

class ProjectManger :public Developer
{
public:
	ProjectManger(std::string name = "", std::string account = "", double level = 0.0, double coin = 0.0)
		:Developer(name, account, level, coin)
	{
		std::cout << "ProjectManger()\n";
	}
	virtual double getCoin() const override { return 2 * m_coin; }
	virtual double getSalary() const override { return 2 * m_coin * MONEY_PER_COIN; }
	virtual ~ProjectManger() 
	{
		std::cout << "~ProjectManger()\n";
	}
};

//int main()
//{
//	Employee *f1 = new Fresher("Pham Van Lam", "LamPV2", 0.7);
//	Employee *d1 = new Dev1("Pham Van Lam", "LamPV2", 1.1, 2.3);
//	Employee *d2 = new Dev2("Nguyen Van A", "LamPV2", 2.1, 2.3);
//	Employee *p1 = new ProjectManger("Nguyen Van A", "LamPV2", 2.1, 2.3);
//	Employee *array[] = { f1, d1, d2, p1 };
//	std::cout << p1->getSalary();
//	for (Employee *e : array)
//	{
//		std::cout << *e;
//	}
//	delete f1;
//	delete d1;
//	delete d2;
//	delete p1;
//	system("pause");
//	return 0;
//}

template <class T>

class B {
public:
	int f(int i) { std::cout << "f(int): "; return i + 1; }
	// ...
};

class D : public B {
public:
	//double f(double d) { std::cout << "f(double): "; return d + 1.3; }
	// ...
};

int main()
{
	D* pd = new D;

	std::cout << pd->f(2) << '\n';
	std::cout << pd->f(2.3) << '\n';
	system("pause");
	return 0;
}

#include<iostream>
#include<string>

class Employee
{
protected:
	std::string m_name;
	std::string m_account;
	double m_level;
	double m_coin;

	// We're making this constructor protected because
	// we don't want people creating employee objects directly,
	// but we still want inhertance classes to be able to use it.
	Employee(std::string name, std::string account, double level, double coin)
		: m_name(name), m_account(account), m_level(level), m_coin(coin)
	{
	}
public:
	std::string getName() { return m_name; }
	virtual const char* level() { return "level0.0"; }
	virtual double coin() { return 0.0; }
};

class Dev1 : public Employee
{
public:
	Dev1(std::string name = "", std::string account = "", double level = 1.0, double coin = 0.0)
		: Employee(name, account, level, coin)
	{
	}
	virtual const char* level() { return m_level + ; }
	virtual double coin() { return 0.5 * m_coin; }
};

class Dev2 : public Employee
{
public:
	Dev2(std::string name = "", std::string account = "", std::string level = "", double coin = 0.0)
		: Employee(name, account, level, coin)
	{
	}

};

class ProjectManager : public Employee
{
public:
	ProjectManager(std::string name = "", std::string account = "", std::string level = "", double coin = 0.0)
		: Employee(name, account, level, coin)
	{
	}

};

int main()
{
	system("pause");
	return 0;
}


/*8. weite a program for below requirement.
class dev1:
- account:
- level: string level1.1 to level1.9
- coin: only have 50%, 50% project Manager will keep.

class dev2:
- account:
- level: string level2.1 to level2.9
- coin: 100% coin

class projectManager:
- account:
- level:  string pm1 to pm4
- coin: 25% coin of all devs's total coins.

Note: coin is counted by milion (4500000 VND = 4.5)

we have clase employee
class employee
{
protected:
    std::string m_name;
 
    // We're making this constructor protected because
    // we don't want people creating employee objects directly,
    // but we still want inhertance classes to be able to use it.
    employee(std::string name)
        : m_name(name)
    {
    }
 
public:
    std::string getName() { return m_name; }
    const char* level() { return "level0.0"; }
    double coin(){return 0.0;}
};

class dev1, dev2, projectManager will inheritance from class employee.
They will re-write 2 functions level() and coin().
We have:
dev1: 
- AnLN: level1.3, coin 7.5
- BinhTT2: level1.5, coin 6.3
- ChungCH: level1.3, coin 9.0
- DucNV2: level1.8, coin 5.8

dev2: 
- HaLN: level2.3, coin 10.5
- LinhTT2: level2.5, coin 9.3 
- HinhTT2: level2.9, coin 12.3 

projectManager:
- MinhTT2: pm3
Print all the devs and projectManager with name, level and coins.*/
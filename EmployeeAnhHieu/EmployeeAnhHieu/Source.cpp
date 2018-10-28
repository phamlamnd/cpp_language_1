#include <iostream>
#include <string>
#include <vector>

using namespace std;

// class Employee
class Employee
{
protected:
	string m_name; // account name
	string m_level; // level
	double m_coin; // coin

	Employee(string name, string level) : m_name(name), m_level(level) {}

public:
	string getName() { return m_name; }
	string level() { return m_level; }
	virtual double coin() { return m_coin; }
	void print()
	{
		cout << "Account: " << getName() << ", Level: " << level() << ", Coin: " << coin() << endl;
	}
};

// class Dev1
class Dev1 : public Employee
{
public:
	Dev1(string name, string level, double coin) : Employee(name, level) {
		m_coin = coin / 2;
	}
};

// class Dev2
class Dev2 : public Employee
{
public:
	Dev2(string name, string level, double coin) : Employee(name, level) {
		m_coin = coin;
	}
};

// class ProjectManager
class ProjectManager : public Employee
{
private:
	vector< Employee > empList;
public:
	ProjectManager(string name, string level) : Employee(name, level) {
		m_coin = 0.0;
	}

	void addEmployee(Employee emp)
	{
		empList.push_back(emp);
	}

	double coin()
	{
		double pmCoin = 0.0;
		double totalCoinMembers = 0.0;
		vector< Employee >::iterator empIterator;
		empIterator = empList.begin();

		for (; empIterator != empList.end(); empIterator++)
		{
			if ((*empIterator).level().find("level1.") != string::npos)
			{
				pmCoin += (*empIterator).coin();
			}

			totalCoinMembers += (*empIterator).coin();
		}

		pmCoin += (totalCoinMembers * 0.25);

		return pmCoin;
	}

	// print all employee's informations
	void printAllEmployee()
	{
		double pmCoin = 0.0;
		vector< Employee >::iterator empIterator;
		empIterator = empList.begin();
		for (; empIterator != empList.end(); empIterator++)
		{
			(*empIterator).print();
		}

		// pm print info
		this->print();
	}
};

int main()
{
	Dev1 AnLN("AnLN", "level1.3", 7.5);
	Dev1 BinhTT2("BinhTT2", "level1.5", 6.3);
	Dev1 ChungCH("ChungCH", "level1.3", 9.0);
	Dev1 DucNV2("DucNV2", "level1.8", 5.8);

	Dev1 HaLN("HaLN", "level2.3", 10.5);
	Dev1 LinhTT2("LinhTT2", "level2.5", 9.3);
	Dev1 HinhTT2("HinhTT2", "level2.9", 12.3);

	ProjectManager projectManager("MinhTT2", "pm3");
	projectManager.addEmployee(AnLN);
	projectManager.addEmployee(BinhTT2);
	projectManager.addEmployee(ChungCH);
	projectManager.addEmployee(DucNV2);
	projectManager.addEmployee(HaLN);
	projectManager.addEmployee(LinhTT2);
	projectManager.addEmployee(HinhTT2);

	projectManager.printAllEmployee();

	system("pause");
	return 0;
}
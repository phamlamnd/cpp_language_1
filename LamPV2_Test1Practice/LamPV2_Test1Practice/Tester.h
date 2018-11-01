#ifndef _TESTER_H_
#define _TESTER_H_
#include "Employee.h"

class Tester : public Employee
{
private:
	std::string m_project;
public:
	Tester(std::string id = "",
		std::string name = "",
		std::string deparment = "",
		JobTitle job = TESTER,
		std::string project = "")
		:Employee(id, name, deparment, job), m_project(project)
	{
	}
	virtual void input() override;
	virtual void writeToFile(std::ofstream &out) override;
	virtual void ShowInformation() override;
	virtual void DisplayDailyWork() override;
	virtual ~Tester() { };
};
#endif /*_TESTER_H_*/

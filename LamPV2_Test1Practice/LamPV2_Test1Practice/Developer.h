#ifndef _DEVELOPER_H_
#define _DEVELOPER_H_
#include "Employee.h"

class Developer : public Employee
{
private:
	std::string m_project;
public:
	Developer(std::string id = "", 
		std::string name = "", 
		std::string deparment = "", 
		JobTitle job = DEVELOPER,
		std::string project = "")
		:Employee(id, name, deparment, job), m_project(project)
	{
	}
	std::string getProject() { return m_project; }
	virtual void input() override;
	virtual void writeToFile(std::ofstream &out) override;
	virtual void ShowInformation() override;
	virtual void DisplayDailyWork() override;
	virtual ~Developer() { }
};
#endif /*_DEVELOPER_H_*/
#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include <iostream>
#include <string>
#include <fstream>
enum JobTitle
{
	DEVELOPER,
	TESTER,
	MANAGER
};

enum SORT_BY
{
	SORT_ID_INC,
	SORT_ID_DEC,
	SORT_NAME_INC,
	SORT_NAME_DEC,
};

class Employee
{
protected:
	std::string m_id;
	std::string m_name;
	std::string m_department;
	JobTitle m_job;
public:
	Employee(std::string id, std::string name, std::string deparment, JobTitle job)
		: m_id(id), m_name(name), m_department(deparment), m_job(job)
	{
	}
	std::string getID() const { return m_id; }
	std::string getName() const { return m_name; }
	std::string getLastName() const;
	std::string getDepartment() const { return m_department; }
	JobTitle getJob() const { return m_job; }
	virtual void input();
	virtual void writeToFile(std::ofstream &out) = 0;
	virtual void ShowInformation();
	virtual void DisplayDailyWork() = 0;
	virtual ~Employee() { };
};
#endif /*_EMPLOYEE_H_*/

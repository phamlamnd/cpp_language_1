#ifndef _MANAGER_H_
#define _MANAGER_H_
#include "Employee.h"
class Manager : public Employee
{
private:
	std::string m_customer;
public:
	Manager(std::string id = "", 
		std::string name = "", 
		std::string deparment = "", 
		JobTitle job = MANAGER, 
		std::string customer = "")
		:Employee(id, name, deparment, job), m_customer(customer)
	{
	}
	std::string getCustomer() { return m_customer; }
	virtual void input() override;
	virtual void writeToFile(std::ofstream &out) override;
	virtual void ShowInformation() override;
	virtual void DisplayDailyWork() override;
	virtual ~Manager() { };
};

#endif /*_MANAGER_H_*/

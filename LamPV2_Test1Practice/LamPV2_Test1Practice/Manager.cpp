#include "Manager.h"

void Manager::ShowInformation()
{
	std::cout << m_id << "\t" << m_name << "\t\t" << m_department << "\t" << m_customer << std::endl;
}

void Manager::DisplayDailyWork()
{
	std::cout << "Daily work (Manager)" << std::endl;
}

void Manager::input()
{
	Employee::input();
	std::cout << "Input Customer: ";
	std::getline(std::cin, m_customer);
}

void Manager::writeToFile(std::ofstream &out)
{
	out << m_id << "," << m_name << "," << m_department << ",MANAGER," << m_customer;
}
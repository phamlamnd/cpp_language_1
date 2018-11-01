#include "Employee.h"

void Employee::ShowInformation()
{
	std::cout << m_id << "\t" << m_name << "\t" << m_department << std::endl;
}

std::string Employee::getLastName() const
{
	std::string lastName;
	int pos = m_name.length();
	while (m_name[pos] != ' ' && pos > 0)
	{
		--pos;
	}
	++pos;
	lastName = m_name.substr(pos);
	return lastName;
}

void Employee::input()
{
	std::cout << "Input ID: ";
	std::cin.ignore();
	std::getline(std::cin, m_id);
	std::cout << "Input Name: ";
	std::getline(std::cin, m_name);
	std::cout << "Input Department: ";
	std::getline(std::cin, m_department);
}
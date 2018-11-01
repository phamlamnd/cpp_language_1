#include "Tester.h"

void Tester::ShowInformation()
{
	std::cout << m_id << "\t" << m_name << "\t\t" << m_department << "\t" << m_project << std::endl;
}

void Tester::DisplayDailyWork()
{
	std::cout << "Daily work (Tester)" << std::endl;
}

void Tester::input()
{
	Employee::input();
	std::cout << "Input Project: ";
	std::getline(std::cin, m_project);
}

void Tester::writeToFile(std::ofstream &out)
{
	out << m_id << "," << m_name << "," << m_department << ",TESTER," << m_project;
}
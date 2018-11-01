#include "Developer.h"

void Developer::ShowInformation()
{
	std::cout << m_id << "\t" << m_name << "\t\t" << m_department << "\t" << m_project << std::endl;
}

void Developer::DisplayDailyWork()
{
	std::cout << "Daily work (Developer)" << std::endl;
}

void Developer::input()
{
	Employee::input();
	std::cout << "Input Project: ";
	std::getline(std::cin, m_project);
}

void Developer::writeToFile(std::ofstream &out)
{
	out << m_id << "," << m_name << "," << m_department << ",DEVELOPER," << m_project;
}
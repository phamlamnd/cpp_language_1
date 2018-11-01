#include "Student.h"
#include <iomanip>

int Student::countStudent = 0;

Student::Student()
{
}

Student::Student(const std::string id, const std::string name, const std::string classId, const std::string rank)
{
	m_ID = id;
	m_Name = name;
	m_ClassID = classId;
	m_Rank = rank;
}

Student::~Student()
{
}

std::string Student::getLastName() const
{
	std::string lastName;
	int leng = m_Name.length();
	int pos = leng;
	while (m_Name[pos] != ' ' && pos > 0)
	{
		--pos;
	}
	lastName = m_Name.substr(pos);
	return lastName;
}

void Student::printStudentInfo()
{
	std::cout << std::setw(3) << std::left << ++countStudent << "  " << m_ID << "  " << std::setw(20) << std::left << m_Name << "  " << m_ClassID << "  " << m_Rank;
}

void Student::input()
{
	std::cout << "Input ID: ";
	std::getline(std::cin, m_ID);
	std::cout << "Input Name: ";
	std::getline(std::cin, m_Name);
	std::cout << "Input Rank: ";
	std::getline(std::cin, m_Rank);
}

std::ofstream& operator<< (std::ofstream& out, const Student& student)
{
	out << student.m_ID << "," << student.m_Name << "," << student.m_ClassID << "," << student.m_Rank;
	return out;
}
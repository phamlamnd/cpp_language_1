#include "Student.h"
#include <iomanip>
std::string Student::getID() const { return m_ID; }
std::string Student::getName() const { return m_Name; }
std::string Student::getClassID() const { return m_ClassID; }
std::string Student::getRank() const { return m_Rank; }
void Student::setID(const std::string &id) { m_ID = id; }
void Student::setName(const std::string &name) { m_Name = name; }
void Student::setClassID(const std::string &classid) { m_ClassID = classid; }
void Student::setRank(const std::string &rank) { m_Rank = rank; }
std::ostream& operator<< (std::ostream& out, const Student& obj)
{
	std::setw(50);
	out << obj.m_ID << "\t" << std::setw(18) << std::left << obj.m_Name << "\t" << obj.m_ClassID << "\t" << obj.m_Rank;
	return out;
}

std::istream& operator>> (std::istream& in, Student& obj)
{
	std::cout << "Input ID: ";
	in.ignore();
	std::getline(in, obj.m_ID);
	std::cout << "Input Name: ";
	std::getline(in, obj.m_Name);
	std::cout << "Input ClassID: ";
	std::getline(in, obj.m_ClassID);
	std::cout << "Input Rank: ";
	std::getline(in, obj.m_Rank);
	return in;
}
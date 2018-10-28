#include "ClassStudent.h"

void ClassStudent::addStudent()
{
	std::cout << "Input ClassID: ";
	std::string classid;
	std::cin.ignore();
	std::getline(std::cin, classid);

	std::cout << "Input number student: ";
	int numberStudent;
	std::cin >> numberStudent;
	m_StudentList.resize(numberStudent);

	std::vector<Student>::iterator studentIterator;
	for (studentIterator = m_StudentList.begin(); studentIterator != m_StudentList.end(); studentIterator++)
	{
		do
		{
			std::cin >> (*studentIterator);
			if (classid != (*studentIterator).getClassID())
			{
				std::cout << "ClassID error\n";
			}
		} while (classid != (*studentIterator).getClassID());
	}
}

void ClassStudent::printClass()
{
	std::vector<Student>::iterator studentIterator;
	for (studentIterator = m_StudentList.begin(); studentIterator != m_StudentList.end(); studentIterator++)
	{
		std::cout << (*studentIterator) << std::endl;
	}
}
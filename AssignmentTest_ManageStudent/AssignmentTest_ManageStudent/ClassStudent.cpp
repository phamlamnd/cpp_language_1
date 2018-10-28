#include "ClassStudent.h"

ClassStudent::ClassStudent(std::string classId)
{
	m_ClassID = classId;
}

ClassStudent::~ClassStudent()
{
	m_StudentList.clear();
}

std::vector<Student>& ClassStudent::getStudentList()
{
	return m_StudentList;
}

void ClassStudent::addStudent(const Student& student)
{
	m_StudentList.push_back(student);
}

void ClassStudent::printAllStudentInfo()
{
	std::vector<Student>::iterator studentIter;
	studentIter = m_StudentList.begin();
	for (; studentIter != m_StudentList.end(); ++studentIter)
	{
		(*studentIter).printStudentInfo();
		std::cout << std::endl;
	}
}

void ClassStudent::search(const std::string &searchData, const SEARCH_BY &searchKey)
{
	std::vector<Student>::iterator studentIter;
	studentIter = m_StudentList.begin();
	std::string studentInfo;
	for (; studentIter != m_StudentList.end(); ++studentIter)
	{
		switch (searchKey)
		{
			case SEARCH_ID:
				studentInfo = (*studentIter).getID(); break;
			case SEARCH_NAME:
				studentInfo = (*studentIter).getName(); break;
			case SEARCH_CLASSID:
				studentInfo = (*studentIter).getClassID(); break;
			case SEARCH_RANK:
				studentInfo = (*studentIter).getRank(); break;
			default: break;
		}
		if (searchData == studentInfo)
		{
			(*studentIter).printStudentInfo();
			std::cout << std::endl;
		}
	}
}
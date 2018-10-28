#include "Student.h"

Student::Student()
{
	m_ID = "";
	m_Name = "";
	m_ClassID = "";
	m_Rank = "";
}

Student::Student( const string id, const string name, const string classId, const string rank )
{
	m_ID = id;
	m_Name = name;
	m_ClassID = classId;
	m_Rank = rank;
}


Student::~Student()
{
}

void Student::printStudentInfo()
{
	cout << m_ID << " - " << m_Name << " - " << m_ClassID << " - " << m_Rank << endl;
}

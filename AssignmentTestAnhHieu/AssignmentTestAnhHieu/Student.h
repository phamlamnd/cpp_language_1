#pragma once

#include <string>
#include <iostream>

using namespace std;

class Student
{
protected:
	string m_ID;
	string m_Name;
	string m_ClassID;
	string m_Rank;

public:
	Student();
	Student( const string id,
			const string name,
			const string classId,
			const string rank );
	~Student();

	string getID() { return m_ID; }
	string getName() { return m_Name; }
	string getClassId() { return m_ClassID; }
	string getRank() { return m_Rank; }

	void printStudentInfo();
};


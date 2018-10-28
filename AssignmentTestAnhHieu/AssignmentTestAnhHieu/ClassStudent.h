#pragma once
#include "Student.h"
#include <string>
#include <vector>

enum SEARCH_BY
{
	SEARCH_ID,
	SEARCH_NAME,
	SEARCH_CLASSID,
	SEARCH_RANK
};

enum SORT_BY
{
	SORT_ID,
	SORT_NAME
};

class ClassStudent : public Student
{
private:
	vector< Student > m_StudentList;

public:
	ClassStudent( string classId );
	~ClassStudent();
	void printAllStudentInfo();
	void addStudent( const Student &student );
	void search( const string searchData, const SEARCH_BY &searchKey );
};


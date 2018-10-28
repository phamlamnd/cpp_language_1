#pragma once

#include "ClassStudent.h"

#define FILE_NAME "Student.csv"

class ClassManager
{
private:
	vector< ClassStudent > m_ClassList;

public:
	ClassManager();
	~ClassManager();
	void loadDataFromFile();
	void printAllClassInfo();
	void search( const string searchData, const SEARCH_BY &searchKey );
	void deleteStudent( const string studentId );
	void sort( const SORT_BY &sortKey );

private:
	ClassStudent* getClassStudent( const string classId );
};


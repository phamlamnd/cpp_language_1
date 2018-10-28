#ifndef _CLASS_STUDENT_H_
#define _CLASS_STUDENT_H_
#include "Student.h"
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
	std::vector<Student> m_StudentList;
public:
	ClassStudent(std::string classId);
	~ClassStudent();
	std::vector<Student>& getStudentList();
	void addStudent(const Student& student);
	void printAllStudentInfo();
	void search(const std::string &searchData, const SEARCH_BY &searchKey);
};

#endif // !_CLASS_STUDENT_H_


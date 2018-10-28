#ifndef _CLASS_STUDENT_H_
#define _CLASS_STUDENT_H_
#include "Student.h"
#include <vector>
class ClassStudent : public Student
{
protected:
	std::vector<Student> m_StudentList;
public:
	ClassStudent(){}
	ClassStudent(const Student &obj) { m_StudentList.push_back(obj); }
	std::vector<Student>& getStudentList() { return m_StudentList; }
	~ClassStudent() {}
	void addStudent();
	void printClass();
};
#endif /*_CLASS_STUDENT_H_*/
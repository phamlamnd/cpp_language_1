#ifndef _CLASS_MANAGER_H_
#define _CLASS_MANAGER_H_
#include "ClassStudent.h"
class ClassManager
{
private:
	std::vector<ClassStudent> m_ClassList;
public:
	ClassManager();
	~ClassManager();
	void loadDataFromFile(const std::string fileName);
	void inputDataFromConsole();
	void printAllClassInfo();
	void search(const std::string &searchData, const SEARCH_BY &searchKey);
	std::vector<Student> sort(const SORT_BY &sortKey);
	bool deleteStudent();
	bool deleteClass();
	void displayClass();
	void deleteRank();
	void addNewStudent(); //add new student to exist class
	void addNewClass();   //add new class
	void clearData();
	bool editStudentInfo();
	void updateFile(const std::string fileName);
	void writeOneClassToFile();
	void writeAllStudentToFile(const std::string fileName);

private:
	ClassStudent* getClassStudent(const std::string classID);
	Student* getStudent(const std::string Id);
};
#endif /*CLASS_MANAGER_H_*/


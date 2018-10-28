#ifndef _CLASS_MANAGER_H_
#define _CLASS_MANAGER_H_
#include "ClassStudent.h"
#include <fstream>
class ClassManager
{
private:
	std::vector<ClassStudent> m_ClassList;
public:
	ClassManager(){}
	~ClassManager(){}
	void inputFromConsole();
	void outputToConsole();
	void inputFromFile(std::string filename);
	void searchName(std::string name);
	void searchClassID(std::string classid);
	void searchRank(std::string rank);
	void searchID(std::string id);
	void deleteID(std::string id);
	void bubbleSort();
};
#endif /*_CLASS_MANAGER_H_*/
#include "ClassManager.h"
#include <fstream>
#include <algorithm>
ClassManager::ClassManager()
{
}

ClassManager::~ClassManager()
{
	m_ClassList.clear();
}

void ClassManager::loadDataFromFile(const std::string fileName)
{
	std::ifstream fileIn;
	fileIn.open(fileName);
	if (!fileIn)
	{
		std::cout << "File opening failed" << std::endl;
		return;
	}
	std::string id;
	std::string name;
	std::string classId;
	std::string rank;
	
	while (!fileIn.eof())
	{
		std::getline(fileIn, id, ',');
		std::getline(fileIn, name, ',');
		std::getline(fileIn, classId, ',');
		std::getline(fileIn, rank, '\n');
		Student student(id, name, classId, rank);
		
		ClassStudent *classStudent = this->getClassStudent(classId);
		if (NULL == classStudent)
		{
			ClassStudent classStud(classId);
			classStud.addStudent(student);
			m_ClassList.push_back(classStud);
		}
		else
		{
			(*classStudent).addStudent(student);
		}
	}
	fileIn.close();
}

ClassStudent* ClassManager::getClassStudent(const std::string classId)
{
	std::vector<ClassStudent>::iterator classIter;
	classIter = m_ClassList.begin();
	for (; classIter != m_ClassList.end(); ++classIter)
	{
		if (classId == (*classIter).getClassID())
		{
			return &(*classIter);
		}
	}
	return NULL;
}

void ClassManager::inputDataFromConsole()
{
	std::cout << "Input number of class: ";
	int numberClass;
	std::cin >> numberClass;
	std::cin.ignore();
	for (int i = 0; i < numberClass; i++)
	{
		std::cout << "Input class id for class " << i+1 << ": ";
		std::string classId;
		std::getline(std::cin, classId);
		ClassStudent classStud(classId);
		m_ClassList.push_back(classStud);
	}

	std::vector<ClassStudent>::iterator classIter;
	classIter = m_ClassList.begin();
	for (; classIter != m_ClassList.end(); ++classIter)
	{
		std::cout << "\nInput number student for class " << (*classIter).getClassID() << ": ";
		int numberStudent;
		std::cin >> numberStudent;
		std::cin.ignore();
		for (int i = 0; i < numberStudent; ++i)
		{
			std::cout << "\nInput student " << i+1 << ": " << std::endl;
			Student student;
			student.input();
			student.setClassID((*classIter).getClassID());
			if (NULL == this->getStudent(student.getID()))   //if student not exist
			{
				(*classIter).getStudentList().push_back(student);	
			}
			else //if student already exist
			{
				--i; 
				std::cout << "\nStudent already exist. Please re-enter info!" << std::endl;
			}
		}	
	}
}

Student* ClassManager::getStudent(const std::string Id)
{
	std::vector<ClassStudent>::iterator classIter;
	classIter = m_ClassList.begin();
	for (; classIter != m_ClassList.end(); ++classIter)
	{
		std::vector<Student> &studentList = (*classIter).getStudentList();
		std::vector<Student>::iterator studentIter;
		studentIter = studentList.begin();
		for (; studentIter != studentList.end(); ++studentIter)
		{
			if (Id == (*studentIter).getID())
			{
				return &(*studentIter);
			}
		}
	}
	return NULL;
}

void ClassManager::printAllClassInfo()
{
	std::vector<ClassStudent>::iterator classIter;
	classIter = m_ClassList.begin();
	for (; classIter != m_ClassList.end(); ++classIter)
	{
		(*classIter).printAllStudentInfo();
	}
}

void ClassManager::search(const std::string &searchData, const SEARCH_BY &searchKey)
{
	std::vector<ClassStudent>::iterator classIter;
	classIter = m_ClassList.begin();
	for (; classIter != m_ClassList.end(); ++classIter)
	{
		(*classIter).search(searchData, searchKey);
	}
}

void ClassManager::sort(const SORT_BY &sortKey)
{
	std::vector<Student> allStudent;
	std::vector<Student>::iterator studentIter;
	std::vector<ClassStudent>::iterator classIter;
	classIter = m_ClassList.begin();
	for (; classIter != m_ClassList.end(); ++classIter)
	{
		std::vector<Student> &studentList = (*classIter).getStudentList();
		studentIter = studentList.begin();
		for (; studentIter != studentList.end(); ++studentIter)
		{
			allStudent.push_back(*studentIter);
		}
	}

	bool(*funPointer)(Student&, Student&) = NULL; //function pointer
	switch (sortKey)
	{
	case SORT_ID: funPointer = [](Student& obj1, Student& obj2) {return obj1.getID() < obj2.getID(); }; break;
	case SORT_NAME: funPointer = [](Student& obj1, Student& obj2) {return obj1.getName() < obj2.getName(); }; break;
	default: break;
	}
	std::sort(allStudent.begin(), allStudent.end(), funPointer); //function pointer pass to sort

	studentIter = allStudent.begin();
	for (; studentIter != allStudent.end(); ++studentIter)
	{
		(*studentIter).printStudentInfo();
		std::cout << std::endl;
	}
}

bool ClassManager::deleteClass()
{
	std::cout << "Enter class id for delete: ";
	std::string classId;
	std::cin >> classId;

	std::vector<ClassStudent>::iterator classIter;
	classIter = m_ClassList.begin();
	for (; classIter != m_ClassList.end(); ++classIter)
	{
		if (classId == (*classIter).getClassID())
		{
			(*classIter).getStudentList().clear(); //clear all student in class
			m_ClassList.erase(classIter); //clear class
			std::cout << classId << "-->class id delete success..." << std::endl;
			return true; //delete success
		}
	}
	std::cout << " ...class id not found" << std::endl;
	return false; //delete fail
}

bool ClassManager::deleteStudent()
{
	std::cout << "Enter student id for delete: ";
	std::string id;
	std::cin >> id;

	std::vector<ClassStudent>::iterator classIter;
	classIter = m_ClassList.begin();
	for (; classIter != m_ClassList.end(); ++classIter)
	{
		std::vector<Student> &studentList = (*classIter).getStudentList();
		std::vector<Student>::iterator studentIter;
		studentIter = studentList.begin();
		for (; studentIter != studentList.end(); ++studentIter)
		{
			if (id == (*studentIter).getID())
			{
				studentList.erase(studentIter); //delete
				std::cout << id << "-->student delete success..." << std::endl;
				return true; //delete success
			}
		}
	}
	std::cout << " ...student id not found" << std::endl;
	return false; //delete fail
}

void ClassManager::writeDataToFile(const std::string fileName)
{
	std::ofstream fileOut(fileName);

	std::vector<ClassStudent>::iterator classIter;
	classIter = m_ClassList.begin();
	for (; classIter != m_ClassList.end(); ++classIter)
	{
		if (classIter != m_ClassList.begin())
		{
			fileOut << "\n";
		}
		std::vector<Student> &studentList = (*classIter).getStudentList();
		std::vector<Student>::iterator studentIter;
		studentIter = studentList.begin();
		for (; studentIter != studentList.end(); ++studentIter)
		{
			if (studentIter != studentList.begin())
			{
				fileOut << "\n";
			}
			fileOut << (*studentIter);
		}
	}
	fileOut.close();
}

void ClassManager::displayClass()
{
	system("cls");
	std::vector<ClassStudent>::iterator classIter;
	classIter = m_ClassList.begin();
	std::cout << "1.Diplay all class id" << std::endl;
	std::cout << "2.Diplay all student" << std::endl;
	for (char i = '3'; classIter != m_ClassList.end(); ++i, ++classIter)
	{
		std::cout << i << ".Display student in class " << (*classIter).getClassID() << std::endl;
	}

	std::cout << "Choose>> ";
	char key;
	std::cin >> key;

	if ('1' == key)
	{
		system("cls");
		std::cout << "Diplay all class id" << std::endl;
		classIter = m_ClassList.begin();
		for (int i = 1; classIter != m_ClassList.end(); ++i, ++classIter)
		{
			std::cout << i << "." << (*classIter).getClassID() << std::endl;
		}
	}

	else if ('2' == key)
	{
		system("cls");
		std::cout << "Diplay all student" << std::endl;
		this->printAllClassInfo();
	}
	else
	{
		classIter = m_ClassList.begin();
		for (char i = '3'; classIter != m_ClassList.end(); ++i, ++classIter)
		{
			if (key == i)
			{
				system("cls");
				std::cout << "Display student in class " << (*classIter).getClassID() << std::endl;
				(*classIter).printAllStudentInfo();
				return;
			}
		}
	}
}

//add new student to exist class
void ClassManager::addNewStudent()
{
	system("cls");
	std::vector<ClassStudent>::iterator classIter;
	classIter = m_ClassList.begin();
	for (char i = '1'; classIter != m_ClassList.end(); ++i, ++classIter)
	{
		std::cout << i << ".Add student for class " << (*classIter).getClassID() << std::endl;
	}

	std::cout << "Key: ";
	char key;
	std::cin >> key;
	std::cin.ignore();

	classIter = m_ClassList.begin();
	for (char i = '1'; classIter != m_ClassList.end(); ++i, ++classIter)
	{
		if (key == i)
		{
			system("cls");
			std::cout << i << ".Add student for class " << (*classIter).getClassID() << std::endl;
			Student student;
			student.input();
			student.setClassID((*classIter).getClassID());
			if (NULL == this->getStudent(student.getID()))   //if student not exist
			{
				std::cout << "Class " << (*classIter).getClassID() << " updating..." << std::endl;
				(*classIter).getStudentList().push_back(student);
				(*classIter).printAllStudentInfo();
				//writeDataToFile(fileName); //update file
				//std::cout << "File updating..." << std::endl;
			}
			else //if student already exist
			{
				--i;
				std::cout << "\nStudent already exist. Can not add!" << std::endl;
			}
			return;
		}
	}
}

//add new class
void ClassManager::addNewClass()
{
	std::string classId;
	std::cout << "Input new class ID: ";
	std::cin >> classId;
	ClassStudent classStud(classId);
	
	std::vector<ClassStudent>::iterator classIter;
	classIter = m_ClassList.begin();
	for (; classIter != m_ClassList.end(); ++classIter)
	{
		if (classId == (*classIter).getClassID())
		{
			std::cout << "Error! Class ID already exist...";
			return;
		}
	}

	//if class id exist yet
	m_ClassList.push_back(classStud);
	std::cout << "\nInput number student for class " << classId << ": ";
	int numberStudent;
	std::cin >> numberStudent;
	std::cin.ignore();
	for (int i = 0; i < numberStudent; ++i)
	{
		std::cout << "\nInput student " << i + 1 << ": " << std::endl;
		Student student;
		student.input();
		student.setClassID(classId);
		if (NULL == this->getStudent(student.getID()))   //if student not exist
		{
			(*(m_ClassList.end() - 1)).getStudentList().push_back(student);
		}
		else //if student already exist
		{
			--i;
			std::cout << "\nError! Student already exist..." << std::endl;
		}
	}
	std::cout << "All student in new class " << classId << std::endl;
	m_ClassList.back().printAllStudentInfo();
}

void ClassManager::clearData()
{
	std::vector<ClassStudent>::iterator classIter;
	classIter = m_ClassList.begin();
	for (; classIter != m_ClassList.end(); ++classIter)
	{
		(*classIter).getStudentList().clear();
	}
	m_ClassList.clear();
}
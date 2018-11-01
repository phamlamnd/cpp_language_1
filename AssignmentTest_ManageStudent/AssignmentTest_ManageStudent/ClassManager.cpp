#include "ClassManager.h"
#include <fstream>
#include <algorithm>
#include <Windows.h>

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

static bool compareID(Student& obj1, Student& obj2)
{
	return obj1.getID() < obj2.getID();
}

static bool compareName(Student& obj1, Student& obj2)
{
	return obj1.getLastName() < obj2.getLastName();
}

std::vector<Student> ClassManager::sort(const SORT_BY &sortKey)
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
		case SORT_ID: funPointer = compareID; break;
		case SORT_NAME: funPointer = compareName; break;
		default: break;
	}
	std::sort(allStudent.begin(), allStudent.end(), funPointer); //function pointer pass to sort

	return allStudent;
}

bool ClassManager::deleteClass()
{
	system("cls");
	std::cout << "Enter class id for delete: ";
	std::string classId;
	std::cin >> classId;
	system("cls");
	std::vector<ClassStudent>::iterator classIter;
	classIter = m_ClassList.begin();
	for (; classIter != m_ClassList.end(); ++classIter)
	{
		if (classId == (*classIter).getClassID())
		{
			std::vector<Student> studentList = (*classIter).getStudentList();
			std::vector<Student>::iterator studentIter;
			studentIter = studentList.begin();
			for (; studentIter != studentList.end(); studentIter++)
			{
				(*studentIter).printStudentInfo();
				Sleep(500);
				std::cout << " -->student delete success..." << std::endl;
			}
			(*classIter).getStudentList().clear(); //clear all student in class
			m_ClassList.erase(classIter); //clear class
			std::cout << classId << "-->class delete success..." << std::endl;
			return true; //delete success
		}
	}
	std::cout << " ...class id not found" << std::endl;
	return false; //delete fail
}

bool ClassManager::deleteStudent()
{
	system("cls");
	std::cout << "Enter student id for delete: ";
	std::string id;
	std::cin >> id;
	system("cls");
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
				(*studentIter).printStudentInfo();
				std::cout << " -->student delete success..." << std::endl;
				studentList.erase(studentIter); //delete
				return true; //delete success
			}
		}
	}
	std::cout << " ...student id not found" << std::endl;
	return false; //delete fail
}

void ClassManager::deleteRank()
{
	std::cout << "Enter rank for delete: ";
	std::string rank;
	std::cin >> rank;

	bool check = false;

	std::vector<ClassStudent>::iterator classIter;
	classIter = m_ClassList.begin();
	for (; classIter != m_ClassList.end(); ++classIter)
	{
		std::vector<Student> &studentList = (*classIter).getStudentList();
		std::vector<Student>::iterator studentIter;
		
		for (studentIter = studentList.begin(); studentIter != studentList.end();)
		{
			if (rank == (*studentIter).getRank())
			{
				check = true;
				(*studentIter).printStudentInfo();
				Sleep(500);
				std::cout << " -->student delete success..." << std::endl;
				studentIter = studentList.erase(studentIter); //delete
			}
			else
			{
				++studentIter;
			}
		}
	}

	if (check == false) std::cout << " Rank not found" << std::endl;
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

	std::cout << "Choose>> ";
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
	system("cls");
	std::cout << "Delete all data" << std::endl;
	std::cout << "1.NO" << std::endl;
	std::cout << "2.YES" << std::endl;
	std::cout << "Choose>> ";
	char key;
	std::cin >> key;
	system("cls");
	switch (key)
	{
	case '1':
		std::cout << "Data not delete..." << std::endl;
		break;
	case '2':
		std::vector<ClassStudent>::iterator classIter;
		classIter = m_ClassList.begin();
		for (; classIter != m_ClassList.end(); ++classIter)
		{
			std::vector<Student> &studentList = (*classIter).getStudentList();
			std::vector<Student>::iterator studentIter;
			studentIter = studentList.begin();
			for (; studentIter != studentList.end(); studentIter++)
			{
				(*studentIter).printStudentInfo();
				Sleep(500);
				std::cout << " -->student delete success..." << std::endl;
			}
		}

		classIter = m_ClassList.begin();
		for (; classIter != m_ClassList.end(); ++classIter)
		{
			(*classIter).getStudentList().clear();
		}
		m_ClassList.clear();
		break;
	}
}

bool ClassManager::editStudentInfo()
{
	std::cout << "Enter student id for edit: ";
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
				std::string name, rank;
				(*studentIter).printStudentInfo(); //In ra thong tin 
				std::cout << std::endl;
				std::cout << "Edit Name: ";
				std::cin.ignore();
				std::getline(std::cin, name);
				std::cout << "Edit Rank: ";
				std::getline(std::cin, rank);
				(*studentIter).setName(name);
				(*studentIter).setRank(rank);
				std::cout << id << "-->student edit success..." << std::endl;
				(*studentIter).printStudentInfo(); //In ra thong tin
				std::cout << std::endl;
				return true; //edit success
			}
		}
	}
	std::cout << " ...student id not found" << std::endl;
	return false; //edit fail
}

void ClassManager::updateFile(const std::string fileName)
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

void ClassManager::writeOneClassToFile()
{
	system("cls");
	std::vector<ClassStudent>::iterator classIter;
	classIter = m_ClassList.begin();
	for (char i = '1'; classIter != m_ClassList.end(); ++i, ++classIter)
	{
		std::cout << i << ".Write class " << (*classIter).getClassID() << " to file" << std::endl;
	}

	std::cout << "Choose>> ";
	char key;
	std::cin >> key;
	//std::cin.ignore();

	classIter = m_ClassList.begin();
	for (char i = '1'; classIter != m_ClassList.end(); ++i, ++classIter)
	{
		std::cout << "check ";
		if (i == key)
		{
			std::ofstream fileOut((*classIter).getClassID() + ".csv");
			std::vector<Student>::iterator studentIter = (*classIter).getStudentList().begin();
			for (; studentIter != (*classIter).getStudentList().end(); ++studentIter)
			{
				if (studentIter != (*classIter).getStudentList().begin())
				{
					fileOut << "\n";
				}
				fileOut << (*studentIter);
			}
			system("cls");
			std::cout << "Class " << (*classIter).getClassID() << " write to file success..." << std::endl;
			fileOut.close();
			return;
		}
	}
}

void ClassManager::writeAllStudentToFile(const std::string fileName)
{
	std::ofstream fileOut(fileName);

	std::vector<Student> allStudent = this->sort(SORT_NAME);
	std::vector<Student>::iterator studentIter = allStudent.begin();
	for (; studentIter != allStudent.end(); ++studentIter)
	{
		if (studentIter != allStudent.begin())
		{
			fileOut << "\n";
		}
		fileOut << (*studentIter);
	}
	system("cls");
	std::cout << "All student write to file '" << fileName << "' success..." << std::endl;
	fileOut.close();
}
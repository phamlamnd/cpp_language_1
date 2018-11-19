#include <iostream>
#include <fstream>
#include "Developer.h"
#include "Manager.h"
#include "Tester.h"
#include "LinkedList.h"

//Loading data from file
void loadDataFromFile(LinkedList<Employee*> &employeeList, std::string fileName)
{
	std::ifstream fileIn(fileName);

	std::string id;
	std::string name;
	std::string department;
	std::string job;
	std::string cur_pro;

	while (!fileIn.eof())
	{
		std::getline(fileIn, id, ',');
		std::getline(fileIn, name, ',');
		std::getline(fileIn, department, ',');
		std::getline(fileIn, job, ',');
		std::getline(fileIn, cur_pro, '\n');

		Employee *employee = NULL;
		if (job == "DEVELOPER")
		{
			employee = new Developer(id, name, department, DEVELOPER, cur_pro);
		}
		else if (job == "TESTER")
		{
			employee = new Tester(id, name, department, TESTER, cur_pro);
		}
		else if (job == "MANAGER")
		{
			employee = new Manager(id, name, department, MANAGER, cur_pro);
		}
		employeeList.push_back(employee);
	}

	fileIn.close();
}

//update file (if delete or add new employee)
void updateFile(LinkedList<Employee*> &employeeList, std::string fileName)
{
	std::ofstream fileOut(fileName); //open file 
	Node<Employee*> *employeeIter = employeeList.begin();
	for (; employeeIter != employeeList.end(); employeeIter = employeeIter->getNext())
	{
		if (employeeIter != employeeList.begin())
		{
			fileOut << "\n";
		}
		(employeeIter->getData())->writeToFile(fileOut);
	}
	std::cout << "-->Updating file success..." << std::endl;
	fileOut.close();
}

//compare ID
bool compareID_INC(Employee *&emp1, Employee *&emp2)
{
	return (*emp1).getID() > (*emp2).getID();
}

bool compareID_DEC(Employee *&emp1, Employee *&emp2)
{
	return (*emp1).getID() < (*emp2).getID();
}

//compare name
bool compareName_INC(Employee *&emp1, Employee *&emp2)
{
	return (*emp1).getLastName() > (*emp2).getLastName();
}

bool compareName_DEC(Employee *&emp1, Employee *&emp2)
{
	return (*emp1).getLastName() < (*emp2).getLastName();
}

//Sort data
void sort(LinkedList<Employee*> &employeeList, SORT_BY sortKey)
{
	bool(*funPointer)(Employee*&, Employee*&) = NULL;
	switch (sortKey)
	{
		case SORT_ID_INC: funPointer = compareID_INC; break;
		case SORT_ID_DEC: funPointer = compareID_DEC; break;
		case SORT_NAME_INC: funPointer = compareName_INC; break;
		case SORT_NAME_DEC: funPointer = compareName_DEC; break;
		default: break;
	}
	employeeList.sort(funPointer);
}

//display data
void displayInfo(LinkedList<Employee*> &employeeList)
{
	Node<Employee*> *employeeIter = employeeList.begin();
	for (; employeeIter != employeeList.end(); employeeIter = employeeIter->getNext())
	{
		(employeeIter->getData())->ShowInformation();
	}
}

//display daily work
void displayDailyWork(LinkedList<Employee*> &employeeList)
{
	Node<Employee*> *employeeIter = employeeList.begin();
	for (; employeeIter != employeeList.end(); employeeIter = employeeIter->getNext())
	{
		std::cout << (employeeIter->getData())->getID() << "  "; //show ID
		(employeeIter->getData())->DisplayDailyWork();			 //show daily work
	}
}

//create new employee (DEVELOPER, TEST, MANAGER)
Employee* createNewEmployee(JobTitle jobKey)
{
	Employee *employee = NULL;
	switch (jobKey)
	{
		case DEVELOPER: employee = new Developer; break;
		case TESTER: employee = new Tester; break;
		case MANAGER: employee = new Manager; break;
		default: break;
	}
	employee->input();
	return employee;
}

template <>
Node<Employee*>::~Node() //if data is Employee* call ~Node() will delete m_data
{
	delete m_data;
}

//delete employee, input ID
bool deleteID(LinkedList<Employee*> &employeeList, std::string id)
{
	Node<Employee*> *employeeIter = employeeList.begin();
	for (; employeeIter != employeeList.end(); employeeIter = employeeIter->getNext())
	{
		if (id == (employeeIter->getData())->getID())
		{
			//delete employeeIter->getData();		//delete emplloyee
			employeeList.erase(employeeIter);		//delete node
			std::cout << "-->ID '" << id << "' delete success..." << std::endl;
			return true; //delete success
		}
	}
	std::cout << "-->ID '" << id << "' not found..." << std::endl;
	return false; //ID not found
}

//free Employee* pointer allocate in linked list
void freeMemory(LinkedList<Employee*> &employeeList)
{
	Node<Employee*> *employeeIter = employeeList.begin();
	for (; employeeIter != employeeList.end(); employeeIter = employeeIter->getNext())
	{
		delete employeeIter->getData();
	}
}

//search ID
bool search(LinkedList<Employee*> &employeeList, std::string id)
{
	Node<Employee*> *employeeIter = employeeList.begin();
	for (; employeeIter != employeeList.end(); employeeIter = employeeIter->getNext())
	{
		if (id == (employeeIter->getData())->getID())
		{
			(employeeIter->getData())->ShowInformation();
			return true;
		}
	}
	std::cout << "-->ID '" << id << "' not found..." << std::endl;
	return false; //ID not found
}


int main()
{
	LinkedList<Employee*> employeeList;								//single linked list
	std::string fileName = "EmployeeList.txt";
	//Loading data from file
	std::cout << "Loading data from file..." << std::endl;			//Question 1.0
	loadDataFromFile(employeeList, fileName);
	//Sort ID display information
	sort(employeeList, SORT_ID_INC);
	displayInfo(employeeList);

	char menuKey;
	do
	{
		system("pause");
		system("cls");
		std::cout << "1.Display (Question 1.0,1.1)" << std::endl;	//Question 1.0, 1.1
		std::cout << "2.Add     (Question 2)" << std::endl;			//Question 2
		std::cout << "3.Delete  (Question 3)" << std::endl;			//Question 3
		std::cout << "4.Sort    (Question 4,5)" << std::endl;		//Question 4 & 5
		std::cout << "5.Search  (Question 6)" << std::endl;			//Question 6
		std::cout << "0.Exit" << std::endl;
		std::cout << "Choose>> ";
		std::cin >> menuKey;

		switch (menuKey)
		{
		case '1': //display information (Question 1.1)
		{
			displayInfo(employeeList);
			break;
		}
		case '2': //add new employee (Question 2)
		{
			system("cls");
			std::cout << "1.Add new Developer" << std::endl;
			std::cout << "2.Add new Tester" << std::endl;
			std::cout << "3.Add new Manager" << std::endl;
			char key;
			JobTitle jobKey;
			do 
			{
				std::cout << "Choose>> ";
				std::cin >> key;
			} while (key != '1' && key != '2' && key != '3');
			switch (key)
			{
				case '1': jobKey = DEVELOPER; break;
				case '2': jobKey = TESTER; break;
				case '3': jobKey = MANAGER; break;
				default: break;
			}
			Employee *employee = createNewEmployee(jobKey);
			employeeList.push_back(employee);
			employee->ShowInformation();		//show info
			std::cout << "-->adding success..." << std::endl;
			updateFile(employeeList, fileName); //update file
			break;
		}
		case '3': //delete one employee (Question 3)
		{
			system("cls");
			std::cout << "Input ID for delete: ";
			std::string id;
			std::cin.ignore();
			std::getline(std::cin, id);
			deleteID(employeeList, id);
			updateFile(employeeList, fileName); //update file
			break;
		}
		case '4': //sort ID inc & dec (Question 4 & 5)
		{
			system("cls");
			std::cout << "1.Sort ID Increase (Show Info)" << std::endl;
			std::cout << "2.Sort ID Descrease (Show Dailywork)" << std::endl;
			std::cout << "Choose>> ";
			char key;
			std::cin >> key;
			switch (key)
			{
				case '1': 
					sort(employeeList, SORT_ID_INC);
					displayInfo(employeeList);
					break;
				case '2': 
					sort(employeeList, SORT_ID_DEC);
					displayDailyWork(employeeList);
					break;
			}
			break;
		}
		case '5': //search ID (Question 6)
		{
			system("cls");
			std::cout << "Enter ID for search: ";
			std::string id;
			std::cin.ignore();
			std::getline(std::cin, id);
			search(employeeList, id);
		}
		}
	} while (menuKey != '0');

	//If have template<> Node<Employee*>::~Node()
	//will don't need call free memory 
	//freeMemory(employeeList);
	return 0;
}
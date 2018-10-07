#include "Student.h"
#include <iostream>
#include <string>

/*define select menu function*/
char selectMenu()
{
	char select;
	std::cout << "\nWellcome student manage system";
	std::cout << "\n\tPress 1 to input student";
	std::cout << "\n\tPress 2 to search student";
	std::cout << "\n\tPress 3 to delete one student";
	std::cout << "\n\tPress 4 to print student list";
	std::cout << "\n\tPress 'q' or 'Q' to quit";
	do {
		std::cout << "\nEnter choise: ";
		std::cin >> select;
		if ((select < '1' || select > '4') && select != 'q' && select != 'Q')
		{
			std::cout << "\nPlease choise 1, 2, 3, 4, q or Q";
		}
	} while ((select < '1' || select > '4') && select != 'q' && select != 'Q');
	return select;
}

/*define input one student function*/
void inputStudent(struct Student* studentsList[], int &n)
{
	studentsList[n] = new struct Student;

	bool checkAccount;
	std::string accountTmp;
	do {
		std::cout << "\nEnter Account: ";
		std::cin.ignore();
		std::getline(std::cin, accountTmp);
		checkAccount = false;
		for (int i = 0; i < n; i++)
		{
			if (accountTmp.compare(studentsList[i]->Account) == 0)
			{
				checkAccount = true;
				break;
			}
		}
	} while (checkAccount == true);
	studentsList[n]->Account = accountTmp;

	std::cout << "\nEnter Name: ";
	std::getline(std::cin, studentsList[n]->Name);

	bool checkCode;
	int codeTmp;
	do {
		std::cout << "\nEnter Code: ";
		std::cin >> codeTmp;
		checkCode = false;
		for (int i = 0; i < n; i++)
		{
			if (codeTmp == studentsList[i]->Code)
			{
				checkCode = true;
				break;
			}
		}
	} while (checkCode == true);
	studentsList[n]->Code = codeTmp;

	n++; /*increase number of student*/
}

/*define print student list*/
void printStudent(struct Student* studentsList[], int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << studentsList[i]->Account << "\t" << studentsList[i]->Name << "\t" << studentsList[i]->Code << "\n";
	}
}

/*define serarch student function*/
void searchStudent(struct Student* studentsList[], int n, std::string accountSearch)
{
	for (int i = 0; i < n; i++)
	{
		if (accountSearch.compare(studentsList[i]->Account) == 0)
		{
			std::cout << studentsList[i]->Account << "\t" << studentsList[i]->Name << "\t" << studentsList[i]->Code << "\n";
			return;
		}
	}
	std::cout << "\nStudent account not found";
}

/*define delete one student function*/
void deleteStudent(struct Student* studentsList[], int &n, int codeDelete)
{
	for (int i = 0; i < n; i++)
	{
		if (studentsList[i]->Code == codeDelete)
		{
			delete studentsList[i];
			for (int j = i; j < n - 1; j++)
			{
				studentsList[j] = studentsList[j + 1];
			}
			std::cout << "\nDelete success";
			n--;	/*decrease number of student*/
			return;
		}
	}
	std::cout << "\nStudent code not found";
}

/*define free memory student list function*/
void freeList(struct Student* studentsList[], int n)
{
	for (int i = 0; i < n; i++)
	{
		delete studentsList[i];
	}
}
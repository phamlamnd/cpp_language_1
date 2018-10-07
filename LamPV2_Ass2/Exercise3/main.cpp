#include "Student.h"
#include <iostream>

int main()
{
	struct Student* studentsList[MAX];
	int n = 0;	//number student

	std::string accountSearch;
	int codeDelete;
	while (true)
	{
		char select = selectMenu();
		switch (select)
		{
			case '1':
				inputStudent(studentsList, n);
				break;
			case '2':
				std::cout << "\nEnter Account: ";
				std::cin.ignore();
				std::getline(std::cin, accountSearch);
				searchStudent(studentsList, n, accountSearch);
				system("pause");
				break;
			case '3':
				std::cout << "\nEnter Code: ";
				std::cin >> codeDelete;
				deleteStudent(studentsList, n, codeDelete);
				system("pause");
				break;
			case '4':
				printStudent(studentsList, n);
				system("pause");
				break;
			case 'q':
			case 'Q':
				goto finish;
		}
	}
finish:
	freeList(studentsList, n);
	system("pause");
	return 0;
}
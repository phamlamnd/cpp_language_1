#include "ClassManager.h"
//29/10/2018
int main()
{
	ClassManager classManager;
	std::string fileName = "Student.csv";
	std::cout << "1.Reading data from file" << std::endl;
	std::cout << "2.Input data from console" << std::endl;
	char inputKey;
	do
	{
		std::cout << "Choose>> ";
		std::cin >> inputKey;
		switch (inputKey)
		{
			case '1':
				system("cls");
				std::cout << "Reading data from file ..." << std::endl;
				classManager.loadDataFromFile(fileName);
				break;
			case '2':
				system("cls");
				std::cout << "Input data from console ..." << std::endl;
				classManager.inputDataFromConsole();
				break;
			default:
				break;
		}
	} while (inputKey != '1' && inputKey != '2');

	std::cout << "All student's info loaded: " << std::endl;
	classManager.printAllClassInfo();
	Student::countStudent = 0;

	char menuKey;
	do
	{
		system("pause");
		system("cls");
		std::cout << "1.Search" << std::endl;
		std::cout << "2.Sort" << std::endl;
		std::cout << "3.Delete" << std::endl;
		std::cout << "4.Add" << std::endl;
		std::cout << "5.Display" << std::endl;
		std::cout << "6.Update file" << std::endl;
		std::cout << "7.Edit info" << std::endl;
		std::cout << "8.Write to file" << std::endl;
		std::cout << "0.Exit" << std::endl;
		std::cout << "Choose>> ";
		std::cin >> menuKey;

		switch (menuKey)
		{

		//Search
		case '1':
		{
			system("cls");
			std::cout << "1.Search by id" << std::endl;
			std::cout << "2.Search by name" << std::endl;
			std::cout << "3.Search by class id" << std::endl;
			std::cout << "4.Search by rank" << std::endl;

			SEARCH_BY searchKey;
			std::cout << "Choose>> ";
			char key;
			std::cin >> key;
			system("cls");
			switch (key)
			{
				case '1': 
					std::cout << "Search by id\n";
					searchKey = SEARCH_ID; break;
				case '2': 
					std::cout << "Search by name\n";
					searchKey = SEARCH_NAME; break;
				case '3': 
					std::cout << "Search by class id\n";
					searchKey = SEARCH_CLASSID; break;
				case '4': 
					std::cout << "Search by rank\n";
					searchKey = SEARCH_RANK; break;
			}
			std::cout << "Enter keyword for searching: ";
			std::string searchData;
			std::cin.ignore();
			std::getline(std::cin, searchData);
			classManager.search(searchData, searchKey);
			Student::countStudent = 0;
		}
		break;

		//Sort 
		case '2':
		{
			system("cls");
			std::cout << "1.Sort by id" << std::endl;
			std::cout << "2.Sort by name" << std::endl;
			SORT_BY sortKey;
			std::cout << "Choose>> ";
			char key;
			std::cin >> key;
			switch (key)
			{
				case '1': sortKey = SORT_ID; break;
				case '2': sortKey = SORT_NAME; break;
			}
			std::vector<Student> allStudent = classManager.sort(sortKey);

			std::vector<Student>::iterator studentIter = allStudent.begin();
			for (; studentIter != allStudent.end(); ++studentIter)
			{
				(*studentIter).printStudentInfo();
				std::cout << std::endl;
			}
			Student::countStudent = 0;
		}
		break;

		//Delete student
		case '3':
		{
			system("cls");
			std::cout << "1.Delete one student" << std::endl;
			std::cout << "2.Delete one class" << std::endl;
			std::cout << "3.Delete rank" << std::endl;
			std::cout << "4.Delete ALL(Carefully)" << std::endl;
			std::cout << "Choose>> ";
			char key;
			std::cin >> key;
			switch (key)
			{
			case '1': classManager.deleteStudent(); break;
			case '2': classManager.deleteClass(); break;
			case '3': classManager.deleteRank(); break;
			case '4': classManager.clearData(); break;
			default: break;
			}
		}
		break;

		//Add new student
		case '4':
		{
			system("cls");
			std::cout << "1.Add new student" << std::endl;
			std::cout << "2.Add new class" << std::endl;
			std::cout << "Choose>> ";
			char key;
			std::cin >> key;
			switch (key)
			{
			case '1': classManager.addNewStudent(); break;
			case '2': classManager.addNewClass(); break;
			}
			Student::countStudent = 0;
			break;
		}
		
		//Display class
		case '5': 
		{
			classManager.displayClass();
			Student::countStudent = 0;
		}
		break;

		//Update file
		case '6':
		{
			system("cls");
			std::cout << "Update file" << std::endl;
			std::cout << "1.NO" << std::endl;
			std::cout << "2.YES" << std::endl;
			std::cout << "Choose>> ";
			char key;
			std::cin >> key;
			
			switch (key)
			{
				case '1':
					system("cls");
					std::cout << "No update..." << std::endl;
					break;
				case '2':
					system("cls");
					classManager.updateFile(fileName);
					std::cout << "Updating file..." << std::endl;
					break;
				default:
					break;
			}
		}
		break;

		//Edit info
		case '7':
		{
			system("cls");
			classManager.editStudentInfo();
		}
		break;

		case '8':
		{
			system("cls");
			std::cout << "1.Write all student to file" << std::endl;
			std::cout << "2.Write one class to file" << std::endl;
			std::cout << "Choose>> ";
			char key;
			std::cin >> key;

			switch (key)
			{
			case '1':
				system("cls");
				classManager.writeAllStudentToFile("OUTPUT.csv");
				break;
			case '2':
				system("cls");
				classManager.writeOneClassToFile();
				break;
			default:
				break;
			}
			
		}
		break;

		default:
			break;
		}
	} while (menuKey != '0');

	return 0;
}
#include <iostream>
#include "ClassManager.h"

int main()
{
	ClassManager classManager;
	// step 1: read data from file
	cout << "Reading data from file ..." << endl;
	classManager.loadDataFromFile();

	// step 2: print student's info
	cout << "All student's info loaded:" << endl;
	classManager.printAllClassInfo();

	// step 3: show menu option
	char input;

	do 
	{
		cout << endl << "Enter key to continuous:" << endl;
		cout << "1: Search" << endl << "2: Sort" << endl << "3: Delete by ID" << endl << "0: Exit" << endl;
		cout << "Key: ";
		cin >> input;

		char key;
		switch ( input )
		{
			case '1':
			{
				cout << "1: Search by ID" << endl << "2: Search by name" << endl << "3: Search by classId" << endl << "4: Search by rank" << endl;
				cout << "Key: ";
				cin >> key;

				SEARCH_BY searchKey;

				switch( key )
				{
					case '1': searchKey = SEARCH_ID; break;
					case '2': searchKey = SEARCH_NAME; break;
					case '3': searchKey = SEARCH_CLASSID; break;
					case '4': searchKey = SEARCH_RANK; break;
					default: break;
				}

				cout << "Enter key word for searching: ";
				string keyWord;
				cin >> keyWord;
				classManager.search( keyWord, searchKey );
			}
			break;

			case '2':
			{
			
			}
			break;

			case '3':
			{

			}
			break;

			default:
			break;
		}
	} while ( input != '0' );

	return 0;
}
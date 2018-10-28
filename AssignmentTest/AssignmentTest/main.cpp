#include "ClassManager.h"

int main()
{

	ClassManager cm;
	//cm.inputFromConsole();
	cm.inputFromFile("Student.csv");
	//cm.searchClassID("K51CB");
	cm.bubbleSort();
	system("pause");
	return 0;
}
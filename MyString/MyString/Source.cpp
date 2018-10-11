#include "MyString.h"
#include <iostream>

int main()
{
	MyString string1 = "Pham Van Lam";
	MyString string2 = " FPT";
	MyString string3 = string1 + string2;
	std::cout << string3;
	system("pause");
	return 0;
}
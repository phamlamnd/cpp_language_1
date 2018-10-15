#include "MyString.h"
#include <iostream>

int main()
{
	MyString string1;
	MyString string2 = " FPT Software";
	MyString string3 = string1 = string2;
	string2[0] = '-';
	std::cin >> string1;
	std::cout << string2[2] << std::endl;
	string1 += "Hello";
	std::cout << string1 << std::endl;
	std::cout << string1.leng() << std::endl;
	std::cout << string1.rev() << std::endl;
	std::cout << string1.comp(string2) << std::endl;
	std::cout << string1.cat(string2) << std::endl;

	system("pause");
	return 0;
}
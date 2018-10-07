#include <iostream>

int main()
{
	/*make some example that often using bitwise Operators (and (&), or (|), xor (^))*/

	//x   1111.1111.0000.0000.0001.0001.1000.1000
	//1U  0000.0000.0000.0000.0000.0000.0000.0001
	unsigned int x = 0xFF001188U;
	
	/*check  bit 7 is 1 or 0*/
	unsigned check = x & (1U << 6);
	std::cout << check << std::endl;

	/*if bit 7 is 0 set bit 7*/
	if (check == 0)
	{
		x = x | (1U << 6);
	}
	std::cout << std::hex << x << std::endl;

	/*Toggle bit 7*/
	x = x ^ (1U << 6);
	std::cout << std::hex << x << std::endl;

	system("pause");
	return 0;
}
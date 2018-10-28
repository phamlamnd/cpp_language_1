#include <iostream>
int& getElement(int Array[], int index)
{
	return Array[index];
}

int main()
{
	int Array[10];
	getElement(Array, 5) = 5;
	std::cout << Array[5] << '\n';
	system("pause");
	return 0;
}

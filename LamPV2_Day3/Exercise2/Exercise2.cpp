#include <iostream>

int isPrime(int x)
{
	if (x < 2) { return 0; }
	if (x == 2) { return 1; }
	if (x % 2 == 0) { return 0; }
	for (int i = 3; i <= sqrt(x); i = i + 2)
	{
		if (x % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int searchPrime(int x)
{
	if (x < 0 || x > 999999)
	{
		return -1;
	}

	for (int i = x; i >= 2; i--)
	{
		if (isPrime(i) == 1)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	int x;
	std::cout << "\nEnter x = ";
	std::cin >> x;

	std::cout << searchPrime(x);

	system("pause");
	return 0;
}
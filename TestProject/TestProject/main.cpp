#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

void generateRandomArray(int *arr, const int limitDown, const int limitUp, const int size)
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % (limitUp - limitDown) + limitDown;
	}
}

int findMax2Number(const int *arr, const int size)
{
	int max1 = arr[0];
	int max2 = INT_MIN;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max1)
		{
			max2 = max1;
			max1 = arr[i];
		}
		if (arr[i] < max1 && arr[i] > max2)
		{
			max2 = arr[i];
		}
	}
	return max2;
}

void printArray(const int *arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}

void writeToFile(std::string filename, const int *arr, const int size)
{
	std::fstream fp(filename, std::ios::out);
	for (int i = 0; i < size; i++)
	{
		fp << arr[i] << "  ";
	}
	fp << "\nMax2 = " << findMax2Number(arr, size);
	fp.close();
}

void readFromFile(std::string filename, int *&arr, int &size)
{
	std::fstream fp(filename, std::ios::in);
	size = 0;
	while (!fp.eof())
	{
		fp >> arr[i];
	}
}

int main()
{
	int size = 10;
	int limitUp = 20;
	int limitDown = 0;
	int *arr = new int[size];
	generateRandomArray(arr, limitDown, limitUp, size);
	writeToFile("RANDOM.TXT", arr, size);
	printArray(arr, size);
	int max2 = findMax2Number(arr, 10);
	std::cout << "\nMax2 = " << max2;
	delete[] arr;
	system("pause"); 
	return 0;
}

#include <iostream>
#include <string>
#include <conio.h>



std::string array[5] = {
	"Pham Van Lam",
	"Nguyen Van A",
	"Hoang Tien Loc",
	"Tran Thuy An",
	"Vu Van Bang" };

int main()
{
	
	std::string key;
	char c;
	while (true)
	{
		c = _getch();
		system("cls");
		std::cout << key << std::endl;
		if (c == 8)
		{
			key.erase(key.end() - 1);
			continue;
		}
		else
		{
			key += c;
		}
		
		

		for (int i = 0; i < 5; i++)
		{
			if (array[i].find(key) < 1)
			{
				std::cout << array[i] << std::endl;
			}
		}
	}


	system("pause");
	return 0;
}
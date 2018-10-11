#include "MyString.h"

/*Default contructor*/
MyString::MyString()
{
	str = NULL;
}

/*Parameter contructor*/
MyString::MyString(const char *buf)
{
	if (buf != NULL)
	{
		int size = 0;
		while (buf[size] != '\0')
		{
			size++;
		}
		this->str = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			this->str[i] = buf[i];
		}
		this->str[size] = '\0';
	}
	else
	{
		str = NULL;
	}
}

/*Copy contructor*/
MyString::MyString(const MyString &obj)
{
	if (obj.str != NULL)
	{
		int size = 0;
		while (obj.str[size] != '\0')
		{
			size++;
		}
		this->str = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			this->str[i] = obj.str[i];
		}
		this->str[size] = '\0';
	}
}
/*Destructor*/
MyString::~MyString()
{
	
	if (str != NULL)
	{
		delete[] str;
		str = NULL;
	}
}


char* MyString::get_str(void)
{
	return str;
}

void MyString::set_str(const char *buf)
{
	if (str != NULL)
	{
		delete[] str;
		str = NULL;
	}
	if (buf != NULL)
	{
		int size = 0;
		while (buf[size] != '\0')
		{
			size++;
		}
		this->str = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			this->str[i] = buf[i];
		}
		this->str[size] = '\0';
	}
}

void MyString::input()
{
	std::cout << "\nInput string: ";
}

void MyString::print()
{
	if (str != NULL)
	{
		std::cout << str;
	}
}

void MyString::delele()
{
	if (str != NULL)
	{
		delete[] str;
		str = NULL;
	}
}

char* MyString::strcat(const char *buf)
{
	int len1 = this->length();
	int len2 = 0;
	if (buf != NULL)
	{
		while (buf[len2] != '\0')
		{
			len2++;
		}
	}
	char *tmp = str;
	str = new char[len1 + len2 + 1];
	int i = 0;
	for (int j = 0; j < len1; j++)
	{
		str[i] = tmp[j];
		i++;
	}
	for (int j = 0; j < len2; j++)
	{
		str[i] = buf[j];
		i++;
	}
	str[i] = '\0';
	delete[] tmp;
	return str;
}

char* MyString::strcat(const MyString &obj)
{
	return this->strcat(obj.str);
}

char* MyString::reverse()
{
	if (str != NULL)
	{
		int len = this->length();
		for (int i = 0; i <= len / 2 - 1; i++)
		{
			char tmp = str[i];
			str[i] = str[len - i - 1];
			str[len - i - 1] = tmp;
		}
	}
	return str;
}

int MyString::length()
{
	if (str != NULL)
	{
		int len = 0;
		while (str[len] != '\0')
		{
			len++;
		}
		return len;
	}
	return 0;
}

int MyString::compare(const MyString &obj)
{
	MyString tmp(obj);
	int len1 = this->length();
	int len2 = tmp.length();
	int min = len1 < len2 ? len1 : len2;
	for (int i = 0; i < min; i++)
	{
		if (this->str[i] > tmp.str[i])
		{
			return -1;
		}
		if (this->str[i] < tmp.str[i])
		{
			return 1;
		}
	}
	if (len1 > len2)
	{
		return 1;
	}
	else if (len1 < len2)
	{
		return -1;
	}
	return 0;
}

void MyString::operator= (const MyString &obj)
{
	if (str != NULL)
	{
		delete[] str;
		str = NULL;
	}
	if (obj.str != NULL)
	{
		int len = 0;
		while (obj.str[len] != '\0')
		{
			len++;
		}
		str = new char[len + 1];
		for (int i = 0; i < len; i++)
		{
			str[i] = obj.str[i];
		}
		str[len] = '\0';
	}
	else
	{
		this->str = obj.str;
	}
}

MyString MyString::operator+ (const MyString &obj)
{
	this->strcat(obj);
	return *this;
}

std::ostream& operator<<(std::ostream &out, const MyString &obj)
{
	if (obj.str != NULL)
	{
		out << obj.str;
	}
	else
	{
		out << "";
	}
	return out;
}
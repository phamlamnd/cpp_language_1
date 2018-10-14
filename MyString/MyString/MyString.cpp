#include "MyString.h"

/*Parameter contructor*/
MyString::MyString(const char *buf)
{
	if (buf != NULL)
	{
		int len = 0;
		while (buf[len] != '\0')
		{
			len++;
		}
		str = new char[len + 1];
		for (int i = 0; i < len; i++)
		{
			str[i] = buf[i];
		}
		str[len] = '\0';
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
		int len = obj.leng();
		str = new char[len + 1];
		for (int i = 0; i < len; i++)
		{
			str[i] = obj.str[i];
		}
		str[len] = '\0';
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

/*get string*/
const char* MyString::getStr(void) const
{
	return str;
}

/*set string*/
void MyString::setStr(const char *buf)
{
	if (str != NULL)
	{
		delete[] str;
		str = NULL;
	}
	if (buf != NULL)
	{
		int len = 0;
		while (buf[len] != '\0')
		{
			len++;
		}
		str = new char[len + 1];
		for (int i = 0; i < len; i++)
		{
			str[i] = buf[i];
		}
		str[len] = '\0';
	}
}

/*input string*/
void MyString::input(void)
{
	std::cout << "\nInput string: ";
}

/*print string*/
void MyString::output(void)
{
	if (str != NULL)
	{
		std::cout << str;
	}
	else
	{
		std::cout << "";
	}
}

/*delete string*/
void MyString::del(void)
{
	if (str != NULL)
	{
		delete[] str;
		str = NULL;
	}
}

/*cat with C style string*/
MyString& MyString::cat(const char *buf)
{
	int len1 = this->leng();
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
	return *this;
}

/*cat two mystring*/
MyString& MyString::cat(const MyString &obj)
{
	return this->cat(obj.str);
}

/*reveser string*/
MyString& MyString::rev(void)
{
	if (str != NULL)
	{
		int len = this->leng();
		for (int i = 0; i <= len / 2 - 1; i++)
		{
			char tmp = str[i];
			str[i] = str[len - i - 1];
			str[len - i - 1] = tmp;
		}
	}
	return *this;
}

/*get string length*/
int MyString::leng(void) const
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

/*compare two mystring*/
int MyString::comp(const MyString &obj)
{
	MyString tmp(obj);
	int len1 = this->leng();
	int len2 = tmp.leng();
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

/*overload operator=*/
MyString& MyString::operator= (const MyString &obj)
{
	if (str != NULL)
	{
		delete[] str;
		str = NULL;
	}
	if (obj.str != NULL)
	{
		int len = obj.leng();
		str = new char[len + 1];
		for (int i = 0; i < len; i++)
		{
			str[i] = obj.str[i];
		}
		str[len] = '\0';
	}
	else
	{
		str = NULL;
	}
	return *this;
}

/*overload operator+*/
MyString& MyString::operator+ (const MyString &obj)
{
	this->cat(obj);
	return *this;
}

/*overload operator<<*/
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
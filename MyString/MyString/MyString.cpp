#include "MyString.h"

/*default contructor*/

/*parameter contructor*/
MyString::MyString(const char *buf)
{
	if (buf != NULL)
	{
		int len = 0;
		while (buf[len] != '\0')
		{
			len++;
		}
		m_str = new char[len + 1];
		for (int i = 0; i < len; i++)
		{
			m_str[i] = buf[i];
		}
		m_str[len] = '\0';
	}
	else
	{
		m_str = NULL;
	}
}

/*copy contructor*/
MyString::MyString(const MyString &obj)
{
	if (obj.m_str != NULL)
	{
		int len = obj.leng();
		m_str = new char[len + 1];
		for (int i = 0; i < len; i++)
		{
			m_str[i] = obj.m_str[i];
		}
		m_str[len] = '\0';
	}
	else
	{
		m_str = NULL;
	}
}

/*destructor*/
MyString::~MyString()
{
	if (m_str != NULL)
	{
		delete[] m_str;
		m_str = NULL;
	}
}

/*get string*/
const char* MyString::getStr(void) const
{
	return m_str;
}

/*set string*/
void MyString::setStr(const char *buf)
{
	if (m_str != NULL)
	{
		delete[] m_str;
		m_str = NULL;
	}
	if (buf != NULL)
	{
		int len = 0;
		while (buf[len] != '\0')
		{
			len++;
		}
		m_str = new char[len + 1];
		for (int i = 0; i < len; i++)
		{
			m_str[i] = buf[i];
		}
		m_str[len] = '\0';
	}
}

/*input string*/
void MyString::input(void)
{
	int len = 0;
	char ch = 0;
	this->del(); /*delete m_str*/
	char *buf = NULL;
	while ((ch = std::cin.get()) == '\n')
	{
		/*if first character is 'ENTER', wating enter another key*/
	}
	/*if ENTER key*/
	len = 1;
	m_str = new char[2]; /*init m_str[0]*/
	m_str[0] = ch;
	m_str[1] = '\0';
	while ((ch = std::cin.get()) != '\n')
	{
		buf = new char[len + 2];
		for (int i = 0; i < len; i++)
		{
			buf[i] = m_str[i];
		}
		buf[len] = ch;
		buf[len + 1] = '\0';
		len++;
		this->del(); /*delete m_str*/
		m_str = buf; /*m_str = buf*/
	}
}

/*print string*/
void MyString::output(void) const
{
	if (m_str != NULL)
	{
		std::cout << m_str;
	}
	else
	{
		std::cout << "";
	}
}

/*delete string*/
void MyString::del(void)
{
	if (m_str != NULL)
	{
		delete[] m_str;
		m_str = NULL;
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
	char *tmp = m_str;
	m_str = new char[len1 + len2 + 1];
	int i = 0;
	for (int j = 0; j < len1; j++)
	{
		m_str[i] = tmp[j];
		i++;
	}
	for (int j = 0; j < len2; j++)
	{
		m_str[i] = buf[j];
		i++;
	}
	m_str[i] = '\0';
	if (tmp != NULL)
	{
		delete[] tmp;
	}
	return *this;
}

/*cat two mystring*/
MyString& MyString::cat(const MyString &obj)
{
	return this->cat(obj.m_str);
}

/*reveser string*/
MyString& MyString::rev(void)
{
	if (m_str != NULL)
	{
		int len = this->leng();
		for (int i = 0; i <= len / 2 - 1; i++)
		{
			char tmp = m_str[i];
			m_str[i] = m_str[len - i - 1];
			m_str[len - i - 1] = tmp;
		}
	}
	return *this;
}

/*get string length*/
int MyString::leng(void) const
{
	if (m_str == NULL)
	{
		return 0;
	}
	int len = 0;
	while (m_str[len] != '\0')
	{
		len++;
	}
	return len;
}

/*subscript operator[]*/
char& MyString::operator[] (const int index)
{
	return m_str[index];
}

/*Overloading typecasts*/
MyString::operator char*()
{
	return m_str;
}

/*compare two mystring*/
int MyString::comp(const MyString &obj) const
{
	int len1 = this->leng();
	int len2 = obj.leng();
	int min = len1 < len2 ? len1 : len2;
	for (int i = 0; i < min; i++)
	{
		if (this->m_str[i] > obj.m_str[i])
		{
			return -1;
		}
		if (this->m_str[i] < obj.m_str[i])
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
	if (this == &obj)
	{
		return *this;
	}
	this->del();
	if (obj.m_str != NULL)
	{
		int len = obj.leng();
		m_str = new char[len + 1];
		for (int i = 0; i < len; i++)
		{
			m_str[i] = obj.m_str[i];
		}
		m_str[len] = '\0';
	}
	else
	{
		m_str = NULL;
	}
	return *this;
}

/*overload operator==*/
bool operator== (const MyString &obj1, const MyString &obj2)
{
	return (obj1.comp(obj2) == 0);
}

/*overload operator!=*/
bool operator!= (const MyString &obj1, const MyString &obj2)
{
	return !(obj1 == obj2);
}

/*overload operator>*/
bool operator> (const MyString &obj1, const MyString &obj2)
{
	return (obj1.comp(obj2) == 1);
}

/*overload operator>=*/
bool operator>= (const MyString &obj1, const MyString &obj2)
{
	return (obj1 == obj2) || (obj1 > obj2);
}

/*overload operator<*/
bool operator< (const MyString &obj1, const MyString &obj2)
{
	return (obj1.comp(obj2) == -1);
}

/*overload operator<=*/
bool operator<= (const MyString &obj1, const MyString &obj2)
{
	return (obj1 == obj2) || (obj1 < obj2);
}

/*overload operator+*/
MyString operator+ (const MyString &obj1, const MyString &obj2)
{
	return MyString(obj1).cat(obj2);
}

/*overload operator+*/
MyString operator+ (const MyString &obj, const char* buf)
{
	return MyString(obj).cat(buf);
}

/*overload operator+*/
MyString operator+ (const char* buf, const MyString &obj)
{
	return MyString(obj).cat(buf);
}

/*overload operator+=*/
MyString& MyString::operator+= (const MyString &obj)
{
	*this = *this + obj;
	return *this;
}

/*overload operator+=*/
MyString& MyString::operator+= (const char* buf)
{
	*this = *this + buf;
	return *this;
}

/*overload operator>>*/
std::istream& operator>> (std::istream &in, MyString &obj)
{
	obj.input();
	return in;
}

/*overload operator<<*/
std::ostream& operator<< (std::ostream &out, const MyString &obj)
{
	obj.output();
	return out;
}
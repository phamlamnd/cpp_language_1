#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
class string1
{
private:
	char *tem;
public:
	string1();
	string1(const char* str);
	void inputs();
	void deletes();
	char* cpys(const string1 &obj1);
	char* cats(const string1 &obj1, const string1 &obj2);
	char* cats(const string1 &obj2);
	void reverses();
	int lens() const;
	int cmps(const string1 &obj1, const string1 &obj2);
	void outputs();
	friend istream &operator >> (istream &in, string1 &s);
	friend ostream &operator << (ostream &out, string1 &s);
	friend string1 operator+ (const string1 &obj1, const string1 &obj2);
	friend int operator> (const string1 &obj1, const string1 &obj2);
	friend int operator< (const string1 &obj1, const string1 &obj2);
	string1 operator= (const string1 &obj1);
	friend int operator>= (const string1 &obj1, const string1 &obj2);
	friend int operator<= (const string1 &obj1, const string1 &obj2);
	friend string1 operator+= (const string1 &obj1, const string1 &obj2);
	~string1();
};
int main()
{
	//string1 bien1,bien4,bien2,bien3,bien;
	//cout << "\nhay nhap chuoi 1 vao : ";
	//cin >> bien1;
	//cout << bien1;
	//cout << "\ndo dai chuoi 1 la : " << bien1.lens() << endl;
	//cout << "\nhay nhap chuoi 2 vao : ";
	//cin >> bien2;
	//cout << "\ndo dai chuoi 2 la : " << bien2.lens() << endl;
	//cout << endl;
	//cout << " noi chuoi: cach 1: ";
	//cout << bien.cats(bien1, bien2) << endl;
	//cout << " noi chuoi: cach 2: ";
	//cout << bien1.cats(bien2);
	//cout << endl << "chuoi lon hon la : ";
	//if (bien.cmps(bien1, bien2) == 1)
	//	cout << bien1;
	//else if (bien.cmps(bien1, bien2) == -1)
	//	cout << bien2;
	//else if (bien.cmps(bien1, bien2) == 0)
	//	cout << " khong co chuoi lon hon \n";
	//cout << endl;
	//cout << " dao chuoi 1: ";
	//bien1.reverses();
	//cout << bien1;
	//cout << "\ncopy chuoi 2 : " << bien4.cpys(bien2);
	////bien1.deletes();

	string1 k, h, g;
	cout << "\nnhap chuoi gan h: \n";
	cin >> h;
	cout << "\nnhap chuoi gan g: \n";
	cin >> g;
	k = g + h;
	cout << "cong : " << k;
	system("pause");

	return 0;
}

string1::string1()
{
	tem = NULL;
}
void string1::inputs()
{
	char a;
	int leng = 0, k = 0;
	while ((a = getchar()))
	{
		if (k == 0 && a == '\n')
		{
			continue;
		}
		if (a == '\n')
		{
			break;
		}
		tem = (char *)realloc(tem, leng + 2);
		tem[leng] = a;
		tem[leng + 1] = '\0';
		leng++;
		k = 1;
	}
}
int string1::lens() const
{
	int i = 0;
	while (tem[i] != '\0')
	{
		i++;
	}
	return i;
}


string1::string1(const char* str)
{
	int len = 0;
	while (str[len] != '\0')
	{
		len++;
	}

	tem = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		tem[i] = str[i];
	}
	tem[len] = '\0';
}
char* string1::cpys(const string1 &obj1)
{
	int len = obj1.lens();
	char *tem = new char[len];
	for (int i = 0; i < len; i++)
	{
		tem[i] = obj1.tem[i];
	}
	tem[len] = '\0';
	return tem;
}

void string1::outputs()
{
	cout << tem;
}
char *string1::cats(const string1 &obj1, const string1 &obj2)
{
	int len3 = obj1.lens() + obj2.lens() + 1;
	char *tem3 = new char[len3];
	int j = 0;
	for (int i = 0; i < len3; i++)
	{
		if (i < obj1.lens())
		{
			tem3[i] = obj1.tem[i];
		}
		else
		{
			tem3[i] = obj2.tem[j];
			j++;
		}
	}
	tem3[len3] = '\0';
	return tem3;
}

char* string1::cats(const string1 &obj2)
{
	return cats(*this, obj2);
}

void string1::reverses()
{
	char tmp;
	int len = this->lens() - 1;
	int j = len;
	for (int i = 0; i <= len / 2; i++)
	{
		tmp = this->tem[i];
		this->tem[i] = this->tem[len - i];
		this->tem[len - i] = tmp;
	}
}

int string1::cmps(const string1 &obj1, const string1 &obj2)
{
	int len = (obj1.lens() > obj2.lens() ? obj1.lens() : obj2.lens());
	int i = 0;
	for (i = 0; i < len; i++)
	{
		if (obj1.tem[i] > obj2.tem[i])
		{
			return 1;
		}
		else if (obj1.tem[i] < obj2.tem[i])
		{
			return -1;
		}
	}
	return 0;
}

istream &operator >> (istream &in, string1 &s)
{
	s.inputs();
	return in;
}
ostream &operator << (ostream &out, string1 &s)
{
	s.outputs();
	return out;
}
void string1::deletes()
{
	if (this->tem != NULL)
	{
		free(tem);
		tem = NULL;
	}
}
string1::~string1()
{
	if (this->tem != NULL)
	{
		free(tem);
	}
}

string1 operator +(const string1 &obj1, const string1 &obj2)
{
	string1 temp;
	return string1(temp.cats(obj1, obj2));
}

//int operator> (const string1 &obj1, const string1 &obj2);
//int operator< (const string1 &obj1, const string1 &obj2);
//int operator>= (const string1 &obj1, const string1 &obj2);
string1 string1::operator = (const string1 &obj1)
{
	free(tem);
	int len = obj1.lens();
	tem = (char*)malloc(len + 1);
	for (int i = 0; i < len; i++)
	{
		tem[i] = obj1.tem[i];
	}
	tem[len] = '\0';
	return string1(tem);
}
//int operator<= (const string1 &obj1, const string1 &obj2);
//string1 operator+= (const string1 &obj1, const string1 &obj2);

#include "Student.h"
#include <iostream>

Student::Student()
{
	Name = "";
	Account = "";
	sql = 0;
	cBasic = 0;
	cpp = 0;
}

Student::Student(std::string name, int id, float mark1, float mark2, float mark3)
{
	Name = name;
	Account = id;
	sql = mark1;
	cBasic = mark2;
	cpp = mark3;
}

Student::~Student()
{

}

void Student::input()				/*Nhap 1 sinh vien*/
{
	std::cout << "\nEnter name: ";
	std::getline(std::cin, Name);
	std::cout << "\nEnter account: ";
	std::getline(std::cin, Account);
	std::cout << "\nEnter sql mark: ";
	std::cin >> sql;
	std::cout << "\nEnter cbasic mark: ";
	std::cin >> cBasic;
	std::cout << "\nEnter cpp mark: ";
	std::cin >> cpp;
}

void Student::output()				/*in ra 1 sinh vien*/
{
	std::cout << "\n" << Name << "\t" << Account << "\t" << sql << "\t" << cBasic << "\t" << cpp;
}

std::string Student::get_name()
{
	return Name;
}

void Student::set_name(std::string name)
{
	Name = name;
}

std::string Student::get_account()
{
	return Account;
}

void Student::set_account(std::string account)
{
	Account = account;
}

float Student::get_sql()
{
	return sql;
}

void Student::set_sql(float mark1)
{
	sql = mark1;
}

float Student::get_cBasic()
{
	return cBasic;
}
void Student::set_cBasic(float mark2)
{
	cBasic = mark2;
}

float Student::get_cpp()
{
	return cpp;
}

void Student::set_cpp(float mark3)
{
	cpp = mark3;
}
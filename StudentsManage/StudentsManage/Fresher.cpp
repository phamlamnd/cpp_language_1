#include "Fresher.h"
#include "Student.h"

Fresher::Fresher()
{
	studentList = NULL;
	n = 0;
	nameTrainer = "";
}

Fresher::Fresher(Student* list, int number, std::string name)
{
	studentList = new Student[n];
	for (int i = 0; i < number; i++)
	{
		studentList[i].set_name(list[i].get_name);
		studentList[i].set_account(list[i].get_account);
		studentList[i].set_sql(list[i].get_sql);
		studentList[i].set_cBasic(list[i].get_cBasic);
		studentList[i].set_cpp(list[i].get_cpp);
	}
	n = number;
	nameTrainer = name;
}

Fresher::~Fresher()
{
	delete[] studentList;
}

void Fresher::REALLOC(int number)
{
	Student *tmp = new Student[number];
	for (int i = 0; i < n; i++)
	{
		tmp[i].set_name(studentList[i].get_name);
		tmp[i].set_account(studentList[i].get_account);
		tmp[i].set_sql(studentList[i].get_sql);
		tmp[i].set_cBasic(studentList[i].get_cBasic);
		tmp[i].set_cpp(studentList[i].get_cpp);
	}
	if (studentList != NULL)
	{
		delete[] studentList;
	}
	studentList = tmp;
	n = number;
}

void Fresher::inputFresherList()
{
	REALLOC(n + 1);
	studentList[n].input();
}

void Fresher::printFresherList()
{
	for (int i = 0; i < n; i++)
	{
		studentList[i].output();
	}
}

/*Ti?p ph?n ??c ghi ra file*/
void Fresher::writeToFile(std::string filename)		/*Ghi ra file*/
{

}
void Fresher::readFromFile(std::string filename)	/*Doc tu file*/
{

}
void Fresher::delID()								/*Xóa theo ID, và ph?i c?p nh?t d? li?u c?a file luôn*/
{

}

/*Trường viết hết phần tìm kiếm sắp xếp các kiểu luôn*/
void Fresher::sortSumMark()		/*Sap xep theo diem trung binh*/
{

}
void Fresher::sortName()		/*Sap xep theo ten*/
{

}
void Fresher::searchName()		/*Tim kiem theo ten*/
{

}
void Fresher::searchID()		/*Tim kiem theo ID*/
{

}
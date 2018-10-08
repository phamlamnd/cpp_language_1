#ifndef _FRESHER_H_
#define _FRESHER_H_
#include "Student.h"
#include <string>

class Fresher
{
private:
	Student* studentList;		/*Danh sach hoc vien*/
	int n;						/*So luong hoc vien*/
	std::string nameTrainer;	/*Ten nguoi huong dan*/
public:

	/*Lam phan giao dien khoi tao khai bao class*/
	Fresher();
	Fresher(Student* list, int n, std::string name);
	~Fresher();
	
	void REALLOC(int number);
	void inputFresherList();
	void printFresherList();

	/*Tiep phan doc ghi file*/
	void writeToFile(std::string filename);		/*Ghi ra file*/
	void readFromFile(std::string filename);	/*Doc tu file*/
	void delID();								/*Xóa theo ID, và ph?i c?p nh?t d? li?u c?a file luôn*/

	/*Truong phan sap xep tim kiem cac kieu luon*/
	void sortSumMark();		/*Sap xep theo diem trung binh*/
	void sortName();		/*Sap xep theo ten*/
	void searchName();		/*Tim kiem theo ten*/
	void searchID();		/*Tim kiem theo ID*/
};

#endif

#ifndef _STUDENT_H_
#define _STUDENT_H_
#define MAX 100
#include <string>

struct Student
{
	std::string Account;
	std::string Name;
	int Code;
};

char selectMenu();
void inputStudent(struct Student* studentsList[], int &n);
void printStudent(struct Student* studentsList[], int n);
void searchStudent(struct Student* studentsList[], int n, std::string accountSearch);
void deleteStudent(struct Student* studentsList[], int &n, int codeDelete);
void freeList(struct Student* studentsList[], int n);

#endif
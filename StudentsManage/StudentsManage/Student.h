#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <string>

class Student
{
private:
	std::string Name;
	std::string Account;
	float sql;
	float cBasic;
	float cpp;
public:
	Student();
	Student(std::string name, int id, float sql, float cBasic, float cpp);
	~Student();

	void input();				/*Nhap 1 sinh vien*/
	void output();				/*in ra 1 sinh vien*/

	std::string get_name();
	void set_name(std::string name);

	std::string get_account();
	void set_account(std::string account);

	float get_sql();
	void set_sql(float mark1);

	float get_cBasic();
	void set_cBasic(float mark2);

	float get_cpp();
	void set_cpp(float mark3);
};

#endif
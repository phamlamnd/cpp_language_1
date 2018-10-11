#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include <iostream>
class MyString
{
private:
	char *str;
public:
	MyString();							/*Default contructor*/
	MyString(const char *buf);			/*Parameter contructor*/
	MyString(const MyString &obj);		/*Copy contructor*/
	~MyString();						/*Destructor*/
	char *get_str(void);
	void set_str(const char *buf);
	void input(void);
	void print(void);
	void delele(void);
	char* strcat(const char *buf);
	char* strcat(const MyString &obj);
	char* reverse(void);
	int length(void);
	int compare(const MyString &obj);
	void operator= (const MyString &obj);
	MyString operator+ (const MyString &obj);
	friend std::ostream& operator<<(std::ostream &out, const MyString &obj);
};

#endif
/*
Định nghĩa lại lớp String để thể hiện chuỗi ký tự với các chức năng
- Input / nhập chuỗi
- Xóa chuỗi
- Ghép chuỗi
- Đảo chuỗi
- Tính chiều dài
- So sánh 2 chuỗi
- Xuất màn hình
= > Dùng char*, không dùng String của C++
Hướng dẫn :
-Dùng copy contructor
- Dùng overload function và overload operator*/
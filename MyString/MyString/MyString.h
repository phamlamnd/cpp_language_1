#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include <iostream>
class MyString
{
private:
	char *m_str;
public:
	MyString() :m_str(NULL) {}													/*default contructor		*/
	MyString(const char *buf);													/*parameter contructor		*/
	MyString(const MyString &obj);												/*copy contructor			*/
	~MyString();																/*destructor				*/
	const char* getStr(void) const;												/*get string				*/
	void setStr(const char *buf);												/*set string				*/
	void input(void);															/*input string				*/
	void output(void) const;													/*output string				*/
	void del(void);																/*delete string				*/
	MyString& cat(const char *buf);												/*cat with C style string	*/
	MyString& cat(const MyString &obj);											/*cat two mystring			*/
	MyString& rev(void);														/*reveser string			*/
	int leng(void) const;														/*get string length			*/
	int comp(const MyString &obj) const;										/*compare two mystring		*/
	char& operator[] (const int index);											/*subscript operator[]		*/
	operator char*();															/*Overloading typecasts		*/
	MyString& operator= (const MyString &obj);									/*overload operator=		*/
	friend bool operator== (const MyString &obj1, const MyString &obj2);		/*overload operator==		*/
	friend bool operator!= (const MyString &obj1, const MyString &obj2);		/*overload operator!=		*/
	friend bool operator> (const MyString &obj1, const MyString &obj2);			/*overload operator>		*/
	friend bool operator>= (const MyString &obj1, const MyString &obj2);		/*overload operator>=		*/
	friend bool operator< (const MyString &obj1, const MyString &obj2);			/*overload operator<		*/
	friend bool operator<= (const MyString &obj1, const MyString &obj2);		/*overload operator<=		*/
	friend MyString operator+ (const MyString &obj1, const MyString &obj2);		/*overload operator+		*/
	friend MyString operator+ (const MyString &obj, const char* buf);			/*overload operator+		*/
	friend MyString operator+ (const char* buf, const MyString &obj);			/*overload operator+		*/
	MyString& operator+= (const MyString &obj);									/*overload operator+=		*/
	MyString& operator+= (const char* buf);										/*overload operator+=		*/
	friend std::istream& operator>> (std::istream &in, MyString &obj);			/*overload operator>>		*/
	friend std::ostream& operator<< (std::ostream &out, const MyString &obj);	/*overload operator<<		*/
};
#endif /*_MYSTRING_H_*/

/*Định nghĩa lại lớp String để thể hiện chuỗi ký tự với các chức năng
- Input / nhập chuỗi
- Xóa chuỗi
- Ghép chuỗi
- Đảo chuỗi
- Tính chiều dài
- So sánh 2 chuỗi
- Xuất màn hình
=> Dùng char*, không dùng String của C++
Hướng dẫn:
- Dùng copy contructor
- Dùng overload function và overload operator*/
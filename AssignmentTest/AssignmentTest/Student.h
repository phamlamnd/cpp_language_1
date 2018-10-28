#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <string>
#include <iostream>
class Student
{
protected:
	std::string m_ID;
	std::string m_Name;
	std::string m_ClassID;
	std::string m_Rank;
public:
	Student(std::string id = "", std::string name = "", std::string classid = "", std::string rank = "")
		:m_ID(id), m_Name(name), m_ClassID(classid), m_Rank(rank){}
	std::string getID() const;
	std::string getName() const;
	std::string getClassID() const;
	std::string getRank() const;
	void setID(const std::string &id);
	void setName(const std::string &name);
	void setClassID(const std::string &classid);
	void setRank(const std::string &rank);
	friend std::ostream& operator<< (std::ostream& out, const Student& obj);
	friend std::istream& operator>> (std::istream& in, Student& obj);
};
#endif /*_STUDENT_H_*/
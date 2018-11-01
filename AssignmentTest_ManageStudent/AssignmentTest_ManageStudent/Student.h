#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <iostream>
#include <string>
#include <fstream>
class Student
{
protected:
	std::string m_ID;
	std::string m_Name;
	std::string m_ClassID;
	std::string m_Rank;
public:
	static int countStudent;
	Student();
	Student(const std::string id, 
		const std::string name, 
		const std::string classId, 
		const std::string rank);
	~Student();
	std::string getID() const { return m_ID; }
	std::string getName() const { return m_Name; }
	std::string getLastName() const;
	std::string getClassID() const { return m_ClassID; }
	std::string getRank() const { return m_Rank; }
	void setClassID(std::string classId) { m_ClassID = classId; }
	void setName(std::string name) { m_Name = name; }
	void setRank(std::string rank) { m_Rank = rank; }
	void printStudentInfo();
	void input();
	friend std::ofstream& operator<< (std::ofstream& out, const Student& student); //write to file
};
#endif /*_STUDENT_H_*/

#include "ClassManager.h"
void ClassManager::inputFromConsole()
{
	std::cout << "Input number class: ";
	int numberClass;
	std::cin >> numberClass;
	m_ClassList.resize(numberClass);
	std::vector<ClassStudent>::iterator it;
	for (it = m_ClassList.begin(); it != m_ClassList.end(); ++it)
	{
		(*it).addStudent();
	}
}

void ClassManager::outputToConsole()
{
	std::vector<ClassStudent>::iterator it;
	for (it = m_ClassList.begin(); it != m_ClassList.end(); ++it)
	{
		(*it).printClass();
	}
}

void ClassManager::inputFromFile(std::string filename)
{
	std::fstream fileIn;
	fileIn.open(filename, std::ios::in);
	if (fileIn.fail())
	{
		std::cout << "Open file error!";
		return;
	}
	
	while (!fileIn.eof())
	{
		std::string id;
		std::string name;
		std::string classid;
		std::string rank;
		std::getline(fileIn, id, ',');
		std::getline(fileIn, name, ',');
		std::getline(fileIn, classid, ',');
		std::getline(fileIn, rank, '\n');

		Student student(id, name, classid, rank);
 		std::vector<ClassStudent>::iterator classListInterator;
		bool checkClassID = false;
		for (classListInterator = m_ClassList.begin(); classListInterator != m_ClassList.end(); ++classListInterator)
		{
			if ((*classListInterator).getStudentList()[0].getClassID() == classid)
			{
				checkClassID = true;
				(*classListInterator).getStudentList().push_back(student);
				break;
			}
		}

		if (false == checkClassID || 0 == m_ClassList.size())
		{
			ClassStudent classStudent(student);
			m_ClassList.push_back(classStudent);
		}
	}
	fileIn.close();
}

void ClassManager::searchName(std::string name)
{
	for (int i = 0; i < m_ClassList.size(); i++)
	{
		for (int j = 0; j < m_ClassList[i].getStudentList().size(); j++)
		{
			if (m_ClassList[i].getStudentList()[j].getName() == name)
			{
				std::cout << m_ClassList[i].getStudentList()[j] << std::endl;
			}
		}
	}
}

void ClassManager::searchClassID(std::string classid)
{
	for (int i = 0; i < m_ClassList.size(); i++)
	{
		for (int j = 0; j < m_ClassList[i].getStudentList().size(); j++)
		{
			if (m_ClassList[i].getStudentList()[j].getClassID() == classid)
			{
				std::cout << m_ClassList[i].getStudentList()[j] << std::endl;
			}
		}
	}
}

void ClassManager::searchRank(std::string rank)
{
	for (int i = 0; i < m_ClassList.size(); i++)
	{
		for (int j = 0; j < m_ClassList[i].getStudentList().size(); j++)
		{
			if (m_ClassList[i].getStudentList()[j].getRank() == rank)
			{
				std::cout << m_ClassList[i].getStudentList()[j] << std::endl;
			}
		}
	}
}

void ClassManager::searchID(std::string id)
{
	for (int i = 0; i < m_ClassList.size(); i++)
	{
		for (int j = 0; j < m_ClassList[i].getStudentList().size(); j++)
		{
			if (m_ClassList[i].getStudentList()[j].getID() == id)
			{
				std::cout << m_ClassList[i].getStudentList()[j] << std::endl;
				return;
			}
		}
	}
}

void ClassManager::deleteID(std::string id)
{
	for (int i = 0; i < m_ClassList.size(); i++)
	{
		for (int j = 0; j < m_ClassList[i].getStudentList().size(); j++)
		{
			if (m_ClassList[i].getStudentList()[j].getID() == id)
			{
				m_ClassList[i].getStudentList().erase(m_ClassList[i].getStudentList().begin() + j);
			}
		}
	}
}

void ClassManager::bubbleSort()
{
	std::vector<Student> v;
	for (int i = 0; i < m_ClassList.size() - 1; i++)
	{
		for (int j = m_ClassList[i].getStudentList().size() - 1; j > 0; j--)
		{
			v.push_back(m_ClassList[i].getStudentList()[j]);
		}
	}

	for (int i = 0; i < v.size() - 1; i++)
	{
		for (int j = v.size() - 1; j > 0; j--)
		{
			if (v[j].getName() < v[j - 1].getName())
			{
				Student tmp = v[j];
				v[j] = v[j - 1];
				v[j - 1] = tmp;
			}
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}
}
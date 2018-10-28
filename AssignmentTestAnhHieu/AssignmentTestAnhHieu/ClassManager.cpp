#include "ClassManager.h"
#include <fstream>
#include <sstream>


ClassManager::ClassManager()
{
}


ClassManager::~ClassManager()
{
	m_ClassList.clear();
}

void ClassManager::loadDataFromFile()
{
	ifstream in( FILE_NAME );
	string line;
	string id;
	string name;
	string classId;
	string rank;
	while( getline( in, line ) )                   // read a whole line of the file
	{
		stringstream ss( line );                     // put it in a stringstream (internal stream)
		string data;

		// get id
		getline( ss, id, ',' );
		// get name
		getline( ss, name, ',' );
		// get class id
		getline( ss, classId, ',' );
		// get rank
		getline( ss, rank, ',' );

		//cout << id << " - " << name << " - " << classId << " - " << rank << endl;
		Student student( id, name, classId, rank );
		ClassStudent *classStudent = this->getClassStudent( classId );
		if( NULL == classStudent )
		{
			ClassStudent classStud( classId );
			classStud.addStudent( student );

			m_ClassList.push_back( classStud );
		}
		else
		{
			classStudent->addStudent( student );
		}
	}
}

void ClassManager::printAllClassInfo()
{
	vector< ClassStudent >::iterator classIter;
	classIter = m_ClassList.begin();
	for( ; classIter != m_ClassList.end(); classIter++ )
	{
		( *classIter ).printAllStudentInfo();
	}
}

void ClassManager::search( const string searchData, const SEARCH_BY & searchKey )
{
	vector< ClassStudent >::iterator classIter;
	classIter = m_ClassList.begin();
	for( ; classIter != m_ClassList.end(); classIter++ )
	{
		( *classIter ).search( searchData, searchKey );
	}
}

void ClassManager::deleteStudent( const string studentId )
{
}

void ClassManager::sort( const SORT_BY & sortKey )
{
}

ClassStudent * ClassManager::getClassStudent( const string classId )
{
	ClassStudent * classStudent = NULL;
	vector< ClassStudent >::iterator classIter;
	classIter = m_ClassList.begin();
	for ( ; classIter != m_ClassList.end(); classIter++ )
	{
		if ( (*classIter).getClassId() == classId )
		{
			return &( *classIter );
		}
	}

	return NULL;
}

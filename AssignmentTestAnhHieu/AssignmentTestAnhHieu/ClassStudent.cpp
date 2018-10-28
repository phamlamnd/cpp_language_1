#include "ClassStudent.h"

ClassStudent::ClassStudent( string classId )
{
	m_ClassID = classId;
}

ClassStudent::~ClassStudent()
{
	m_StudentList.clear();
}

void ClassStudent::printAllStudentInfo()
{
	vector< Student >::iterator classIter;
	classIter = m_StudentList.begin();
	for( ; classIter != m_StudentList.end(); classIter++ )
	{
		( *classIter ).printStudentInfo();
	}
}

void ClassStudent::addStudent( const Student & student )
{
	m_StudentList.push_back( student );
}

void ClassStudent::search( const string searchData, const SEARCH_BY & searchKey )
{
	vector< Student >::iterator classIter;
	classIter = m_StudentList.begin();
	string studentInfo;
	for( ; classIter != m_StudentList.end(); classIter++ )
	{
		switch( searchKey )
		{
			case SEARCH_ID:
				studentInfo = ( *classIter ).getID();
				break;
			case SEARCH_NAME:
				studentInfo = ( *classIter ).getName();
				break;
			case SEARCH_CLASSID:
				studentInfo = ( *classIter ).getClassId();
				break;
			case SEARCH_RANK:
				studentInfo = ( *classIter ).getRank();
				break;
			default:
				break;
		}

		if ( studentInfo == searchData )
		{
			( *classIter ).printStudentInfo();
		}
	}
}

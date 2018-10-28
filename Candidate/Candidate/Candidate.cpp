#include <iostream>
#include <string>

class Day
{
private:
	int m_day;
	int m_month;
	int m_year;
public:
	Day() :m_day(0), m_month(0), m_year(0)
	{
	}
	Day(int day, int month, int year) :m_day(day), m_month(month), m_year(year)
	{
	}
	Day(const Day& d)
	{
		m_day = d.m_day;
		m_month = d.m_month;
		m_year = d.m_year;
	}
	~Day(){}
	Day& operator= (const Day& d)
	{
		m_day = d.m_day;
		m_month = d.m_month;
		m_year = d.m_year;
		return *this;
	}
	friend std::ostream& operator<< (std::ostream& out, const Day& d)
	{
		out << d.m_day << "/" << d.m_month << "/" << d.m_year;
		return out;
	}
	friend std::istream& operator>> (std::istream& in, Day& d)
	{
		in >> d.m_day;
		in.ignore();
		in >> d.m_month;
		in.ignore();
		in >> d.m_year;
		return in;
	}
};

class Candidate
{
private:
	int *a;
	std::string m_code;
	std::string m_name;
	Day m_birth;
	double m_math;
	double m_lite;
	double m_eng;
public:
	Candidate() :m_code(""), m_name(""), m_birth(0, 0, 0), m_math(0.0), m_lite(0.0), m_eng(0.0)
	{
		a = new int(0);
	}
	Candidate(const std::string &code, const std::string &name, const Day &d, const double &math, const double &lite, const double &eng)
		:m_code(code), m_name(name), m_birth(d), m_math(math), m_lite(lite), m_eng(eng)
	{
		a = new int(5);
	}
	Candidate(const Candidate& c) 
		:m_code(c.m_code), m_name(c.m_name), m_birth(c.m_birth), m_math(c.m_math), m_lite(c.m_lite), m_eng(c.m_eng)
	{
		a = new int;
		*a = *(c.a);
		std::cout << "copy contructor" << std::endl;
	}
	~Candidate()
	{
		delete a;
	}
	Candidate operator= (const Candidate& c)
	{
		std::cout << "Address *this: " << this << std::endl;
		delete a;
		a = new int;
		*a = *(c.a);
		m_code = c.m_code;
		m_name = c.m_name;
		m_birth = c.m_birth;
		m_math = c.m_math;
		m_lite = c.m_lite;
		m_eng = c.m_eng;
		return *this;
	}
	friend std::ostream& operator<< (std::ostream& out, const Candidate& c)
	{
		out << "\t" << c.m_code << "\t" << c.m_name << "\t" << c.m_birth << "\t" << c.m_math << "\t" << c.m_lite << "\t" << c.m_eng;
		return out;
	}
};

int main()
{
	Candidate a("A", "A", Day(1, 2, 3), 7, 8, 9);
	Candidate b("B", "B", Day(1, 2, 3), 7, 8, 9);
	Candidate c("C", "C", Day(1, 2, 3), 7, 8, 9);
	a = b = c;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	system("pause");
	return 0;
}
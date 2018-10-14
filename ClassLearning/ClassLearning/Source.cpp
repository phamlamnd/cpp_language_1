#include <iostream>
#include "Header.h"
class Line
{
private:
	double length;
	int  *ptr;
public:
	static double with;			//static member
	static double getWith();	//static fuunction
	void setLength(double len);
	double getLength(void);
	Line();						//Default contructor
	Line(double len);			//Parameterried Contructor
	Line(const Line &obj);		//Copy contructor	
	~Line();					//Destructor
	friend void print(Line l);	//friend function
	
};
/*Init static member*/
double Line::with = 0;

/*Static function only access static data member, and static member function*/
double Line::getWith()
{
	return with;
}

/*friend function*/
void print(Line l) 
{
	std::cout << l.length;
}
/*Default contructor*/
Line::Line(void)
{
	std::cout << "Object is being created";
}

/*Parameterried Contructor*/
Line::Line(double len) : length(len) {}	//Using Initialization list to Inittialize Field

/*Copy contructor*/
Line::Line(const Line &obj)
{
	ptr = new int;
	*ptr = *obj.ptr;
}

/*Destructor*/
Line::~Line()
{
	std::cout << "Object is being deleted";
	delete ptr;
}

void Line::setLength(double len)
{
	length = len;
}

double Line::getLength(void)
{
	return length;
}

void display(Line obj)
{
	std::cout << obj.getLength();
}

class Box
{
private:
	double with;
	double length;
	double high;
public:
	Box(){}
	Box(double w, double l, double h) : with(w), length(l), high(h){}
	double get_with() { return with; }
	double get_length() { return length; }
	double get_high() { return high; }
};

class A
{
public:
	A() { std::cout << "A"; }
};

class B
{
private:
	A m_a;
public:
	B() { std::cout << "B"; }
};

class Something
{
private:
	static int s_value;
	std::string m_value;
public:
	Something(const std::string &value = "") { m_value = value; }
	std::string& get_value() { return m_value; }
	const std::string& get_value() const { return m_value; }
	~Something(){}
};

int Something::s_value = 0;

int main()
{
	Something st;
	st.get_value();
	system("pause");
	return 0;
}
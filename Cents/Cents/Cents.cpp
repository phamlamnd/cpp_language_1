#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Employee
{
private:
	int m_id;
	std::string m_name;

public:
	Employee(int id = 0, const std::string &name = "") : m_id(id), m_name(name)
	{
		std::cout << "Employee " << m_name << " created.\n";
	}

	// Use a delegating constructors to minimize redundant code
	Employee(const std::string &name) : Employee(0, name) { }
};

class Foo
{
private:
	int *m_ptr;
public:
	Foo()
	{
		m_ptr = new int;
		//do A
	}
	Foo(int value) : Foo()	//delegating constructors
	{
		//do B
	}
	~Foo()
	{
		delete m_ptr;
		std::cout << "Distructor";
	}
	void DoA() const
	{

	}
	void DoB() const
	{
		DoA();
	}
};

class A
{
public:
	A(int x) { std::cout << "A" << x << std::endl; }
};

class B
{
private:
	A m_a;
public:
	B(int y) :m_a(y - 1)  //call A(int x) contructor to init member m_a
	{ 
		std::cout << "B" << y << std::endl; 
	}
};

class Line
{
private:
	double m_length{0};			//double length = 5, non-static member init
	int  *m_ptr = NULL;			//non-static member init
	const int m_arr[5];
public:
	Line() : m_length{ 0 }, m_ptr(NULL), m_arr{1, 2, 3, 4, 5} //member initializer lists
	{

	}	

	Line(double len) : Line()
	{
		m_length = len;
	}

	Line::Line(const Line &obj) : m_arr{}
	{
		m_ptr = new int;
		*m_ptr = *obj.m_ptr;
	}

	Line::~Line()
	{
		std::cout << "Object is being deleted";
		delete m_ptr;
	}

	void setLength(double len);
	double getLength(void);
};

void Line::setLength(double len)
{
	m_length = len;
}

double Line::getLength(void)
{
	return m_length;
}

void display(Line obj)
{
	std::cout << obj.getLength();
}

/*operator+*/
class Cents
{
private:
	int m_cents;
public:
	Cents(int cents) { m_cents = cents; }
	Cents operator-() const
	{
		return Cents(-m_cents);
	}
	int getCents() const { return m_cents; }
	friend std::ostream& operator<< (std::ostream& out, const Cents &c)
	{
		std::cout << c.m_cents;
		return out;
	}
	friend bool operator== (const Cents &c1, const Cents &c2)
	{
		return c1.m_cents == c2.m_cents;
	}
	friend bool operator!= (const Cents &c1, const Cents &c2)
	{
		return !(c1 == c2);
	}
	friend bool operator> (const Cents &c1, const Cents &c2)
	{
		return c1.m_cents > c2.m_cents;
	}
	friend bool operator>= (const Cents &c1, const Cents &c2)
	{
		return !(c1 < c2);
	}
	friend bool operator< (const Cents &c1, const Cents &c2)
	{
		return c1.m_cents < c2.m_cents;
	}
	friend bool operator<= (const Cents &c1, const Cents &c2)
	{
		return !(c1 > c2);
	}
};

/*operator!*/
class Point
{
private:
	double m_x, m_y, m_z;
public:
	Point(double x = 0.0, double y = 0.0, double z = 0.0):m_x(x), m_y(y), m_z(z){}

	Point operator-() const
	{
		return Point(-m_x, -m_y, -m_z);
	}

	bool operator!() const
	{
		return (m_x == 0.0 && m_y == 0.0 && m_z == 0.0);
	}

	friend std::ostream& operator<< (std::ostream& out, const Point &point)
	{
		out << "(" << point.m_x << "," << point.m_y << "," << point.m_z << ")";
		return out;
	}
};

class Car
{
private:
	std::string m_make;
	std::string m_model;
public:
	Car(std::string make, std::string model):m_make(make), m_model(model){}
	~Car(){}
	std::string getMake() const { return m_make; }
	std::string getModel() const { return m_model; }
	friend bool operator< (const Car &c1, const Car & c2)
	{
		return (c1.m_make < c2.m_make) || ((c1.m_make == c2.m_make) && (c1.m_model < c2.m_model));
	}
	friend std::ostream& operator<< (std::ostream& out, const Car &c)
	{
		out << "(" << c.m_make << "," << c.m_model << ")";
		return out;
	}
};

class Digit
{
private:
	int m_digit;
public:
	Digit(int digit = 0):m_digit(digit){}
	~Digit(){}
	Digit& operator++(); /*prefix*/
	Digit& operator--(); /*prefix*/
	Digit operator++(int); /*postfix*/
	Digit operator--(int); /*postfix*/
	friend std::ostream& operator<< (std::ostream& out, const Digit &d);
};

Digit& Digit::operator++()
{
	if (m_digit == 9)
	{
		m_digit = 0;
	}
	else
	{
		++m_digit;
	}
	return *this;
}

Digit& Digit::operator--()
{
	if (m_digit == 0)
	{
		m_digit = 9;
	}
	else
	{
		--m_digit;
	}
	return *this;
}

Digit Digit::operator++(int) /*postfix*/
{
	Digit tmp(m_digit);
	++(*this);
	return tmp;
}

Digit Digit::operator--(int) /*postfix*/
{
	Digit tmp(m_digit);
	--(*this);
	return tmp;
}

std::ostream& operator<< (std::ostream& out, const Digit &d)
{
	std::cout << d.m_digit;
	return out;
}

void Fun_Car_Vector()
{
	std::vector<Car> v;
	v.push_back(Car("Toyota", "Corolla"));
	v.push_back(Car("Honda", "Accord"));
	v.push_back(Car("Toyota", "Camry"));
	v.push_back(Car("Honda", "Civic"));

	std::sort(v.begin(), v.end());
	for (auto &car : v)
	{
		std::cout << car << std::endl;
	}
}

class Book
{
private:
	std::string m_name;
public:
	Book():m_name("")
	{
		std::cout << "Default contructor" << std::endl;
	}
	Book(const char *name):m_name(name)
	{
		std::cout << "Parameter contructor 1" << std::endl;
	}
	Book(std::string name):m_name(name)
	{
		std::cout << "Parameter contructor 2" << std::endl;
	}
	Book(const Book& book):m_name(book.m_name)
	{
		std::cout << "Copy contructor" << std::endl;
	}
	~Book() 
	{ 
		std::cout << "Distructor" << std::endl;
	}
	std::string getName() const { return m_name; }
	Book& operator= (const Book& book) 
	{ 
		std::cout << "Operator=" << std::endl;
		m_name = book.m_name; return *this; 
	}
	friend std::ostream& operator<< (std::ostream& out, const Book& book)
	{
		std::cout << book.m_name << std::endl;
		return out;
	}
};
	Book getBook(Book book)
	{
		return book;
	}
int main()
{
	Book book1("AMA");
	book1 = "a";
	//std::cout << getBook("A");
	system("pause");
	return 0;
}
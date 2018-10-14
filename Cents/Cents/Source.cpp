#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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

int main()
{
	Digit digit(1);
	++digit;
	std::cout << "digit = " << digit++ << std::endl;

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

	Cents nickle(5);
	std::cout << (-nickle).getCents() << std::endl;
	Point point(2,3,4);
	std::cout << -point << std::endl;
	if (!point)
	{
		std::cout << "Point set origin";
	}
	else
	{
		std::cout << "Point not set origin";
	}
	system("pause");
	return 0;
}
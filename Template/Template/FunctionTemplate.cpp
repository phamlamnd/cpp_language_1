#include <iostream>

template <typename T>
const T& max(const T& x, const T& y)
{
	return (x > y) ? x : y;
}

class Cents
{
private:
	double m_value;
public:
	Cents(double value = 0) :m_value(value){}
	friend bool operator> (const Cents& c1, const Cents& c2)
	{
		return (c1.m_value > c2.m_value);
	}
	friend std::ostream& operator<< (std::ostream& out, const Cents& c)
	{
		std::cout << "Cents: " << c.m_value;
		return out;
	}
	~Cents(){}
};

//int main()
//{
//	std::cout << max(2, 3) << std::endl;
//	std::cout << max(1.2, 3.4) << std::endl;
//	Cents c1(2);
//	Cents c2(3);
//	std::cout << max(c1, c2);
//
//	system("pause");
//	return 0;
//}
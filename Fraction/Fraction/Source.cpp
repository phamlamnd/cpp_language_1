#include <iostream>

class Fraction
{
private:
	int m_numerator;
	int m_denominator;
public:
	Fraction(int numerator = 0, int denominator = 1):m_numerator(numerator), m_denominator(denominator)
	{
		reduce();
	}
	static int gcd(int a, int b)
	{
		return b == 0 ? a : gcd(b, a % b);
	}

	void reduce()
	{
		int gcd = Fraction::gcd(m_numerator, m_denominator);
		m_numerator /= gcd;
		m_denominator /= gcd;
	}

	friend Fraction operator* (const Fraction &f1, const Fraction &f2)
	{
		return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
	}

	friend Fraction operator* (const Fraction &f1, int value)
	{
		return Fraction(f1.m_numerator * value, f1.m_denominator);
	}

	friend Fraction operator* (int value, const Fraction &f2)
	{
		return Fraction(value * f2.m_numerator, f2.m_denominator);
	}

	friend std::ostream& operator<< (std::ostream &out, const Fraction &f)
	{
		std::cout << f.m_numerator << "/" << f.m_denominator;
		return out;
	}

	friend std::istream& operator>> (std::istream &in, Fraction &f)
	{
		std::cin >> f.m_numerator;
		std::cin.ignore();	//enter /
		std::cin>> f.m_denominator;
		f.reduce();
		return in;
	}
};

int main()
{

	Fraction f1;
	std::cout << "\nEnter Fraction 1: ";
	std::cin >> f1;

	Fraction f2;
	std::cout << "\nEnter Fraction 2: ";
	std::cin >> f2;

	std::cout << f1 << " * " << f2 << " is " << f1*f2 << std::endl;

	system("pause");
	return 0;
}
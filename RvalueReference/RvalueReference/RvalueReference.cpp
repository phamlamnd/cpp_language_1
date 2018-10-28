#include <iostream>

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator(numerator), m_denominator(denominator)
	{
		std::cout << "contructor";
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction &f1)
	{
		out << f1.m_numerator << "/" << f1.m_denominator;
		return out;
	}
	~Fraction()
	{
		std::cout << "distructor";
	}
};

int main()
{
	int &&x = 5;
	Fraction(3, 5);
	Fraction &rref = Fraction(3, 5); // r-value reference to temporary Fraction
	std::cout << rref << '\n';

	system("pause");
	return 0;
} // rref (and the temporary Fraction) goes out of scope here
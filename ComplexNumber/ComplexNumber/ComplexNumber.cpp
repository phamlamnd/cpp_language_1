#include <iostream>
#include <iomanip>
class ComplexNumBer
{
private:
	double m_real;
	double m_imag;
public:
	ComplexNumBer() : m_real(0.0) , m_imag(0.0)
	{
	}
	ComplexNumBer(const double &real, const double &imag) : m_real(real), m_imag(imag)
	{
	}
	ComplexNumBer(const ComplexNumBer& complex)
	{
		m_real = complex.m_real;
		m_imag = complex.m_imag;
	}
	ComplexNumBer& operator= (const ComplexNumBer &complex)
	{
		m_real = complex.m_real;
		m_imag = complex.m_imag;
		return *this;
	}
	friend std::istream& operator>> (std::istream& in, ComplexNumBer& complex)
	{
		in >> complex.m_real;
		in >> complex.m_imag;
		return in;
	}
	friend std::ostream& operator<< (std::ostream& out, const ComplexNumBer& complex)
	{
		out << "(" << complex.m_real << ((complex.m_imag < 0.0) ? "" : "+") << complex.m_imag << "i)";
		return out;
	}
	friend ComplexNumBer operator+ (const ComplexNumBer& c1, const ComplexNumBer& c2)
	{
		return ComplexNumBer((c1.m_real + c2.m_real), (c1.m_imag + c2.m_imag));
	}
	friend ComplexNumBer operator- (const ComplexNumBer& c1, const ComplexNumBer& c2) 
	{
		return ComplexNumBer((c1.m_real - c2.m_real), (c1.m_imag - c2.m_imag));
	}
	friend ComplexNumBer operator* (const ComplexNumBer& c1, const ComplexNumBer& c2)
	{
		return ComplexNumBer((c1.m_real * c2.m_real - c1.m_imag * c2.m_imag), (c1.m_real * c2.m_imag + c1.m_imag * c2.m_real));
	}
	friend ComplexNumBer Conjugates(const ComplexNumBer& complex)
	{
		return ComplexNumBer(complex.m_real, -complex.m_imag);
	}
	friend ComplexNumBer operator/ (const ComplexNumBer& c1, const ComplexNumBer& c2)
	{
		ComplexNumBer num = ComplexNumBer(c1 * Conjugates(c2));
		ComplexNumBer den = ComplexNumBer(c2 * Conjugates(c2));
		double div = den.m_real;
		return ComplexNumBer(num.m_real / div, num.m_imag / div);
	}
};



int main()
{
	while (true)
	{
		ComplexNumBer complex1, complex2;
		std::cout << "\nEnter complex1:" << std::endl;
		std::cin >> complex1;
		std::cout << "\nEnter complex2:" << std::endl;
		std::cin >> complex2;

		std::cout << std::setprecision(2);
		std::cout << complex1 << " + " << complex2 << " = " << complex1 + complex2 << std::endl;
		std::cout << complex1 << " - " << complex2 << " = " << complex1 - complex2 << std::endl;
		std::cout << complex1 << " * " << complex2 << " = " << complex1 * complex2 << std::endl;
		std::cout << complex1 << " / " << complex2 << " = " << complex1 / complex2 << std::endl;

		std::cout << "1.Continue" << std::endl;
		std::cout << "q.Quit" << std::endl;
		std::cout << "Enter choise: ";
		
		std::cin.ignore();
		if ('q' == std::cin.get())
		{
			break;
		}
	}
	system("pause");
	return 0;
}
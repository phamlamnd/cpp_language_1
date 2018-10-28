#include <iostream>

template <class T>
class Array
{
private:
	int m_length;
	T *m_data;
public:
	Array() :m_length(0), m_data(NULL)
	{
	}

	Array(int length)
	{
		m_length = length;
		m_data = new T[length];
	}

	T& operator[] (const int index)
	{
		return m_data[index];
	}

	int getLength() const;

	~Array()
	{
		delete m_data;
		m_data = nullptr;
		m_length = 0;
	}
};

template <class T>
int Array<T>::getLength() const
{
	return m_length;
}

int main()
{
	Array<int> intArray(5);
	Array<double> doubleArray(5);
	for (int i = 0; i < intArray.getLength(); i++)
	{
		intArray[i] = i;
		doubleArray[i] = i + 0.5;
	}

	for (int i = 0; i < intArray.getLength(); i++)
	{
		std::cout << intArray[i] << "  " << doubleArray[i] << std::endl;
	}

	system("pause");
	return 0;
}
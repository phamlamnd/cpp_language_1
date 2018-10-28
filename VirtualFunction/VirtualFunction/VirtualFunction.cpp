#include <iostream>
#include <string>

class Base
{
protected:
	int m_value;
public:
	Base(int value = 0) : m_value(value)
	{
	}

	const char* getName() { return "Base"; }
	int getValue() { return m_value; }
};

class Derived : public Base
{
public:
	Derived(int value = 0) : Base(value)
	{
	}
	const char* getName() { return "Derived"; }
	int getValue() { return m_value * 2; }
};

class Animal
{
protected:
	std::string m_name;
	Animal(std::string name) :m_name(name) 
	{ 
	}
public:
	std::string getName() { return m_name; }
	virtual std::string speak() { return "???"; };
};

class Cat :public Animal
{
public:
	Cat(std::string name = "") :Animal(name)
	{
	}
	virtual std::string speak() override { return "MeowMeow"; } //Tu khoa override de dam bao ham nay duoc ghi de 1 ham o lop co so
};

class Dog /*final*/ :public Animal //Neu khong muon cho BackDog ke thua thi them tu khoa final
{
public:
	Dog(std::string name = "") :Animal(name)
	{
	}
	virtual std::string speak() override /*final*/ { return "WofWof"; } //Them tu khoa final neu khong muon cho lop BlackDog ghi de lai ham nay
};

void report(Animal &rAnimal)
{
	std::cout << rAnimal.getName() << " says " << rAnimal.speak() << std::endl;
}

class BlackDog :public Dog
{
	BlackDog(std::string name = "") :Dog(name)
	{
	}
	virtual std::string speak() override { return "BlackWofWof"; }
};

int main()
{
	
	Cat fred("Fred"), misty("Misty"), zeke("Zeke");
	Dog garbo("Garbo"), pook("Pook"), truffle("Truffle");
	Animal A = fred;
	std::cout << A.speak() << std::endl;
	Animal *animals[] { &fred, &misty, &zeke, &garbo, &pook, &truffle };
	              
	for (const auto &e : animals)
	{
		std::cout << e->getName() << " says " << e->speak() << std::endl;
	}
	system("pause");
	return 0;
}
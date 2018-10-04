#include <iostream>
#include <string>
class Student
{
private:
	std::string Name;
	float Mark;
public:
	std::string get_name();
	void set_name(std::string name);
};

int main()
{
	Student s1;
	s1.get_name();

	return 0;
}

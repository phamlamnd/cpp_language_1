#include <iostream>

class Line
{
private:
	double length;
	static int with;
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

int main()
{

	system("pause");
	return 0;
}
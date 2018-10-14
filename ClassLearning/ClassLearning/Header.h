#ifndef _TEST_H_
#define _TEST_H_
#include <iostream>
extern void printTest();
class Test
{
public:
	Test::Test() { std::cout << "A"; }
	Test::~Test() {}
};

#endif
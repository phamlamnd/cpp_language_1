#include <iostream>
#include <thread>

void threadFunc()
{
	std::cout << "Thread " << std::endl;
}

int main()
{
	while(1)
	std::thread funcTest1(threadFunc);
}
#include <iostream>
#define CONG 0x0001//: cộng
#define TRU  0x0002//: trừ
#define NHAN 0x0004//: nhân
#define CHIA 0x0008//: chia
#define MAX  0x0010//: số lớn
#define MIN  0x0020//: số bé
using namespace std;

void Calculator(unsigned int MathType, float num1, float num2)
{
	if (MathType & CONG)
	{
		cout << num1 << " + " << num2 << " = " << num1+num2 << endl;
	}
	if (MathType & TRU)
	{
		cout << num1 << " - " << num2 << " = " << num1-num2 << endl;
	}
	if (MathType & NHAN)
	{
		cout << num1 << " * " << num2 << " = " << num1*num2 << endl;
	}
	if (MathType & CHIA)
	{
		cout << num1 << " / " << num2 << " = " << num1/num2 << endl;
	}
	if (MathType & MAX)
	{
		cout << "MAX(" << num1 << "," << num2 << ") = " << ((num1>num2)?num1:num2) << endl;
	}
	if (MathType & MIN)
	{
		cout << "MIN(" << num1 << "," << num2 << ") = " << ((num1<num2)?num1:num2) << endl;
	}
}

int main()
{
	Calculator(CONG|TRU|NHAN|CHIA, 1, 2);
	Calculator(MAX|MIN, 1, 2);
	system("pause");
	return 0;
}


#include<iostream>
#include<map>
#include"BrushlessMotorCtrl.h"

void test(int& a)
{
	a = 1;
}

int main()
{
	std::map<int, int> const LT{ {1,15},{5,78} };
	int c;
	test(c);
	BrushlessMotorCtrl controlmotors;

	//LT[1] = 3;
	//std::cout << "LT = " << LT[1] << std::endl;

	return 0;
}
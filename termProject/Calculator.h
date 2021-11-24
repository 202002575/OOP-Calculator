#pragma once
#include <string>
#include "Stack.h"
class Calculator {
private:
	const char* postfixArr[100];
	int resultNum = 0;
public:
	Calculator() {
		resultNum = 0;
	}
	int getResult();
	int strToInt(const char* str);
	void calculate(std::string& aPostfixStr);
	int operation(int a, int b, const char anOperator);
};
#pragma once
#include <string>
#include "Stack.h"
class Calculator {
private:
	int resultNum = 0;
	int strToInt(const char* str);
	int operation(int a, int b, const char anOperator);
public:
	Calculator() {
		resultNum = 0;
	}
	int getResult();
	void calculate(std::string& aPostfixStr);
};

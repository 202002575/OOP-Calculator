#define _CRT_SECURE_NO_WARNINGS 
#include<algorithm>
#include "Calculator.h"
#include "Stack.h"
 
int Calculator::getResult() {
	return this->resultNum;
}
int Calculator::strToInt(const char* str) {
	int num = 0;
	if (sizeof(str) >= 2 && str[0] == '0') {
		if (str[1] == 'x' || str[1] == 'X') {
			num = strtol(str, NULL, 16);
		}
		else if (str[1] == 'b' || str[1] == 'B') {
			num = strtol((char*)str + 2, NULL, 2);
		}
	}
	else {
		num = strtol(str, NULL, 10);
	}
	return num;
}
void Calculator::calculate(std::string& aPostfixStr) {
	char str_buff[100];
	Stack<int> stack = Stack<int>(100);
	strcpy(str_buff, aPostfixStr.c_str());
	char* tok = strtok(str_buff, " ");
	int index = 0;
	while (tok != NULL) {
		if ((tok[0] == '+') || (tok[0] == '-') ||
			(tok[0] == '*') || (tok[0] == '/')) {
			int anElement = stack.pop();
			int anotherEmement = stack.pop();
			stack.push(operation(anElement, anotherEmement, tok[0]));
		}
		else {
			int toPush = strToInt(tok);
			stack.push(toPush);	//피연산자 입력이 잘못되었을 경우, 오류 발생 가능
		}
		tok = strtok(NULL, " ");
	}
	this->resultNum = stack.pop();
}
int Calculator::operation(int a, int b, const char anOperator) {
	if (anOperator == '+') {
		return a + b;
	}
	if (anOperator == '-') {
		return b - a;
	}
	if (anOperator == '*') {
		return a * b;
	}
	if (anOperator == '/') {
		if (a == 0) {
			throw 2;
		}
		return b / a;
	}
	else {
		throw 0;
	}
}

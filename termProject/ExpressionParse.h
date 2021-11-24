#pragma once
#include<string>

class ExpressionParse {
private:
	ExpressionParse() {

	}
public:
	static bool compareOperators(char stackOperator, char newOperator);
	static bool infixToPostfix(std::string &infixStr);
};
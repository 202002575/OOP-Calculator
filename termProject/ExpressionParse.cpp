
#include<string>
#include "stack.h"
#include "expressionParse.h"
#include "AppView.cpp"
bool ExpressionParse::compareOperators(char stackOperator, char newOperator) {
	if (stackOperator == '(') {
		return false;
	}
	if ((newOperator == '+') || (newOperator) == '-') {
		return true;
	}
	else if ((stackOperator == '*') || (stackOperator == '/')) {
		return true;
	}
	else {
		return false;
	}
}
bool ExpressionParse::infixToPostfix(std::string &aString) {
	aString.erase(remove(aString.begin(), aString.end(), ' '), aString.end());
	std::string infixStr = '(' + aString + ')';
	std::string postfixStr = "";
	Stack<char> operatorStack(infixStr.size());
	for (int i = 0; i < infixStr.size(); i++) {
		bool lastIsOperator = false;
		if ((infixStr[i] == '(')) {//���� ��ȣ
			operatorStack.push(infixStr[i]);
		}
		else if ((infixStr[i] == '+') || (infixStr[i] == '-') ||
			(infixStr[i] == '*') || (infixStr[i] == '/')) {//������
			if ((i == 1) || (infixStr[i - 1] == '+') || (infixStr[i - 1] == '-') ||
				(infixStr[i - 1] == '*') || (infixStr[i - 1] == '/')) {
				throw 0;
			}
			postfixStr += ' ';
			if (!operatorStack.isEmpty() &&
					(ExpressionParse::compareOperators(operatorStack.peek(), infixStr[i]))) {
				//���ÿ� �ִ� �������� �켱������ �� ũ�ų� ������
				postfixStr += operatorStack.pop();
				postfixStr += ' ';
				lastIsOperator = true;
			}
			operatorStack.push(infixStr[i]);
		}
		else if (infixStr[i] == ')') {//�ݴ� ��ȣ
			while (operatorStack.peek() != '(') {
				if (operatorStack.getSize() == 0) {
					throw 0;
				}
				postfixStr += ' ';
				postfixStr += operatorStack.pop();
				lastIsOperator = true;
			}
			operatorStack.pop();
		}
		else if (infixStr[i] == ' ') {	//���� ���ֱ�
			continue;
		}
		else if ((infixStr[i] >= 48 && infixStr[i] <= 57) || (infixStr[i] == 46) ||
			((infixStr[i] >= 65 && infixStr[i] <= 90)) ||
			((infixStr[i] >= 97 && infixStr[i] <= 122))) {	//����, ����
			if (lastIsOperator) {
				postfixStr += ' ';
			}
			postfixStr += infixStr[i];
		}
		else {
			throw 0;
		}
	}
	if (operatorStack.getSize() > 0) {
		return false;
	}
	aString = postfixStr;
	return true;
}


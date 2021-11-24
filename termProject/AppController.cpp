#include<string>
#include "AppView.cpp"
#include "Stack.h"
#include "expressionParse.h"
#include "Calculator.h"
class AppController {
private:
	std::string expression;
	Calculator* calculator;
	bool doCalculate () {
		std::string aString = AppView::inputExpression();
		if (aString == "end") {
			return false;
		}
		this->expression = aString;
		try {
			ExpressionParse::infixToPostfix(expression);
			AppView::outputLine("// 후위 표기식: " + this->expression);
			calculator->calculate(this->expression);
		}
		catch(int e) {
			if (e == 0) {
				AppView::outputLine("[error] 수식이 잘못되었습니다.");
			}
			if (e == 1) {
				AppView::outputLine("[error] 스택 오류");
			}
			if (e == 2) {
				AppView::outputLine("[error] 0으로 나눌 수 없습니다.");
			}
			return true;
		}
		AppView::output("-> 연산 결과: ");
		AppView::output(std::to_string(calculator->getResult()));
	}
public:
	AppController() {
		calculator = new Calculator();
	}
	void run() {
		AppView::outputLine("** 계산기 실행 시작.");
		AppView::outputLine("* 종료하려면 \"end\"를 입력하시오.");
		AppView::outputLine("");
		while(1) {
			AppView::outputLine("! 수식을 입력하시오.");
			AppView::output(">> ");
			if (doCalculate() == false) {
				break;
			}
			AppView::outputLine("");
			AppView::outputLine("");
		}
		AppView::outputLine("");
		AppView::outputLine("** 계산기 실행 종료.");
	}
};
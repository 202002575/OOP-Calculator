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
			if (!ExpressionParse::infixToPostfix(expression)) {
				throw 0;
			}
			
			AppView::outputLine("// ���� ǥ���: " + this->expression);
			calculator->calculate(this->expression);
		}
		catch(int e) {
			if (e == 0) {
				AppView::outputLine("[error] ������ �߸��Ǿ����ϴ�.");
			}
			if (e == 1) {
				AppView::outputLine("[error] ���� ����");
			}
			if (e == 2) {
				AppView::outputLine("[error] 0���� ���� �� �����ϴ�.");
			}
			return true;
		}
		AppView::output("-> ���� ���: ");
		AppView::output(std::to_string(calculator->getResult()));
	}
public:
	AppController() {
		calculator = new Calculator();
	}
	void run() {
		AppView::outputLine("** ���� ���� ����.");
		AppView::outputLine("* �����Ϸ��� \"end\"�� �Է��Ͻÿ�.");
		AppView::outputLine("");
		while(1) {
			AppView::outputLine("! ������ �Է��Ͻÿ�.");
			AppView::output(">> ");
			if (doCalculate() == false) {
				break;
			}
			AppView::outputLine("");
			AppView::outputLine("");
		}
		AppView::outputLine("");
		AppView::outputLine("** ���� ���� ����.");
	}
};
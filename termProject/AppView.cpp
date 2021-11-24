#include<iostream>
#include<string>
class AppView {
public:
	static void outputLine(std::string aString) {
		std::cout << aString << std::endl;
	}
	static void output(std::string aString) {
		std::cout << aString;
	}
	static std::string inputExpression() {
		std::string anExpression;
		std::getline(std::cin, anExpression);
		return anExpression;
	}
};
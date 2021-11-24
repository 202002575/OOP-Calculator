#include<iostream>
#include "Stack.h"
#include "AppController.cpp"
int main() {
	Stack<char> stack(10);
    stack.push('a');
    stack.push('b');
    stack.push('c');
    stack.push('d');
    stack.push('e');
    stack.push('f');

    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;

    AppController* appController = new AppController();
    appController->run();

	return 0;
}
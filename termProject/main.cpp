#include<iostream>
#include "Stack.h"
#include "AppController.cpp"
int main() {
    AppController* appController = new AppController();
    appController->run();

	return 0;
}
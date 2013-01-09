//============================================================================
// Name        : Hello.cpp
// Author      : akin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <logic/logicengine.hpp>

#include "UI/uithread.hpp"

using namespace std;

int main() {

	logic::Engine engine;

	ui::Thread uilogic;

	engine.getScheduler().queue( uilogic );

	engine.run();

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

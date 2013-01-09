//============================================================================
// Name        : Hello.cpp
// Author      : akin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <loop.hpp>

#include "UI/uithread.hpp"

using namespace std;

int main() {

	Loop loop;

	ui::Thread uilogic;

	loop.getScheduler().queue( uilogic );

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

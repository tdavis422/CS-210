#pragma once
#include <iostream>//cout
//MenuOptions class to be used when the program 
//has started or user option has finished running its section
using namespace std;

inline void MenuOptions() {
	cout << "What would you like to do? " << endl;
	cout << "1: Specific Item" << endl;
	cout << "2: All Items" << endl;
	cout << "3: All Items (Histogram)" << endl;
	cout << "4: End Program" << endl;
}

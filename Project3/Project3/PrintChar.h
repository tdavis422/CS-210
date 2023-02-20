#pragma once
#include <iostream>//cout
//PrintChar class for Menu3 to correctly output histogram
using namespace std;

inline void PrintChar(int numTimes) {
	for (int i = 0; i < numTimes; i++) {
		cout << "*";
	}
	cout << endl;

}
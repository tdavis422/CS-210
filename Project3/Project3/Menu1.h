#pragma once
#include <iostream>//cout
#include <fstream>//ifstream, ofstream
#include <string>//string

using namespace std;

inline int Menu1() {
	//variable initialization
	int count = 0;
	string userWord;
	string listWord;
	ifstream produce;
	ofstream backup;

	//file opening
	produce.open("CS210_Project_Three_Input_File.txt");
	backup.open("frequency.dat");

	//determine if files opened correctly
	if (!produce.is_open()) {
		cout << "Could not open file";
		return 1;
	}
	if (!backup.is_open()) {
		cout << "Could not open file";
		return 1;
	}

	//print to output
	cout << "Which product are you looking for?" << endl;
	cin >> userWord; //user input

	while (!produce.fail()) {
		produce >> listWord;
		if (userWord == listWord) { //if item user is looking for is found
			count++;
		}
	}

	//print to file and to output
	backup << userWord << " " << count << endl;
	cout << userWord << " " << count << endl;

	//clear fail and close files
	produce.clear();
	produce.close();
	backup.close();
}
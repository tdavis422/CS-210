#pragma once
#include <iostream>//cout
#include <fstream>//ifstream, ofstream
#include <string>//string
#include <algorithm>//unique
#include <array>//array
#include <utility>//pair
#include <vector>//vector
#include <iterator> //for ip, distance
#include "PrintChar.h"

using namespace std;

inline int Menu3() {//FIXME
	//file opening
	ifstream produce;
	ofstream backup;
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

	//initialize variables
	int numLines = 0;
	vector<string> produceList;
	vector<string> produceVector;
	vector<pair <string, int>> produceSortVector;
	vector<string>::iterator ip;
	vector<pair<string, int>>::iterator ippair;
	string item;

	//insert contents of file into vectors
	for (int i = 0; getline(produce, item); i++) {
		produceVector.push_back(item);
		produceList.push_back(item);
		numLines++;
	}

	//sort, remove duplicates, and resize vector
	sort(produceVector.begin(), produceVector.end());
	ip = unique(produceVector.begin(), produceVector.end());
	produceVector.resize(distance(produceVector.begin(), ip));

	for (int k = 0; k < produceVector.size(); k++) {
		int count = 0; //initialization
		for (int l = 0; l < produceList.size(); l++) {
			if (produceVector[k] == produceList[l]) { //if item being looked for is found
				count++;
			}
		}
		//insert into vector
		produceSortVector.push_back(make_pair(produceVector[k], count));
	}

	//sort, remove duplicates, and resize vector
	sort(produceSortVector.begin(), produceSortVector.end());
	ippair = unique(produceSortVector.begin(), produceSortVector.end());
	produceSortVector.resize(distance(produceSortVector.begin(), ippair));

	//print to output and to backup file
	for (int y = 0; y < produceSortVector.size(); y++) {
		cout << produceSortVector[y].first << " ";
		PrintChar(produceSortVector[y].second);
		backup << produceSortVector[y].first << " ";
		for (int i = 0; i < produceSortVector[y].second; i++) {
			backup << "*";
		}
		backup << endl;
	}

	//close files when done
	produce.close();
	backup.close();
}
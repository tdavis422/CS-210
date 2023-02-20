#include <fstream>//ifstream, ofstream
#include <string>//string
#include <algorithm>//unique
#include <array>//array
#include <utility>//pair
#include <vector>//vector
#include <iterator> //for ip, distance

#include "MenuOptions.h" //MenuOptions function
#include "Menu1.h" //Menu1 function
#include "Menu2.h" //Menu2 function
#include "Menu3.h" //Menu3 function

using namespace std;

int main() {
	//variable initialization
	int userInput;
	//function call
	MenuOptions();
	//user input
	cin >> userInput;
	
	while (userInput != 4) {
		if (userInput == 1) {
			Menu1(); //function call
		}
		else if (userInput == 2) {
			Menu2(); //function call
		}
		else if (userInput == 3) {
			Menu3(); //function call
		}
		else {
			cout << "Invalid option" << endl; //print to output
		}
		MenuOptions(); //function call
		cin >> userInput; //user input
	}//end while

	return 0;
}
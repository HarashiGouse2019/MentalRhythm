//Include our user defined header file, as well as header files defined from C++
#include "ConsolePrint.h"
#include <iostream>
#include <string>

//Create some preprocessors
#define BREAK cout << "-----------------------------------------------------------------------------------------------------------" << endl;

//Declaring our constructor
ConsolePrint::ConsolePrint(void) {};

//Displays Text on the Console
std::string ConsolePrint::DisplayText(string text) {

	system("cls");

	std::string * ptrText = &text; //Create a pointer for our text

	std::cout << *ptrText << std::endl; //Print our parameter to the console

	return *ptrText; //Return our pointer

}

//Give us what this program is and how to use it
void ConsolePrint::GiveTutorial() {

	BREAK; //Create a line desu

	BREAK; //Create a line

	BREAK; //Create a line

	BREAK; //Create a line
}
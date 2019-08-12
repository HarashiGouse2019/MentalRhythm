//Include our user defined header file, as well as header files defined from C++
#include "ConsolePrint.h"
#include <iostream>
#include <string>

using namespace std;

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

//HelpPrint Constructor
HelpPrint::HelpPrint(void) {};

//Give us what this program is and how to use it
void HelpPrint::GiveTutorial() {
	std::cout << "Welcome to Mental Rhythm!!!" << "\n";
	std::cout << "You are going to be given a tone at a certain frequency." << "\n";
	std::cout << "As you match a frequency, you'll be given a long chain of frequencies." << "\n";
	std::cout << "Match as many frequencies as you can until you've completed a chain." << "\n";

	BREAK;

	std::cout << "CONTROLS: \n LEFT - C Note \n UP - D Note \n RIGHT - E Note \n DOWN - F Note \n SPACE - G Note \n";

	BREAK;

}
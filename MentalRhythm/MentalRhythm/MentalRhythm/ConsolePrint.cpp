//Include our user defined header file, as well as header files defined from C++
#include "ConsolePrint.h"
#include "FileManager.h"
#include <iostream>
#include <string>

using namespace std;

//Create some preprocessors
#define BREAK cout << "-----------------------------------------------------------------------------------------------------------" << endl;

//Declaring our constructor
ConsolePrint::ConsolePrint(void) {};

//Displays Text on the Console
std::string ConsolePrint::DisplayText(string text, bool clear, bool include_eol) {

	if (clear)
		system("cls");

	std::string * ptrText = &text; //Create a pointer for our text

	//Include an end of line or not
	if (include_eol)
		std::cout << *ptrText << std::endl; //Print our parameter to the console
	else
		std::cout << *ptrText;

	return *ptrText; //Return our pointer

}

//HelpPrint Constructor
HelpPrint::HelpPrint(void) {};

//Give us what this program is and how to use it
void HelpPrint::SimHelp() {
	std::cout << "Welcome to Mental Rhythm!!!" << "\n";
	std::cout << "You are going to be given a tone at a certain frequency." << "\n";
	std::cout << "As you match a frequency, you'll be given a long chain of frequencies." << "\n";
	std::cout << "Match as many frequencies as you can until you've completed a chain." << "\n";

	BREAK;

	std::cout << "CONTROLS: \n LEFT - C Note \n UP - D Note \n DOWN - E Note \n RIGHT- F Note \n SPACE - G Note \n";

	BREAK;

}

void HelpPrint::FileManagerHelp(int index) {
	switch (index) {
	case 0:
	{
		std::cout << "Welcome to the NoteStreak File Creation!!!" << "\n";
		std::cout << "You are able to create your own .mrb file using this menu.";

		BREAK;

		std::cout << "When using the NoteStreak File Creation, valid inputs include... \n";
		std::cout << "LEFT - C Note (Prints 1) \nUP - D Note (Prints 2) \nDOWN - E Note (Prints 3) \nRIGHT - F Note (Prints 4) \n SPACE - G Note (Prints 0) \n";

		BREAK;

		std::cout << "When finish recording your streak, hit ENTER to save it in the default directory.\n";
		std::cout << "Type in \"help\" to see avaliable commands.\n";

		BREAK;
		break;
	}
	case 1:
	{
		std::cout << "\n\nWhat you see below are valid commands:\n";

		BREAK;

		std::cout << "# - File Index\n\n";
		std::cout << "execute #\n";
		std::cout << "read #\n";
		std::cout << "rename #\n";
		std::cout << "delete #\n\n";

		BREAK;

		break;
	}
	}
};

//Menu Constructor
Menu::Menu(void) {};

//Pop the menu open
int Menu::ShowMenu() {
	std::cout << "Please select an option" << "\n";

	BREAK;

	std::cout << "1 - Play Random Note Streak" << "\n";

	std::cout << "2 - Select Note Streak" << "\n";

	std::cout << "3 - Create Note Streak" << "\n";

	std::cout << "99 - End Program" << "\n";

	BREAK;

	//Menu Functionality
	int inputVal;
	std::cin >> inputVal;
	return inputVal;
}

FileMenu::FileMenu(void) {};

std::string FileMenu::ShowMenu() {
	std::cout << "Type in a command, follow by a folder based on its index." << "\n";

	BREAK;

	//Menu Functionality
	std::string inputVal;
	std::cin >> inputVal;

	return inputVal;
}

Menu::~Menu() {
	system("CLS");
}
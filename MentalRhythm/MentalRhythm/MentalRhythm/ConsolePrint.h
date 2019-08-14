#pragma once

#ifndef CONSOLE_PRINT_H
#define CONSOLE_PRINT_H

#include <iostream> //Include iostream
#include <string> //Include string

using namespace std; //Using the standard library


class ConsolePrint //Creating our class called ConsolePrint
{
public:

	ConsolePrint(); //Our constructor
	string DisplayText(string text, bool clear = true, bool include_eol = true); //Our display text function

private:
	string name;
};

class HelpPrint : public ConsolePrint {
public:
	HelpPrint();
	void SimHelp(); //A function to give us during the Simulation
	void FileManagerHelp(int index = NULL); //A function to help with File Manager
};

class Menu : public ConsolePrint {
public:
	Menu();
	~Menu();
	int ShowMenu();
};

class FileMenu : public Menu {
public:
	FileMenu();
	std::string ShowMenu();
};


#endif

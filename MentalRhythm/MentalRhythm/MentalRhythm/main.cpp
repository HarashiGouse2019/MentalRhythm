/*Mental Rhythm  is an application that has the user guess a pattern on tones.
The user's goal is to complete the entire chain of notes without fail

Building the application will take some steps, including taking a string and parsing it into frequencies.
An iterator will be needed.

File IO will be used for anyone to create their own chain of notes.

The program will also have a vector to keep what file to access, as well as recent scores made.

We'll utilize the boost library for this project*/


//Include standard headers
#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <vector>
#include <algorithm>

//Include custom headers
#include "Sim.h"
#include "ConsolePrint.h"
#include "MyRandom.h"
#include "FileManager.h"

using namespace std;

int inputVal = NULL;

Menu * menu = new Menu();
HelpPrint * printInfo = new HelpPrint();

int main() {
	do {
		inputVal = menu->ShowMenu();
		switch (inputVal) {
		case 1:
		{
			delete menu;
			printInfo->GiveTutorial();

			Sim * simulation = Sim::Get();
			simulation->inputVal = inputVal;
			simulation->Start();
		}
			break;
		case 2:
		{
			delete menu;
			FileManager * fileManager = FileManager::Get();
			fileManager->Read();

			break;
		}
		}
	} while (inputVal != 99);
}
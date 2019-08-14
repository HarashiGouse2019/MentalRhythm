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
#include "NoteStreakFileCreation.h"

using namespace std;

int inputVal = NULL;
int& globalRef = inputVal;


HelpPrint * printInfo = new HelpPrint();
string fileString; //This is from reading a file

int main() {
	do {
		Menu * menu = new Menu();
		inputVal = menu->ShowMenu();
		switch (inputVal) {
		case 1:
		{
			delete menu;
			std::cout << "OK" << std::endl;

			printInfo->SimHelp();

			Sim * simulation = Sim::Get();
			simulation->inputVal = inputVal;
			simulation->Start();
			simulation->Delete();

			break;
		}
		case 2:
		{
			delete menu;

			int inputVal;

			FileManager * fileManager = FileManager::Get();
			FileMenu * menu = new FileMenu();

			int numFiles = fileManager->Read();

			if (numFiles > 0) inputVal = menu->ShowMenu();

			//Loop through
			for (int i = 0; i < fileManager->fileNames.size(); i++) {
				if (i == inputVal) {
					Sim * simulation = Sim::Get();
					simulation->inputVal = globalRef;
					simulation->patternReceiver = fileManager->Execute(fileManager->fileNames[i]);
					simulation->Start();
					simulation->Delete();
				}
			}
			fileManager->Delete();
			break;
		}
		case 3:
		{
			delete menu;
			
			NoteStreakFileCreation * nfsc = NoteStreakFileCreation::Get();

			nfsc->Record();
			nfsc->Delete();

			break;
		}
		}
	} while (inputVal != 99);
}
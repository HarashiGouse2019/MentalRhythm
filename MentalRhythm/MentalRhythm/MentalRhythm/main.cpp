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

			HelpPrint * helpPrint = new HelpPrint();

			helpPrint->SimHelp();

			Sim * simulation = Sim::Get();
			simulation->inputVal = inputVal;
			simulation->Start();
			simulation->Delete();

			delete helpPrint;

			break;
		}
		case 2:
		{
			delete menu;

			string fileIndex;

			string command;

			FileManager * fileManager = FileManager::Get();
			FileMenu * menu = new FileMenu();

			int numFiles = fileManager->Read();

			if (numFiles > 0)  SHOWMENU: command = menu->ShowMenu();

			std::size_t found;

			bool running = true;

			do {
				int commandInExecute = 0;

				if (commandInExecute < 1) {
					//Check if numFiles is actually above zero. If not, running is automatically set to false
					if (numFiles < 1) {
						running = false;
						fileManager->Delete();
						delete menu;
					}
					else {

						//Well look at command and find a certain keyword (there's 4 commands)
						found = command.find("execute");
						if (found != std::string::npos) {
							//We increment commandInExecute
							commandInExecute++;

							//We clear out the whole screen
							system("CLS");

							//Now we look for the number that we what to execute, and assign it to fileIndex
							std::string extractor;
							std::getline(std::cin, extractor, ' '); //By doing this, we allow ourselves to access the fileIndex
							std::getline(std::cin, fileIndex); //We read from the new line, and we assign the number to fileIndex

							//fileIndex is curretly a string. We just need to convert it to an integer, and place an integer value;
							int fID = stoi(fileIndex);

							//Loop through
							for (int i = 0; i < fileManager->fileNames.size(); i++) {
								if (i == fID) {
									Sim * simulation = Sim::Get();
									simulation->inputVal = globalRef;
									simulation->patternReceiver = fileManager->Execute(fileManager->fileNames[i]);
									simulation->Start();
									simulation->Delete();
								}
							}
							fileManager->Delete();
							delete menu;
							running = false;
							break;
						}

						//Now we find a delete command
						found = command.find("delete");
						if (found != std::string::npos) {
							//We increment commandInExecute
							commandInExecute++;

							//Clear out screen
							system("CLS");

							//Do the same method as command execute
							std::string extractor;
							std::getline(std::cin, extractor, ' ');
							std::getline(std::cin, fileIndex);

							//Turn fileIndex to a string and assign it to fID
							int fID = stoi(fileIndex);

							//Loop through
							for (int i = 0; i < fileManager->fileNames.size(); i++) {
								if (i == fID) {
									fileManager->Trash(fileManager->fileNames[i]);
								}
							}

							//We actually will return to the main menu, so...
							fileManager->Delete();
							delete menu;
							running = false;
							break;
						}

						//Now we find a help command
						found = command.find("help");
						if (found != std::string::npos) {
							//We increment commandInExecute
							commandInExecute++;

							HelpPrint * helpPrint = new HelpPrint();
							helpPrint->FileManagerHelp(1);
							delete helpPrint;
							goto SHOWMENU;
						}

						//Now we find an end command
						found = command.find("end");
						if (found != std::string::npos) {
							//We increment commandInExecute
							commandInExecute++;

							system("CLS");
							fileManager->Delete();
							delete menu;
							running = false;
							break;
						}

						std::cerr << "\"" << command << "\" is not an existing command.\n"; command = "";  goto SHOWMENU;
					}
				}
			} while (running);
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
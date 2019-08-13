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
#include "MyRandom.h"

//Include custom headers
#include "Sim.h"
#include "ConsolePrint.h"

//Include Booost Library Headers
#include <boost/filesystem.hpp>

using namespace std;

int inputVal = NULL;

Menu * menu;
HelpPrint * printInfo;

int main() {

	/*Notes to leave whenever I come back from work::

		First of all, make sure you turn in your multithread work before anything else.

		After that, prioritize the final project for C++ (because I believe that will be a lot more easier than Unity since you're strictly doing coding)

			First, we need a menu!
			Implement a design pattern(singleton will be the easiest) - Complete!!!
			Include exception handling of some sort

			These are just the really notiable stuff that we need*/

	inputVal = menu->ShowMenu();
	do {
		switch (inputVal) {
		case 1:
			printInfo->GiveTutorial();

			Sim * simulation = Sim::Get();
			simulation->inputVal = inputVal;
			simulation->Start();
			break;
		//case 2:
		//	break;
		//case 3:
		//	break;
		//case 99:
		//	break;
		}
	} while (inputVal != 99);

	
}
#include <boost/foreach.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>


#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <thread>
#include <atomic>
#include <mutex>
#include <exception>

#include "Sim.h"
#include "ConsolePrint.h"
#include "MyRandom.h"

using namespace std;

//Preprocessor Tokens
#define SLEEP SleepEx(100, false)

#define WAIT system("pause")

#define KEY_UP 72

#define KEY_DOWN 80

#define KEY_LEFT 75 

#define KEY_RIGHT 77

#define SPACE 32

#define C5 Beep((DWORD)523.2511, (DWORD)100)

#define D5 Beep((DWORD)587.3295, (DWORD)100)

#define E5 Beep((DWORD)659.2551, (DWORD)100)

#define F5 Beep((DWORD)698.4565, (DWORD)100)

#define G5 Beep((DWORD)783.9909, (DWORD)100)

std::atomic<Sim*> Sim::pinstance{ nullptr };
std::mutex Sim::m_;

//Exception here
struct InputException : public exception{
	const char * what() const throw() {
		return "Incorrect Input!";
	}
};

Sim* Sim::Get() {
	//Singleton
	if (pinstance == nullptr) {
		lock_guard<mutex> lock(m_);
		if (pinstance == nullptr) {
			pinstance = new Sim();
		}
	}
	return pinstance;
}

Sim * Sim::Delete() {
	delete pinstance;
	pinstance = nullptr;
	return pinstance;
}

void Sim::Start() {

	bool gameOn = true;

	bool usersTurn = false;

	int currentNoteChain = 0;

	ConsolePrint * con = new ConsolePrint();

	std::string pattern = "";
	std::string streak = "";

	if (inputVal == 1) pattern = Generate(); //We'll have the Simulation generate a number if we haven't choose a noteStreak File
	if (inputVal == 2) pattern = patternReceiver;

	streak = pattern[currentNoteChain];

	do {
		switch (usersTurn) {
		case false:
			if (streak.size() == pattern.size()) gameOn = false; else {
				BOOST_FOREACH(char ch, streak) {
					switch (ch) {
					case '0': {G5; SLEEP; break; }
					case '1': {C5; SLEEP; break; }
					case '2': {D5; SLEEP; break; }
					case '3': {E5; SLEEP; break; }
					case '4': {F5; SLEEP; break; }
					case '<': usersTurn = true; break;
					default: break;
					}
					if (streak.size() == currentNoteChain + 1) {
						usersTurn = true;
					}
				}
			}
			break;
		case true:
			int c = 0; //Initialize c to toggle from 0 to 1 when we send input
			while (1) {
				try {
					switch ((c = _getch())) {
					case 72:
					{
						D5;
						noteStreak += '2';
						con->DisplayText(noteStreak);
						if (noteStreak.size() == streak.size()) {
							if (MatchingStreak(noteStreak, streak)) {
								noteStreak = "";
								usersTurn = false;
								currentNoteChain++;
								streak += pattern[currentNoteChain];
							}
							else gameOn = false;
						}

						break;

					}
					case 80:
					{
						E5;
						noteStreak += '3';
						con->DisplayText(noteStreak);
						if (noteStreak.size() == streak.size()) {
							if (MatchingStreak(noteStreak, streak)) {
								noteStreak = "";
								usersTurn = false;
								currentNoteChain++;
								streak += pattern[currentNoteChain];
							}
							else gameOn = false;
						}

						break;
					}
					case 75:
					{
						C5;
						noteStreak += '1';
						con->DisplayText(noteStreak);
						if (noteStreak.size() == streak.size()) {
							if (MatchingStreak(noteStreak, streak)) {
								noteStreak = "";
								usersTurn = false;
								currentNoteChain++;
								streak += pattern[currentNoteChain];
							}
							else gameOn = false;
						}

						break;
					}
					case 77:
					{
						F5;
						noteStreak += '4';
						con->DisplayText(noteStreak);
						if (noteStreak.size() == streak.size()) {
							if (MatchingStreak(noteStreak, streak)) {
								noteStreak = "";
								usersTurn = false;
								currentNoteChain++;
								streak += pattern[currentNoteChain];
							}
							else gameOn = false;
						}

						break;
					}
					case 32:
					{
						G5;
						noteStreak += '0';
						con->DisplayText(noteStreak);
						if (noteStreak.size() == streak.size()) {
							if (MatchingStreak(noteStreak, streak)) {
								noteStreak = "";
								usersTurn = false;
								currentNoteChain++;
								streak += pattern[currentNoteChain];
							}
							else gameOn = false;
						}

						break;
					}
					default:
						throw InputException();
						break;
					}
				}
				catch (InputException& ie) {
					std::cerr << ie.what();
				}
				catch (std::exception& e) {
					std::cerr << "System Defined Exception: \"" << e.what() << "\"";
				}
				break;
			}
		}
	} while (gameOn);

	//Check if the player did match the entire pattern before the game ended!
	if (streak.size() == pattern.size()) {
		std::cout << "\nYou completed the entire pattern!!!\nYour score: " << (currentNoteChain) << "\n"; WAIT;
	}
	else {
		std::cout << "\nTry again:\nYour score: " << (currentNoteChain) << "\n"; WAIT;
	}
	streak = "";

	delete pinstance;
 }

bool Sim::MatchingStreak(std::string a, std::string b) {
	ConsolePrint * con = new ConsolePrint();
	if (a == b) {
		con->DisplayText("Good");
		return true;
	}
	else {
		con->DisplayText("Nope");
		return false;
	}
	return false;
}

string Sim::Generate() {
	string generatedString = "";

	//Generate a number between 10 and 20
	Random noteLength;
	int val1 = noteLength.GetNumberRange(10, 20);

	//Do a for loop, and generate a number between 0 and 4
	for (int i = 0; i < val1; i++) {
		Random notes;
		int val2 = notes.GetNumberRange(0, 4);

		generatedString += std::to_string(val2);
	}

	generatedString += '<';

	return generatedString; //Return the generated string
}

Sim::~Sim() {system("CLS"); std::cout << "End of Simulation. "; pinstance = NULL; }
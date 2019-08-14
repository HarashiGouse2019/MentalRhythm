#include <boost/foreach.hpp>

#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <thread>
#include <atomic>
#include <mutex>
#include <exception>

#include "NoteStreakFileCreation.h"
#include "ConsolePrint.h"
#include "FileManager.h"

using namespace std;

//Preprocessor Tokens
#define SLEEP SleepEx(100, false)

#define WAIT system("pause")

#define KEY_UP 72

#define KEY_DOWN 80

#define KEY_LEFT 75 

#define KEY_RIGHT 77

#define SPACE 32

#define ENTER 13

#define C5 Beep((DWORD)523.2511, (DWORD)100)

#define D5 Beep((DWORD)587.3295, (DWORD)100)

#define E5 Beep((DWORD)659.2551, (DWORD)100)

#define F5 Beep((DWORD)698.4565, (DWORD)100)

#define G5 Beep((DWORD)783.9909, (DWORD)100)

std::atomic<NoteStreakFileCreation*> NoteStreakFileCreation::pinstance{ nullptr };
std::mutex NoteStreakFileCreation::m_;

//Exception here
struct InputException : public exception {
	const char * what() const throw() {
		return "Incorrect Input!";
	}
};

NoteStreakFileCreation * NoteStreakFileCreation::Get() {
	//Singleton
	if (pinstance == nullptr) {
		lock_guard<mutex> lock(m_);
		if (pinstance == nullptr) {
			pinstance = new NoteStreakFileCreation();
		}
	}
	return pinstance;
}

NoteStreakFileCreation * NoteStreakFileCreation::Delete() {
	delete pinstance;
	pinstance = nullptr;
	return pinstance;
}

std::string NoteStreakFileCreation::Record() {
	ConsolePrint con;
	do {
		int c = 0; //Initialize c to toggle from 0 to 1 when we send input
		while (1) {
			switch ((c = _getch())) {
			case KEY_UP:
				D5;
				noteStreak += '2';
				con.DisplayText("2", false, false);
				break;
			case KEY_DOWN:
				E5;
				noteStreak += '3';
				con.DisplayText("3", false, false);
				break;
			case KEY_LEFT:
				C5;
				noteStreak += '1';
				con.DisplayText("1", false, false);
				break;
			case KEY_RIGHT:
				F5;
				noteStreak += '4';
				con.DisplayText("4", false, false);
				break;
			case SPACE:
				G5;
				noteStreak += '0';
				con.DisplayText("0", false, false);
				break;
			case ENTER:
				noteStreak += '<';
				con.DisplayText("<", false, false);
				isRecording = false;
				this->Save(noteStreak);
				break;
			}
			break;
		}
	} while (isRecording);
	return noteStreak;
}

void NoteStreakFileCreation::Save(string streakPattern) {
	FileManager * fileManager = FileManager::Get();
	std::string name;
	std::cout << "What would you like to call this NoteStreak?: ";
	std::cin >> name;
	fileManager->Write(name, streakPattern);
	fileManager->Delete();
}


NoteStreakFileCreation::~NoteStreakFileCreation() { system("CLS"); std::cout << "Exiting Note Streak File Creation. ";}
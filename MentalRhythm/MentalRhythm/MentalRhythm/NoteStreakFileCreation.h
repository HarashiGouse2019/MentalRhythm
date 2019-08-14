#pragma once

#ifndef NOTE_STREAK_FILE_CREATION_H
#define SIM_H

#include <iostream>
#include <string>
#include <future>
#include <atomic>
#include <mutex>

#include "ConsolePrint.h"

using namespace std;

class NoteStreakFileCreation {
public:
	~NoteStreakFileCreation();
	std::string Record();
	void Save(string streakPattern);
	static NoteStreakFileCreation* Get(); //Singleton
	static NoteStreakFileCreation* Delete();

private:
	//Singleton
	NoteStreakFileCreation() { init(); }
	void init() {
		HelpPrint helpPrint;
		helpPrint.FileManagerHelp();
	}
	static atomic<NoteStreakFileCreation*> pinstance;
	static mutex m_;

	//The amount of notes you have to play
	std::string noteStreak;

	//Check if user is recording
	bool isRecording;
};

#endif

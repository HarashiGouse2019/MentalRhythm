#pragma once

#ifndef SIM_H
#define SIM_H

#include <iostream>
#include <string>
#include <future>
#include <atomic>
#include <mutex>

using namespace std;

class Sim {
public:
	~Sim();
	void Start();
	bool MatchingStreak(std::string a, std::string b);
	string Generate(); //Generate between a 10 to 20 character string with numbers 0, 1, 2, 3, and 4
	static Sim* Get(); //Singleton
	static Sim* Delete();

	int inputVal;
	std::string patternReceiver;

private:
	//Singleton
	Sim() { init(); }
	void init() {
		std::cout << "Simulation has initiated" << std::endl;
	}
	static atomic<Sim*> pinstance;
	static mutex m_;

	//The amount of notes you have to play
	std::string noteStreak;
};

#endif
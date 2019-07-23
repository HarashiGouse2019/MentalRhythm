#pragma once

#include <string>

class Sim {
public:
	Sim();
	void Start();
	bool MatchingStreak(std::string a, std::string b);
private:
	std::string noteStreak;
};
#pragma once

#include <string>
#include <future>

class Sim {
public:
	static Sim& getInstance() {
		std::call_once(initInstanceFlag, &Sim::initSingleton);
		return *instance;
	}
	static void Start();
	static bool MatchingStreak(std::string a, std::string b);
private:
	Sim() = default;
	~Sim() = default;
	Sim(const Sim&) = delete;
	Sim& operator=(const Sim&) = delete;

	static Sim* instance;
	static std::once_flag initInstanceFlag;

	static void initSingleton() {
		instance = new Sim();
	}

	static std::string noteStreak;
};
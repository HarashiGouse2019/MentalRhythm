#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

#include <iostream>
#include <string>
#include <ctime>

#include "MyRandom.h"

using namespace std;

Random::Random(void) {};

int Random::GetNumberRange(int a, int b) {
	static boost::random::mt19937 gen(static_cast<unsigned int>(std::time(0)));
	boost::random::uniform_int_distribution<int> dist(a, b);
	return dist(gen);
}
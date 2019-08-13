#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

#include <iostream>
#include <string>

#include "MyRandom.h"

using namespace std;

Random::Random(void) {};

int Random::GetNumberRange(int a, int b) {
	boost::random::mt19937 gen;
	boost::random::uniform_int_distribution<> dist(a, b);

	return dist(gen);
}
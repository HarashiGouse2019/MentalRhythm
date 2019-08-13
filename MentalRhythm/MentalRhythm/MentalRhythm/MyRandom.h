#pragma once

#ifndef MY_RANDOM_H
#define MY_RANDOM_H

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

class Random {
public:
	Random();
	int GetNumberRange(int a, int b);
};

#endif
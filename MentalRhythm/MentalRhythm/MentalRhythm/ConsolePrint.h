#pragma once
#include <iostream> //Include iostream
#include <string> //Include string

using namespace std; //Using the standard library

class ConsolePrint //Creating our class called ConsolePrint
{
public:
	ConsolePrint(); //Our constructor
	string DisplayText(string text); //Our display text function
	void GiveTutorial(); //A function to give us an tutorial
private:
	string name;
};



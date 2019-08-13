#pragma once

#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <iostream>
#include <boost/filesystem.hpp>

#include <atomic>
#include <future>
#include <mutex>

#include "ConsolePrint.h"

using namespace std;
using namespace boost::filesystem;

class FileManager {
public:
	void Read(); //Read from a file
	void Write(); //Write to a file

	//The FileManager will just do those two basic functionalities

	static FileManager* Get(); //Singleton

private:
	FileManager() { std::cout << "Running FileManager..." << std::endl; init(); }
	void init() {
		std::cout << "FileManager  Ready!!!" << std::endl;
	}
	static atomic<FileManager*> pinstance;
	static mutex m_;

};

class FileMenu : public FileManager, public Menu {
public:
	int ShowMenu();
};

#endif
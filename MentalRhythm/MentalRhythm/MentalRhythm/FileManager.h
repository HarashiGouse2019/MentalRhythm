#pragma once

#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <iostream>
#include <boost/filesystem.hpp>

#include <atomic>
#include <future>
#include <mutex>
#include <vector>
#include <algorithm>


#include "ConsolePrint.h"

using namespace std;
using namespace boost::filesystem;

class FileManager {
public:
	int Read(); //Read from a file
	void Write(string filename, string content); //Write to a file
	void Trash(string filename); //Delete a file

	static string Execute(string filename); //Execute a file

	//The FileManager will just do those two basic functionalities

	static FileManager* Get(); //Singleton
	static FileManager* Delete();

	vector<std::string> fileNames;

private:
	FileManager() { std::cout << "\nRunning FileManager...\n" << std::endl; init(); }
	void init() {
		std::cout << "\nFileManager Ready!!!\n" << std::endl;
	}
	static atomic<FileManager*> pinstance;
	static mutex m_;
};
#endif
#include <iostream>

#include <mutex>
#include <atomic>
#include "FileManager.h"
#include "ConsolePrint.h"

using namespace std;

//Create some preprocessors
#define BREAK cout << "-----------------------------------------------------------------------------------------------------------" << endl;

ConsolePrint con;

std::atomic<FileManager*> FileManager::pinstance{ nullptr };
std::mutex FileManager::m_;

FileManager * FileManager::Get() {
	if (pinstance == nullptr) {
		lock_guard<mutex> lock(m_);
		if (pinstance == nullptr) {
			pinstance = new FileManager();
		}
	}
	return pinstance;
}

void FileManager::Read() {
	int index = 0;

	con.DisplayText("Reading...\n");

	boost::filesystem::path p(".");

	boost::filesystem::directory_iterator end_itr;

	//cycle through the directory
	for (boost::filesystem::directory_iterator itr(p); itr != end_itr; ++itr) {
		if (boost::filesystem::is_regular_file(itr->path())) {
			//Assign current file name to current_file and echo it out ot the console
			std::string current_file = std::to_string(index) + itr->path().string();
			std::cout << current_file << std::endl;
			index++;
		}
	}
}

//void FileManager::Write() {
//	return NULL;
//}
int FileMenu::ShowMenu() {
	std::cout << "Input a value to open a file. (Must be of extension .mrb)" << "/n";

	BREAK;

	//Menu Functionality
	int inputVal;
	std::cin >> inputVal;
	return inputVal;
}
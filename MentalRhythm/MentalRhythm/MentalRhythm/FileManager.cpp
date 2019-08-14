#include <boost/spirit/include/support_istream_iterator.hpp>
#include <iostream>

#include <mutex>
#include <atomic>
#include "FileManager.h"
#include "ConsolePrint.h"
#include "Sim.h"
#include "NoteStreakFileCreation.h"

using namespace std;

//Create some preprocessors
#define BREAK cout << "-----------------------------------------------------------------------------------------------------------" << endl;

ConsolePrint con;
HelpPrint helpPrint;

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

FileManager * FileManager::Delete() {
	delete pinstance;
	pinstance = NULL;
	return pinstance;
}

int FileManager::Read() {
	int index = 0;

	con.DisplayText("Reading...\n\n", false, false);

	boost::filesystem::path p(".");

	boost::filesystem::directory_iterator end_itr;

	BREAK;

	//cycle through the directory
	for (boost::filesystem::directory_iterator itr(p); itr != end_itr; ++itr) {
		if (boost::filesystem::is_regular_file(itr->path()) && boost::filesystem::extension(itr->path()) == ".mrb") {
			//Assign current file name to current_file and echo it out ot the console
			fileNames.push_back(itr->path().string());
			std::string current_file = std::to_string(index) + " ----- " + itr->path().string();
			std::cout << current_file << std::endl;
			index++;
		}
	}

	BREAK;

	std::cout << "\nDONE!\n\n";

	//If the program could not find any .mrb files
	if (index < 1) {
		con.DisplayText("There were no .mrb files. \nYou should create your own .mrb\neither manually or via Main Menu (option 3)\n", false);
		system("pause"); system("CLS");
		return NULL;
	}
	
	return index;
}

void FileManager::Write(string filename, string content) {

	boost::filesystem::ofstream save;

	//Open our file. If it doesn't exist, create one!
	save.open(filename + ".mrb", ios::out | ios::binary);

	//Iterate and put each individual text into the file;
	if (save) {
		std::cout << "Saving... \n";
		save << content;
	}

	//Close the file
	save.close();
};

void FileManager::Trash(string filename) {
	std::cout << "\nErasing...\n";

	//Delete the file
	boost::filesystem::remove(filename);

	std::cout << "\nDONE!!!\n";
}

void FileManager::Rename(string filename) {
	string name;

	std::cout << "\nRename this file as: ";

	std::getline(std::cin, name);

	//Rename our file
	std::cout << "Overriding...\n";
	boost::filesystem::rename(filename, name + ".mrb");
	std::cout << "\n\nDONE!!!\n";
	
}


std::string FileManager::Execute(string filename) {
	std::string content;
	std::string line;

	std::cout << "\nExecuting..." << filename << std::endl;

	boost::filesystem::ifstream exec;

	//We open the selected file
	exec.open(filename, ios::in | ios::binary);

	//We want to iterate through the content.
	//We'll get getting a string for this, and we want to return
	//it for the simulation
	if (exec) {
		for (content; getline(exec, line);) {
			content += line;
		}
	}
	else {
		std::cerr << "Couldn't Open " << filename << "\n";
	}
	
	//And now that we got the information we need, we close the file.
	exec.close();

	std::cout << "\nDONE!!!\n" << std::endl;

	return content;
}

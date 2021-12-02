/*
Created by: Eli Madi
For: CSC28500 Team Project 02
Submitted: 2021 December 01
Instructor: Dr. Jeevanjee
*/

#include "head.hpp"
using namespace std;

//"prompt" prompts the user for a filename and returns it if that file exists
string prompt() {

	//File stream initializations
	string filename;

	cout << "Please enter the name of the file you woud like to solve: ";
	cin >> filename;

	ifstream file(filename);

	//Check if the file exists
	if (!file.good()) {
		//If file name is invalid, print error message and prompt the user again
		cout << "File not found!" << endl << endl;
		return prompt();
	}

	//If the file name is valid, return the filename
	return filename;
}

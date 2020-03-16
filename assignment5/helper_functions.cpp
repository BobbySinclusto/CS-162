/***************************************************************************
** File: helper_functions.cpp
** Author: Allen Benjamin
** Date: 02/16/2020
** Description: Some helpful functions that I used in several classes
**************************************************************************/

#include "helper_functions.h"
#include <iostream>
#include <string>

using namespace std;

unsigned int get_unsigned_int(string prompt) {
	string input;
	while (true) {
		cout << prompt;
		try {
			getline(cin, input);
			if (input.find_first_not_of("0123456789") != string::npos) throw 0;
			return stoul(input);
		}
		catch (...) {
			cout << "Invalid input." << endl;
		}
	}
}

int get_int(string prompt) {
	string input;
	while (true) {
		cout << prompt;
		try {
			getline(cin, input);
			if (input.find_first_not_of("0123456789") != string::npos && input.length() != 0 && input.at(0) != '-') throw 0;
			return stoi(input);
		}
		catch (...) {
			cout << "Invalid input." << endl;
		}
	}
}

bool get_input_dichotomy(string prompt, char t, char f) {
	string input;
	while (true) {
		cout << prompt;
		getline(cin, input);
		if (input.length() == 1 && input.at(0) == t) {
			return true;
		}
		else if (input.length() == 1 && input.at(0) == f) {
			return false;
		}
		cout << "Invalid input." << endl;
	}
}
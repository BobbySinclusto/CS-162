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

int get_input_range(string prompt, int min, int max) {
	int num = min - 1;
	string input;
	while (true) {
		while (true) {
			cout << prompt;
			getline(cin, input);
			if (input == "" || input.find_first_not_of("0123456789") != string::npos) {
				cout << "Invalid input." << endl;
			}
			else {
				break;
			}
		}
		num = stoi(input);
		if (num < min || num > max) {
			cout << "Invalid input." << endl;
		}
		else {
			return num;
		}
	}
}
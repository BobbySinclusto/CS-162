/******************************************************
** Program: prog.cpp
** Author: Allen Benjamin
** Date: 02/29/2020
** Description: Plays a Hunt the Wumpus game
** Input: User input for choices
** Output: Game progress
******************************************************/

#include "Game.h"
#include "helper_functions.h"
#include "colors.h"
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

void validate_arguments(int, char **, int &, bool &);

/********************************************************
** Function: main()
** Description: validates arguments and starts a game
** Input: command line arguments
** Pre-Conditions: none
** Post-Conditions: game starts
********************************************************/
int main(int argc, char **argv) {
	srand(time(NULL));
	int s;
	bool dbg;
	validate_arguments(argc, argv, s, dbg);
	Game g(s, dbg);
	cout << CLEAR;
	for (int i = 0; i < 50; ++i) cout << "\n";
	g.play();

	return 0;
}

/********************************************************
** Function: validate_arguments()
** Description: validates command line arguments
** Input: command line arguments, size and dbg
** Pre-Conditions: none
** Post-Conditions: arguments are validated
********************************************************/
void validate_arguments(int argc, char **argv, int &s, bool &dbg) {
	if (argc != 3) {
		cout << "Incorrect number of command line arguments" << endl;
		s = get_input_range("Enter the size of the grid (between 4 and 50): ", 4, 50);
		dbg = get_input_range("Run in debug mode? (1-yes, 0-no): ", 0, 1);
	}
	else {
		if (atoi(argv[1]) < 4) {
			cout << "Invalid argument for size of board" << endl;
			s = get_input_range("Enter the size of the grid (between 4 and 50): ", 4, 50);
		}
		else {
			s = atoi(argv[1]);
		}

		if (strcmp(argv[2], "true") == 0) {
			dbg = true;
		}
		else if (strcmp(argv[2], "false") == 0) {
			dbg = false;
		}
		else {
			cout << "Invalid argument for debug mode" << endl;
			dbg = get_input_range("Run in debug mode? (1-yes, 0-no): ", 0, 1);
		}
	}
}
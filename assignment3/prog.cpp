/******************************************************
** Program: prog.cpp
** Author: Allen Benjamin
** Date: 02/17/2020
** Description: Plays a zoo tycoon game
** Input: User input for choices
** Output: Game progress
******************************************************/

#include "Animal.h"
#include "Bear.h"
#include "SeaLion.h"
#include "Tiger.h"
#include "Zoo.h"
#include "helper_functions.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	srand(time(NULL));

	do {
		Zoo z;
		cout << "\u001b[2J\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; // start at bottom of the screen
		z.play();
	} while (get_input_range("Play again? 1-yes, 0-no: ", 0, 1));
	
	return 0;
}
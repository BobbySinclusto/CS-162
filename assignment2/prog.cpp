/***************************************************************************
** File: prog.cpp
** Author: Allen Benjamin
** Date: 01/28/2020
** Description: Plays a game of crazy_eights
** Inputs: choices from user
** Output: progress of the game
**************************************************************************/

#include "Game.h"
#include "helper_functions.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	srand(time(NULL));
	do {
		Game g;
		g.play();
	} while (get_input_range("Would you like to play again? (1-yes, 0-no): ", 0, 1));
	return 0;
}
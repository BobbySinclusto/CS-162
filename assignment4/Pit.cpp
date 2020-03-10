/***************************************************************************
** File: Pit.cpp
** Author: Allen Benjamin
** Date: 02/29/2020
** Description: Represents a Pit
**************************************************************************/

#include "Pit.h"
#include "Game.h"
#include "colors.h"
#include <iostream>

using namespace std;

Pit::Pit(int r, int c) {
	row = r;
	col = c;
}

void Pit::percept() {
	cout << YELLOW << "You feel a breeze." << RESET << endl;
}

bool Pit::encounter(Game &g) {
	cout << RED << "You fell into a bottomless pit." << RESET << endl;
	return true;
}

char Pit::abbreviation() {
	return 'P';
}
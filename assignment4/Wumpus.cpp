/***************************************************************************
** File: Wumpus.cpp
** Author: Allen Benjamin
** Date: 02/29/2020
** Description: Represents a Wumpus
**************************************************************************/

#include "Wumpus.h"
#include "Game.h"
#include "colors.h"
#include <iostream>

using namespace std;

Wumpus::Wumpus(int r, int c) {
	row = r;
	col = c;
}

void Wumpus::percept() {
	cout << YELLOW << "You smell a terrible stench." << RESET << endl;
}

bool Wumpus::encounter(Game &g) {
	cout << RED << "You were eaten by the Wumpus." << RESET << endl;
	return true;
}

char Wumpus::abbreviation() {
	return 'W';
}
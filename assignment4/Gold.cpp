/***************************************************************************
** File: Gold.cpp
** Author: Allen Benjamin
** Date: 02/29/2020
** Description: Represents a Gold
**************************************************************************/

#include "Gold.h"
#include "Game.h"
#include "colors.h"
#include <iostream>

using namespace std;

Gold::Gold(int r, int c) {
	row = r;
	col = c;
}

void Gold::percept() {
	cout << YELLOW << "You see a glimmer nearby." << RESET << endl;
}

bool Gold::encounter(Game &g) {
	cout << GREEN << "Got the gold!!" << RESET << endl;
	g.get_gold();
	return false;
}

char Gold::abbreviation() {
	return 'G';
}
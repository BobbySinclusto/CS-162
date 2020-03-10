/***************************************************************************
** File: Bat.cpp
** Author: Allen Benjamin
** Date: 02/29/2020
** Description: Represents a Bat
**************************************************************************/

#include "Bat.h"
#include "Game.h"
#include "colors.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Bat::Bat(int r, int c) {
	row = r;
	col = c;
}

void Bat::percept() {
	cout << YELLOW << "You hear wings flapping." << RESET << endl;
}

bool Bat::encounter(Game &g) {
	cout << BLUE << "A super bat carried you away!" << RESET << endl;
	int r = rand() % g.get_size();
	int c = rand() % g.get_size();
	g.move_player(r, c);
	if (g.get_cave()[r][c].has_event()) {
		return g.get_cave()[r][c].get_event()->encounter(g);
	}
	return false;
}

char Bat::abbreviation() {
	return 'B';
}
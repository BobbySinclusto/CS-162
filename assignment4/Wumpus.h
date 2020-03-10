/***************************************************************************
** File: Wumpus.h
** Author: Allen Benjamin
** Date: 02/29/2020
** Description: Represents a Wumpus
**************************************************************************/

#ifndef WUMPUS_H
#define WUMPUS_H

#include "Event.h"

class Wumpus: public Event {
public:
/********************************************************
** Function: Wumpus constructor
** Description: initializes row and column
** Input: row and column
** Pre-Conditions: none
** Post-Conditions: row and column are initialized
********************************************************/
	Wumpus(int r = 0, int c = 0);

/********************************************************
** Function: Wumpus destructor
** Description: removes the annoying warning
** Input: none
** Pre-Conditions: none
** Post-Conditions: none
********************************************************/
	~Wumpus() {}

/********************************************************
** Function: percept()
** Description: displays a message indicating the Wumpus is nearby
** Input: none
** Pre-Conditions: none
** Post-Conditions: message is displayed
********************************************************/
	void percept() override;

/********************************************************
** Function: encounter()
** Description: prints game over message, kills the player
** Input: reference to the game object
** Pre-Conditions: none
** Post-Conditions: returns true
********************************************************/
	bool encounter(Game &) override;

/********************************************************
** Function: abbreviation()
** Description: returns the abbreviation to show in the map for this event
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns the abbreviation to show in the map for this event
********************************************************/
	char abbreviation() override;

};

#endif
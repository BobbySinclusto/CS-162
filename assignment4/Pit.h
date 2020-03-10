/***************************************************************************
** File: Pit.h
** Author: Allen Benjamin
** Date: 02/29/2020
** Description: Represents a Pit
**************************************************************************/

#ifndef PIT_H
#define PIT_H

#include "Event.h"

class Pit: public Event {
public:
/********************************************************
** Function: Pit constructor
** Description: initializes row and column
** Input: row and column
** Pre-Conditions: none
** Post-Conditions: row and column are initialized
********************************************************/
	Pit(int r = 0, int c = 0);

/********************************************************
** Function: Pit destructor
** Description: removes the annoying warning
** Input: none
** Pre-Conditions: none
** Post-Conditions: none
********************************************************/
	~Pit() {}

/********************************************************
** Function: percept()
** Description: displays a message indicating the Pit is nearby
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
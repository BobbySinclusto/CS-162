/***************************************************************************
** File: Bat.h
** Author: Allen Benjamin
** Date: 02/29/2020
** Description: Represents a Bat
**************************************************************************/

#ifndef BAT_H
#define BAT_H

#include "Event.h"

class Bat: public Event {
public:
/********************************************************
** Function: Bat constructor
** Description: initializes row and column
** Input: row and column
** Pre-Conditions: none
** Post-Conditions: row and column are initialized
********************************************************/
	Bat(int r = 0, int c = 0);

/********************************************************
** Function: Bat destructor
** Description: removes the annoying warning
** Input: none
** Pre-Conditions: none
** Post-Conditions: none
********************************************************/
	~Bat() {}

/********************************************************
** Function: percept()
** Description: displays a message indicating the Bat is nearby
** Input: none
** Pre-Conditions: none
** Post-Conditions: message is displayed
********************************************************/
	void percept() override;

/********************************************************
** Function: encounter()
** Description: prints a message, teleports the player to a randomly chosen room
** Input: reference to the game object
** Pre-Conditions: none
** Post-Conditions: returns true if the room contains an event that kills the player, false otherwise
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
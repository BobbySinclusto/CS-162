/***************************************************************************
** File: Gold.h
** Author: Allen Benjamin
** Date: 02/29/2020
** Description: Represents a Gold
**************************************************************************/

#ifndef GOLD_H
#define GOLD_H

#include "Event.h"

class Gold: public Event {
public:
/********************************************************
** Function: Gold constructor
** Description: initializes row and column
** Input: row and column
** Pre-Conditions: none
** Post-Conditions: row and column are initialized
********************************************************/
	Gold(int r = 0, int c = 0);

/********************************************************
** Function: Gold destructor
** Description: removes the annoying warning
** Input: none
** Pre-Conditions: none
** Post-Conditions: none
********************************************************/
	~Gold() {}

/********************************************************
** Function: percept()
** Description: displays a message indicating the Gold is nearby
** Input: none
** Pre-Conditions: none
** Post-Conditions: message is displayed
********************************************************/
	void percept() override;

/********************************************************
** Function: encounter()
** Description: changes has_gold to true for the player, changes picked_up to true
** Input: reference to the game object
** Pre-Conditions: none
** Post-Conditions: returns false
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
/***************************************************************************
** File: Event.h
** Author: Allen Benjamin
** Date: 02/29/2020
** Description: Represents an event
**************************************************************************/

#ifndef EVENT_H
#define EVENT_H

class Game;

class Event {
protected:
	int row = 0; // row of the grid where this event is located
	int col = 0; // column of the grid where this event is located
public:
/********************************************************
** Function: Event constructor
** Description: initializes member variables
** Input: none
** Pre-Conditions: none
** Post-Conditions: member variables are initialized
********************************************************/
	Event(int r = 0, int c = 0);

/********************************************************
** Function: Event destructor
** Description: removes the annoying warning
** Input: none
** Pre-Conditions: none
** Post-Conditions: none
********************************************************/
	virtual ~Event() {}
/********************************************************
** Function: percept()
** Description: displays a message indicating what events are adjacent to the player
** Input: none
** Pre-Conditions: none
** Post-Conditions: message is displayed
********************************************************/
	virtual void percept() = 0;

/********************************************************
** Function: encounter()
** Description: displays messages and modifies the game based on what this event does
** Input: reference to the game object
** Pre-Conditions: none
** Post-Conditions: returns whether or not the game should end
********************************************************/
	virtual bool encounter(Game &) = 0;

/********************************************************
** Function: abbreviation()
** Description: returns the abbreviation to show in the map for this event
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns the abbreviation to show in the map for this event
********************************************************/
	virtual char abbreviation() = 0;
};

#endif
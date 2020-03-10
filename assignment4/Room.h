/***************************************************************************
** File: Room.h
** Author: Allen Benjamin
** Date: 02/29/2020
** Description: Represents a Room
**************************************************************************/

#ifndef ROOM_H
#define ROOM_H

#include "Event.h"

class Room {
private:
	bool contains_event;
	Event* event;
public:
/********************************************************
** Function: Room constructor
** Description: initializes contains_event to false
** Input: none
** Pre-Conditions: none
** Post-Conditions: contains_event is initialized
********************************************************/
	Room();

/********************************************************
** Function: Room destructor
** Description: cleans up dynamic memory
** Input: none
** Pre-Conditions: none
** Post-Conditions: memory is freed
********************************************************/
	~Room();

/********************************************************
** Function: has_event()
** Description: returns whether or not this room has an event
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns whether or not this room has an event
********************************************************/	
	bool has_event();

/********************************************************
** Function: get_event()
** Description: returns the event that this room contains
** Input: none
** Pre-Conditions: this room contains an event
** Post-Conditions: returns the event that this room contains
********************************************************/
	Event* get_event();

/********************************************************
** Function: set_event()
** Description: sets contains_event to true and sets event to the provided event
** Input: none
** Pre-Conditions: none
** Post-Conditions: event is set to the provided value
********************************************************/
	void set_event(Event *);

/********************************************************
** Function: remove_event()
** Description: sets contains_event to false, returns event
** Input: none
** Pre-Conditions: this room contains an event
** Post-Conditions: returns event
********************************************************/
	Event* remove_event();
};

#endif
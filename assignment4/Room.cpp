/***************************************************************************
** File: Room.cpp
** Author: Allen Benjamin
** Date: 02/29/2020
** Description: Represents a Room
**************************************************************************/

#include "Room.h"

Room::Room() {
	contains_event = false;
	event = nullptr;
}

Room::~Room() {
	if (contains_event) {
		delete event;
	}
}

bool Room::has_event() {
	return contains_event;
}

Event* Room::get_event() {
	return event;
}

void Room::set_event(Event *e) {
	contains_event = true;
	event = e;
}

Event* Room::remove_event() {
	contains_event = false;
	Event *tmp = event;
	event = nullptr;
	return tmp;
}
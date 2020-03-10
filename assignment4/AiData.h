/***************************************************************************
** File: AiData.h
** Author: Allen Benjamin
** Date: 02/29/2020
** Description: holds data for the AI and does some processing
**************************************************************************/

#ifndef AI_DATA
#define AI_DATA

#include <vector>
#include <string>

using namespace std;

class AiData {
private:
	vector<int> p_rows; // positions at which events were observed
	vector<int> p_cols;
	vector<string> adjacents; // things that were observed
	bool seen; // whether or not this room has been seen yet
	bool verified; // whether or not this contains an event that we know of
	char event; // event that this contains
public:
/********************************************************
** Function: AiData constructor
** Description: initializes member variables
** Input: none
** Pre-Conditions: none
** Post-Conditions: member variables are initialized
********************************************************/
	AiData();

/********************************************************
** Function: was_seen
** Description: returns whether or not this room has been seen yet
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns whether or not this room has been seen yet
********************************************************/
	bool was_seen();

/********************************************************
** Function: is_verified
** Description: returns whether or not this room definitely holds an event
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns whether or not this room definitely holds an event
********************************************************/
	bool is_verified();

/********************************************************
** Function: get_event
** Description: returns event this room contains
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns event this room contains
********************************************************/
	char get_event();

/********************************************************
** Function: update
** Description: adds an adjacent if necessary
** Input: row, col, adj
** Pre-Conditions: none
** Post-Conditions: updated
********************************************************/
	void update(int, int, string);

/********************************************************
** Function: reset
** Description: resets data
** Input: none
** Pre-Conditions: none
** Post-Conditions: data is reset
********************************************************/
	void reset();
};

#endif
/***************************************************************************
** File: Game.h
** Author: Allen Benjamin
** Date: 02/29/2020
** Description: Represents a Game of Hunt the Wumpus
**************************************************************************/

#ifndef GAME_H
#define GAME_H

#include "Room.h"
#include "AiData.h"
#include <string>
#include <vector>

using namespace std;

class Game {
private:
	int size; // size of grid
	int num_arrows; // number of arrows
	bool debug; // whether or not the game is running in debug mode
	bool has_gold; // whether or not the player has gold
	bool shooting; // whether or not the player is currently shooting an arrow

	// Keeping track of special rooms
	int gold_row;
	int gold_col;
	int player_row;
	int player_col;
	int rope_row;
	int rope_col;
	int original_wumpus_row;
	int original_wumpus_col;
	int wumpus_row;
	int wumpus_col;

	vector< vector<Room> > cave; // Represents the cave
	vector< vector<AiData> > ai_data; // Stores data that the ai uses to make decisions

/********************************************************
** Function: initialize
** Description: initializes member variables
** Input: size, debug mode
** Pre-Conditions: none
** Post-Conditions: member variables are initialized
********************************************************/
	void initialize(int, bool);

/********************************************************
** Function: place_wumpus
** Description: places wumpus in the cave
** Input: none
** Pre-Conditions: none
** Post-Conditions: wumpus is placed
********************************************************/
	void place_wumpus();

/********************************************************
** Function: place_bats
** Description: places bats throughout the cave
** Input: none
** Pre-Conditions: none
** Post-Conditions: bats are placed
********************************************************/
	void place_bats();

/********************************************************
** Function: place_pits
** Description: places pits throughout the cave
** Input: none
** Pre-Conditions: none
** Post-Conditions: pits are placed
********************************************************/
	void place_pits();

/********************************************************
** Function: place_gold
** Description: places gold in the cave
** Input: none
** Pre-Conditions: none
** Post-Conditions: gold is placed
********************************************************/
	void place_gold();

/********************************************************
** Function: place_events
** Description: places events throughout the cave
** Input: none
** Pre-Conditions: none
** Post-Conditions: events are placed
********************************************************/
	void place_events();

/********************************************************
** Function: clean_up
** Description: resets the game
** Input: none
** Pre-Conditions: game is over, starting a new game with same configuration
** Post-Conditions: ready for a new game
********************************************************/
	void clean_up();

/********************************************************
** Function: display
** Description: displays the board
** Input: none
** Pre-Conditions: none
** Post-Conditions: board is displayed
********************************************************/
	void display();

/********************************************************
** Function: shoot_arrow
** Description: gets direction from user and shoots an arrow
** Input: user input
** Pre-Conditions: none
** Post-Conditions: an arrow is shot, wumpus moves, stays, or is killed
********************************************************/
	void shoot_arrow(bool ai);

/********************************************************
** Function: ai_get_shoot_direction
** Description: chooses a direction to shoot
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns direction to shoot
********************************************************/
	char ai_get_shoot_direction();

/********************************************************
** Function: get_input
** Description: gets input from the user for direction to move/shoot an arrow
** Input: user input
** Pre-Conditions: none
** Post-Conditions: returns whether or not the user has chosen to shoot an arrow
********************************************************/
	bool get_input();

/********************************************************
** Function: ai_get_input
** Description: updates adjacent rooms in the ai_data vector
** Input: adjacent rooms, bad directions and moved
** Pre-Conditions: none
** Post-Conditions: values are updated, returns whether or not ai wants to shoot an arrow
********************************************************/
	bool update_ai_data(string, string&, bool&);

/********************************************************
** Function: ai_get_input
** Description: gets input from the ai for direction to move/shoot an arrow
** Input: adjacent rooms
** Pre-Conditions: none
** Post-Conditions: returns whether or not the ai has chosen to shoot an arrow
********************************************************/
	bool ai_get_input(string);

/********************************************************
** Function: ai_return_to_rope
** Description: returns to rope, avoiding obstacles
** Input: bad directions
** Pre-Conditions: none
** Post-Conditions: moves toward rope hopefully, return false if unsuccessful
********************************************************/
	bool ai_return_to_rope(string);

/********************************************************
** Function: search_adjacent
** Description: calls percept functions on adjacent rooms with events
** Input: none
** Pre-Conditions: none
** Post-Conditions: messages are displayed, returns list of abbreviations of events
********************************************************/
	string search_adjacent();

/********************************************************
** Function: take_turn
** Description: prompts for input and displays things for a turn
** Input: none
** Pre-Conditions: none
** Post-Conditions: return whether or not the game should end
********************************************************/
	bool take_turn(bool);

/********************************************************
** Function: move_wumpus
** Description: 75% that the wumpus is moved to one of the adjacent rooms
** Input: none
** Pre-Conditions: none
** Post-Conditions: 75% that the wumpus is moved to one of the adjacent rooms
********************************************************/
	void move_wumpus();

public:
/********************************************************
** Function: Game default constructor
** Description: initializes member variables to default values
** Input: none
** Pre-Conditions: none
** Post-Conditions: member variables are initialized
********************************************************/
	Game();

/********************************************************
** Function: Game alternate constructor
** Description: initializes member variables
** Input: size, debug mode
** Pre-Conditions: inputs are valid
** Post-Conditions: member variables are initialized
********************************************************/
	Game(int, bool);

/********************************************************
** Function: get_size
** Description: returns the size
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns the size
********************************************************/
	int get_size();

/********************************************************
** Function: move_player
** Description: moves the player
** Input: new row, new column
** Pre-Conditions: none
** Post-Conditions: player is moved to the specified position
********************************************************/
	void move_player(int, int);


/********************************************************
** Function: get_cave
** Description: returns the cave
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns the cave
********************************************************/
	vector< vector<Room> >& get_cave();

/********************************************************
** Function: get_gold
** Description: updates the has_gold member variable
** Input: none
** Pre-Conditions: none
** Post-Conditions: has_gold is true
********************************************************/
	void get_gold();

/********************************************************
** Function: play
** Description: plays the game
** Input: none
** Pre-Conditions: none
** Post-Conditions: the user has chosen to quit
********************************************************/
	void play();
};

#endif
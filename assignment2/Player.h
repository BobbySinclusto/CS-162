/***************************************************************************
** File: Player.h
** Author: Allen Benjamin
** Date: 01/28/2020
** Description: Represents a Player
**************************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "Hand.h"
#include "Deck.h"
#include <iostream>

using namespace std;

class Player {
private:
	Hand hand; // represents the hand of the player
	string name; // represents the name of the player
	bool is_computer; // represents whether or not the player is a computer

/********************************************************
** Function: choose_suit()
** Description: gets the suit that the player wants to use when they play an 8
** Input: index
** Pre-Conditions: index is a valid index
** Post-Conditions: modifies the card at the specified index to have the chosen suit
********************************************************/
	void choose_suit(int);

/********************************************************
** Function: choose_card_human()
** Description: prompts the user for a card to play
** Input: draw pile, top card on discard pile
** Pre-Conditions: the arguments are valid
** Post-Conditions: returns the index of the card the user wants to play
********************************************************/
	int choose_card_human(Deck &, const Card &);

/********************************************************
** Function: choose_card_computer()
** Description: returns the index of a card that can be played
** Input: draw pile, top card on discard pile
** Pre-Conditions: the arguments are valid
** Post-Conditions: returns the index of the card the computer wants to play
********************************************************/
	int choose_card_computer(Deck &, const Card &);

/********************************************************
** Function: choose_card()
** Description: returns the index of a card that the player wants to play
** Input: draw pile, top card on discard pile
** Pre-Conditions: the arguments are valid
** Post-Conditions: returns the index of the card the player wants to play
********************************************************/
	int choose_card(Deck &, const Card &);
public:

/********************************************************
** Function: Player default constructor
** Description: creates a Player object that represents a computer oponent
** Input: none
** Pre-Conditions: none
** Post-Conditions: initializes the Player object with stuff for a computer oponent
********************************************************/
	Player();

/********************************************************
** Function: Player constructor
** Description: creates a Player object that represents a human
** Input: none
** Pre-Conditions: none
** Post-Conditions: initializes the player object with stuff for a human user
********************************************************/
	Player(string);

/********************************************************
** Function: get_hand()
** Description: gets the hand of the player
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns the hand of the player
********************************************************/
	Hand& get_hand();

/********************************************************
** Function: get_name()
** Description: returns the name of the player
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns the name of the player
********************************************************/
	string get_name() const;

/********************************************************
** Function: take_turn()
** Description: plays a turn
** Input: draw pile and top card on discard pile
** Pre-Conditions: it is this player's turn
** Post-Conditions: displays information, gets user input, returns whether or not this player has won
********************************************************/
	bool take_turn(Deck &, Card &);
};

#endif
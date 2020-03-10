/***************************************************************************
** File: Card.h
** Author: Allen Benjamin
** Date: 01/28/2020
** Description: Represents a Card
**************************************************************************/

#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;

class Card {
private:
	int suit; // Represents the suit of a card (0-3)
	int rank; // Represents the rank of a card (0-12)
public:
/********************************************************
** Function: Card constructor
** Description: Initializes member variables to corresponding values
** Input: suit, rank
** Pre-Conditions: suit is a valid suit, rank is a valid rank
** Post-Conditions: the card object is initialized
********************************************************/
	Card(int s = 0, int r = 0);

/********************************************************
** Function: get_suit()
** Description: returns the suit
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns the suit
********************************************************/
	int get_suit() const;

/********************************************************
** Function: get_rank()
** Description: returns the rank
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns the rank
********************************************************/
	int get_rank() const;

/********************************************************
** Function: set_suit()
** Description: sets the suit to the provided value
** Input: suit
** Pre-Conditions: suit is a valid suit
** Post-Conditions: suit is set to the provided value
********************************************************/
	void set_suit(int);

/********************************************************
** Function: set_rank()
** Description: sets the rank to the provided value
** Input: rank
** Pre-Conditions: rank is a valid rank
** Post-Conditions: rank is set to the provided value
********************************************************/
	void set_rank(int);

/********************************************************
** Function: update()
** Description: updates the suit and rank to provided values
** Input: suit, rank
** Pre-Conditions: suit is a valid suit, rank is a valid rank
** Post-Conditions: suit and rank are updated to provided values
********************************************************/
	void update(int, int);

/********************************************************
** Function: print()
** Description: prints the card
** Input: none
** Pre-Conditions: none
** Post-Conditions: prints the card
********************************************************/
	void print() const;

/********************************************************
** Function: matches()
** Description: returns whether or not this card matches the given card's rank or suit
** Input: card
** Pre-Conditions: card is a valid card
** Post-Conditions: returns whether or not this card is a match
********************************************************/
	bool matches(const Card &) const;
};

#endif
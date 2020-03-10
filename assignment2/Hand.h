/***************************************************************************
** File: Hand.h
** Author: Allen Benjamin
** Date: 01/28/2020
** Description: Represents a Hand of Cards
**************************************************************************/

#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include <iostream>

using namespace std;

class Hand {
private:
	Card *cards; // holds the cards that make up the hand
	int size; // number of cards in hand
	int arr_size; // size of array of cards

/********************************************************
** Function: increase_size()
** Description: doubles the size of the array
** Input: none
** Pre-Conditions: none
** Post-Conditions: doubles the size of the array
********************************************************/
	void increase_size();
public:

/********************************************************
** Function: Hand default con structor
** Description: creates a Hand object
** Input: none
** Pre-Conditions: none
** Post-Conditions: members are initialized
********************************************************/
	Hand();

/********************************************************
** Function: Hand copy constructor
** Description: creates a new copy of the provided Hand object
** Input: Hand object to copy
** Pre-Conditions: the provided hand object is valid
** Post-Conditions: members are initialized
********************************************************/
	Hand(const Hand &);

/********************************************************
** Function: Hand assignment operator overload
** Description: returns a copy of the provided Hand object
** Input: Hand object to copy
** Pre-Conditions: the provided hand object is valid
** Post-Conditions: returns the copy
********************************************************/
	Hand& operator=(const Hand &);

/********************************************************
** Function: Hand destructor
** Description: cleans up dynamic memory
** Input: none
** Pre-Conditions: none
** Post-Conditions: frees memory allocated for cards
********************************************************/
	~Hand();

/********************************************************
** Function: get_cards()
** Description: returns the card array
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns the card array
********************************************************/
	Card* get_cards();

/********************************************************
** Function: get_size()
** Description: returns the number of cards in the hand
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns the number of cards in the hand
********************************************************/
	int get_size() const;

/********************************************************
** Function: receive_card()
** Description: adds a card to the hand
** Input: card to add
** Pre-Conditions: card is valid
** Post-Conditions: the size increases and the card is added to the cards array
********************************************************/
	void receive_card(const Card &);

/********************************************************
** Function: play_card()
** Description: plays the card at the specified index
** Input: index
** Pre-Conditions: index is a valid index
** Post-Conditions: the card at the given index is returned
********************************************************/
	Card& play_card(int);

/********************************************************
** Function: print()
** Description: prints the hand with numbered options
** Input: none
** Pre-Conditions: none
** Post-Conditions: print the hand with numbered options
********************************************************/
	void print() const;
};

#endif
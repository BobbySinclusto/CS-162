/***************************************************************************
** File: Deck.h
** Author: Allen Benjamin
** Date: 01/28/2020
** Description: Represents a Deck of Cards
**************************************************************************/

#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <iostream>

using namespace std;

class Deck {
private:
	Card cards[52]; // Holds the cards in the deck
	int size; // Number of cards in the deck

/********************************************************
** Function: swap_cards()
** Description: swaps the given cards
** Input: card 1, card 2
** Pre-Conditions: both cards are valid
** Post-Conditions: cards are swapped
********************************************************/
	void swap_cards(Card &, Card &);
public:

/********************************************************
** Function: Deck constructor
** Description: creates a deck of 52 cards and shuffles it
** Input: none
** Pre-Conditions: none
** Post-Conditions: Deck object is initialized
********************************************************/
	Deck();

/********************************************************
** Function: get_cards()
** Description: returns the cards array
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns the cards array
********************************************************/
	Card* get_cards();

/********************************************************
** Function: get_size()
** Description: returns the number of cards in the deck
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns the number of cards in the deck
********************************************************/
	int get_size() const;

/********************************************************
** Function: shuffle()
** Description: shuffles the deck.
** Input: none
** Pre-Conditions: none
** Post-Conditions: the deck is shuffled
********************************************************/
	void shuffle();

/********************************************************
** Function: draw()
** Description: takes a card off the top of the deck
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns the card on top of the deck, decrements the size of the deck
********************************************************/
	Card& draw();

/********************************************************
** Function: print()
** Description: sets the suit to the provided value
** Input: suit
** Pre-Conditions: suit is a valid suit
** Post-Conditions: suit is set to the provided value
********************************************************/
	void print() const;
};

#endif
/***************************************************************************
** File: Card.cpp
** Author: Allen Benjamin
** Date: 01/28/2020
** Description: Represents a Card
**************************************************************************/

#include "Card.h"
#include <iostream>

using namespace std;

Card::Card(int s, int r) {
	suit = s;
	rank = r;
}

int Card::get_suit() const {
	return suit;
}

int Card::get_rank() const {
	return rank;
}

void Card::set_suit(int s) {
	suit = s;
}

void Card::set_rank(int r) {
	rank = r;
}

void Card::update(int s, int r) {
	suit = s;
	rank = r;
}

void Card::print() const {
	string suits[] = {"Spades", "Clubs", "Hearts", "Diamonds"};
	string ranks[] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
	cout << ranks[rank] << " of " << suits[suit] << endl;
}

bool Card::matches(const Card &c) const {
	return (suit == c.suit || rank == c.rank);
}
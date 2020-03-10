/***************************************************************************
** File: Hand.cpp
** Author: Allen Benjamin
** Date: 01/28/2020
** Description: Represents a Hand of Cards
**************************************************************************/
#include "Hand.h"
#include "Card.h"
#include <iostream>

using namespace std;

Hand::Hand() {
	size = 0;
	arr_size = 8;
	cards = new Card[arr_size];
}

Hand::Hand(const Hand &h) {
	size = h.size;
	arr_size = h.arr_size;
	cards = new Card[arr_size];
	for (int i = 0; i < arr_size; i++) {
		cards[i] = h.cards[i];
	}
}

Hand& Hand::operator=(const Hand &h) {
	if (&h != this) {
		delete [] cards;
		size = h.size;
		arr_size = h.arr_size;
		cards = new Card[arr_size];
		for (int i = 0; i < arr_size; i++) {
			cards[i] = h.cards[i];
		}
	}
	return *this;
}

Hand::~Hand() {
	delete [] cards;
}

void Hand::increase_size() {
	arr_size *= 2;
	Card *tmp = new Card[arr_size];
	for (int i = 0; i < size; i++) {
		tmp[i] = cards[i];
	}
	delete [] cards;
	cards = tmp;
}

Card* Hand::get_cards() {
	return cards;
}

int Hand::get_size() const {
	return size;
}

void Hand::receive_card(const Card &c) {
	if (size + 1 >= arr_size) {
		increase_size();
	}
	cards[size] = c;
	size++;
}

Card& Hand::play_card(int index) {
	Card tmp = cards[index];
	for (int i = index + 1; i < size; i++) {
		cards[i - 1] = cards[i];
	}
	size--;
	cards[size] = tmp;
	return cards[size];
}

void Hand::print() const {
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ". ";
		cards[i].print();
	}
	cout << size + 1 << ". Draw another card" << endl;
}
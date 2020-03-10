#include "Deck.h"
#include "Card.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Deck::Deck() {
	size = 52;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			cards[i*13 + j] = Card(i, j);
		}
	}
	shuffle();
}

Card *Deck::get_cards() {
	return cards;
}

int Deck::get_size() const {
	return size;
}

void Deck::swap_cards(Card &c1, Card &c2) {
	Card tmp = c1;
	c1 = c2;
	c2 = tmp;
}

void Deck::shuffle() {
	for (int i = 0; i < 52; i++) {
		swap(cards[i], cards[rand() % 52]);
	}
}

void Deck::print() const {
	for (int i = 0; i < 52; i++) {
		cards[i].print();
		cout << endl;
	}
}

Card& Deck::draw() {
	size--;
	return cards[size];
}

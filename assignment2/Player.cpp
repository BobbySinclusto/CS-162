/***************************************************************************
** File: Player.h
** Author: Allen Benjamin
** Date: 01/28/2020
** Description: Represents a Player
**************************************************************************/

#include "Player.h"
#include "helper_functions.h"
#include <iostream>

using namespace std;

Player::Player() {
	name = "Computer";
	is_computer = true;
}

Player::Player(string n) {
	name = n;
	is_computer = false;
}

Hand& Player::get_hand() {
	return hand;
}

string Player::get_name() const {
	return name;
}

void Player::choose_suit(int index) {
	if (is_computer) {
		int counts[] = {0, 0, 0, 0};
		int suit = 0;
		for (int i = 0; i < hand.get_size(); i++) {
			counts[hand.get_cards()[i].get_suit()] ++;
		}
		for (int i = 1; i < 4; i++) {
			if (counts[0] < counts[i]) {
				counts[0] = counts[i];
				suit = i;
			}
		}
		hand.get_cards()[index].set_suit(suit);
	}
	else {
		cout << "Choose a suit for the 8:" << endl;
		for (int i = 0; i < 4; i++) {
			string suits[] = {"Spades", "Clubs", "Hearts", "Diamonds"};
			cout << i+1 << ". " << suits[i] << endl;
		}
		hand.get_cards()[index].set_suit(get_input_range("Choose an option (1-4): ", 1, 4) - 1);
	}
}

int Player::choose_card_human(Deck &stock, const Card &c) {
	while (true) {
		cout << "Choose a card to play or draw another card:" << endl;
		hand.print();
		int index = get_input_range("Choose an option: ", 1, hand.get_size() + 1) - 1;
		cout << endl;
		if (index == hand.get_size()) {
			hand.receive_card(stock.draw());
			if (stock.get_size() == 0) {
				cout << "You drew the last card!" << endl;
				return -1;
			}
		}
		else if (hand.get_cards()[index].matches(c) || hand.get_cards()[index].get_rank() == 7) {
			return index;
		}
		else {
			cout << "That card doesn't match. Try again.\n" << endl;
		}
		
	}
}

int Player::choose_card_computer(Deck &stock, const Card &c) {
	for (int i = 0; i < hand.get_size(); i++) {
		if (hand.get_cards()[i].matches(c)) {
			return i;
		}
	}
	for (int i = 0; i < hand.get_size(); i++) {
		if (hand.get_cards()[i].get_rank() == 7) {
			return i;
		}
	}
	while (true) {
		hand.receive_card(stock.draw());
		if (stock.get_size() == 0) {
			cout << "Computer drew the last card!" << endl;
			return -1;
		}
		if (hand.get_cards()[hand.get_size() - 1].get_rank() == 7) {
			return hand.get_size() - 1;
		}
	}
}

int Player::choose_card(Deck &stock, const Card &c) {
	if (is_computer) {
		choose_card_computer(stock, c);
	}
	else {
		return choose_card_human(stock, c);
	}
}

bool Player::take_turn(Deck &stock, Card &pile) {
	cout << name << "'s turn!\t" << "There are " << stock.get_size() << " cards left in the deck." << endl;
	cout << "The top card on the deck is: ";
	pile.print();
	cout << endl;
	int index = choose_card(stock, pile);
	if (index == -1) {
		return true;
	}
	if (hand.get_cards()[index].get_rank() == 7) {
		choose_suit(index);
	}
	pile = hand.play_card(index);
	if (hand.get_size() == 0) {
		cout << name << " is out of cards!" << endl;
		return true;
	}
	return false;
}
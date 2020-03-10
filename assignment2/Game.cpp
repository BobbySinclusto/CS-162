/***************************************************************************
** File: Game.cpp
** Author: Allen Benjamin
** Date: 01/28/2020
** Description: Represents a Game of crazy_eights
**************************************************************************/

#include "Game.h"
#include "Card.h"
#include "Player.h"
#include "Deck.h"
#include <iostream>

using namespace std;

Game::Game() {
	string name;
	cout << "Enter your name: ";
	getline(cin, name);
	cout << endl;
	players[0] = Player(name);
	for (int i = 0; i < 7; i++) {
		players[0].get_hand().receive_card(cards.draw());
		players[1].get_hand().receive_card(cards.draw());
	}
	pile = cards.draw();
}

void Game::determine_winner() {
	if (players[0].get_hand().get_size() < players[1].get_hand().get_size()) {
		cout << players[0].get_name() << " wins!" << endl;
		return;
	}
	cout << players[1].get_name() << " wins!" << endl;
}

void Game::play() {
	while (true) {
		if (players[0].take_turn(cards, pile)) {
			determine_winner();
			return;
		}
		if (players[1].take_turn(cards, pile)) {
			determine_winner();
			return;
		}
	}
}
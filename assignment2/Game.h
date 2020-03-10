/***************************************************************************
** File: Game.h
** Author: Allen Benjamin
** Date: 01/28/2020
** Description: Represents a Game of crazy_eights
**************************************************************************/

#ifndef GAME_H
#define GAME_H

#include "Card.h"
#include "Player.h"
#include "Deck.h"
#include <iostream>

using namespace std;

class Game {
private:
	Deck cards; // Draw pile
	Player players[2]; // Player 0 is human player, player 1 is computer
	Card pile; // Top card on the discard pile

/********************************************************
** Function: determine_winner()
** Description: determines the winner
** Input: none
** Pre-Conditions: the game is ending
** Post-Conditions: displays whichever player has lest cards
********************************************************/
	void determine_winner();
public:

/********************************************************
** Function: Game constructor
** Description: creates a game object
** Input: name of human player (input from user)
** Pre-Conditions: none
** Post-Conditions: members are initialized
********************************************************/
	Game();
	void play();
};

#endif
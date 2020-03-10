/***************************************************************************
** File: Game.cpp
** Author: Allen Benjamin
** Date: 02/29/2020
** Description: Represents a Game of Hunt the Wumpus
**************************************************************************/

#include "Game.h"
#include "Event.h"
#include "Bat.h"
#include "Gold.h"
#include "Pit.h"
#include "Wumpus.h"
#include "Room.h"
#include "colors.h"
#include "helper_functions.h"
#include "AiData.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

Game::Game() {
	size = 0;
	num_arrows = 0;
	debug = false;
	has_gold = false;
	shooting = false;
	gold_row = gold_col = player_row = player_col = rope_row = rope_col = original_wumpus_row = original_wumpus_col = wumpus_row = wumpus_col = 0;
}

Game::Game(int s, bool dbg) {
	initialize(s, dbg);
	place_events();
}

void Game::initialize(int s, bool dbg) {
	shooting = false;
	size = s;
	num_arrows = 3;
	debug = dbg;
	has_gold = false;
	for (int i = 0; i < s; ++i) {
		cave.push_back(vector<Room>());
		ai_data.push_back(vector<AiData>());
		for (int j = 0; j < s; ++j) {
			ai_data[i].push_back(AiData());
			cave[i].push_back(Room());
		}
	}
}

int Game::get_size() {
	return size;
}

void Game::move_player(int r, int c) {
	player_row = r;
	player_col = c;
}

vector<vector<Room>>& Game::get_cave() {
	return cave;
}

void Game::get_gold() {
	has_gold = true;
	delete cave[gold_row][gold_col].remove_event();
}

void Game::place_wumpus() {
	do {
		original_wumpus_row = wumpus_row = rand() % size;
		original_wumpus_col = wumpus_col = rand() % size;
	} while (wumpus_row == player_row && wumpus_col == player_col);
	cave[wumpus_row][wumpus_col].set_event(new Wumpus(wumpus_row, wumpus_col));
}

void Game::place_bats() {
	int r, c;
	for (int i = 0; i < 2; ++i) {
		do {
			r = rand() % size;
			c = rand() % size;
		} while (cave[r][c].has_event() || (r == player_row && c == player_col));
		cave[r][c].set_event(new Bat(r, c));
	}
}

void Game::place_pits() {
	int r, c;
	for (int i = 0; i < 2; ++i) {
		do {
			r = rand() % size;
			c = rand() % size;
		} while (cave[r][c].has_event() || (r == player_row && c == player_col));
		cave[r][c].set_event(new Pit(r, c));
	}
}

void Game::place_gold() {
	do {
		gold_row = rand() % size;
		gold_col = rand() % size;
	} while (cave[gold_row][gold_col].has_event() || (gold_row == player_row && gold_col == player_col));
	cave[gold_row][gold_col].set_event(new Gold(gold_row, gold_col));
}

void Game::place_events() {
	// First we'll place the player and escape rope.
	player_row = rope_row = rand() % size;
	player_col = rope_col = rand() % size;

	// Next we'll place the wumpus, making sure not to place it in the same spot as the escape rope.
	place_wumpus();

	// Now the super bats
	place_bats();

	// Now the pits
	place_pits();

	// Now the gold
	place_gold();

}

void Game::clean_up() {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			ai_data[i][j].reset();
		}
	}
	num_arrows = 3;
	if (cave[wumpus_row][wumpus_col].has_event()) {
		cave[original_wumpus_row][original_wumpus_col].set_event(cave[wumpus_row][wumpus_col].remove_event());
	}
	else {
		cave[original_wumpus_row][original_wumpus_col].set_event(new Wumpus(original_wumpus_row, original_wumpus_col));
	}
	wumpus_row = original_wumpus_row;
	wumpus_col = original_wumpus_col;
	if (has_gold) {
		cave[gold_row][gold_col].set_event(new Gold(gold_row, gold_col));
		has_gold = false;
	}
	player_row = rope_row;
	player_col = rope_col;
}

void Game::display() {
	cout << "You have " << BLUE << num_arrows << RESET << " arrows." << endl;

	// Print the board (the ternary operator is fun!)
	for (int i = 0; i < size * 4 + 1; ++i) { // Rows
		for (int j = 0; j < size * 4 + 1; ++j) { // Columns
			cout << (j % 4 == 0 ? (i % 4 == 0 ? '+' : '|') : (i % 4 == 0 ? '-' : (j % 2 == 0 && i % 2 == 0 ? (i / 4 == player_row && j / 4 == player_col ? '*' : (debug ? (cave[i/4][j/4].has_event() ? (cave[i/4][j/4].get_event()->abbreviation()) : (i / 4 == rope_row && j / 4 == rope_col) ? 'R' : ' ') : ' ')) : ' ')));
		}
		cout << endl;
	}
}

void Game::shoot_arrow(bool ai) {
	if (num_arrows == 0) {
			cout << RED << "Out of arrows!" << RESET << endl;
			return;
	}
	--num_arrows;
	char d = ai ? ai_get_shoot_direction() : get_input_wasd("Enter a direction to shoot (wasd): ", false);
	cout << CLEAR;
	if (!cave[wumpus_row][wumpus_col].has_event()) return;
	for (int i = 1; i <= 3; ++i) {
		int r = player_row + (d == 'w' ? -i : (d == 's' ? i : 0));
		int c = player_col + (d == 'a' ? -i : (d == 'd' ? i : 0));
		if (r >= size || c >= size || r < 0 || c < 0) {
			break;
		}
		if (wumpus_row == r && wumpus_col == c) {
			cout << GREEN << "You killed the Wumpus!" << RESET << endl;
			delete cave[r][c].remove_event();
			return;
		}
	}
	cout << "Missed!" << endl;
	move_wumpus();
}

bool Game::get_input() {
	char d = get_input_wasd("Enter a direction to move (wasd), or space to shoot an arrow: ", true);
	if (d == ' ') {
		return true;
	}
	int r = player_row + (d == 'w' ? -1 : (d == 's' ? 1 : 0));
	int c = player_col + (d == 'a' ? -1 : (d == 'd' ? 1 : 0));
	if (r < size && c < size && r >= 0 && c >= 0) {
		player_row = r;
		player_col = c;
	}
	return false;
}

bool Game::ai_return_to_rope(string bad_dirs) {
	if (player_row < rope_row && bad_dirs.find('s') == string::npos) {
		++player_row;
	}
	else if (player_row > rope_row && bad_dirs.find('w') == string::npos) {
		--player_row;
	}
	else if (player_col < rope_col && bad_dirs.find('d') == string::npos) {
		++player_col;
	}
	else if (player_col > rope_col && bad_dirs.find('a') == string::npos) {
		--player_col;
	}
	else {
		return false;
	}
	return true;
}

bool Game::update_ai_data(string adj, string &bad_dirs, bool &moved) {
	char dirs[] = {'d', 'w', 'a', 's'};
	// update data for adjacent rooms
	for(int i = 0; i < 4; ++i) {
		int r = player_row + (i < 2 ? i%2 : -i%2);
		int c = player_col + (i < 2 ? 1-i%2 : i%2-1);
		if (r < size && c < size && r >= 0 && c >= 0) {
			ai_data[r][c].update(player_row, player_col, adj);
			if (ai_data[r][c].is_verified()) {
				if (ai_data[r][c].get_event() == 'G') {
					player_row = r;
					player_col = c;
					moved = true;
					return false;
				}
				if (ai_data[r][c].get_event() == 'W') {
					return true;
				}
				if (ai_data[r][c].get_event() != 0) {
					bad_dirs += dirs[i];
				}
			}
		}
	}
	return false;
}

bool Game::ai_get_input(string adj) {
	get_input_wasd("Press space to continue...", true);
	string bad_dirs = "";
	bool moved = false;
	if (update_ai_data(adj, bad_dirs, moved)) return true;
	if (moved) return false;

	if (has_gold) {
		if (ai_return_to_rope(bad_dirs)) return false;
	}
	int d, r, c;
	do {
		d = rand() % 4;
		r = player_row + (d < 2 ? d%2 : -d%2);
		c = player_col + (d < 2 ? 1-d%2 : d%2-1);
	} while (r >= size || c >= size || r < 0 || c < 0);
	player_row = r;
	player_col = c;
	return false;
}

char Game::ai_get_shoot_direction() {
	for(int i = 0; i < 4; ++i) {
		int r = player_row + (i < 2 ? i%2 : -i%2);
		int c = player_col + (i < 2 ? 1-i%2 : i%2-1);
		if (r < size && c < size && r >= 0 && c >= 0) {
			if (ai_data[r][c].get_event() == 'W') {
				char dirs[] = {'d', 'w', 'a', 's'};
				return (dirs[i]);
			}
		}
	}
	return 0;
}

string Game::search_adjacent() {
	vector<int> adj;
	string s = "";
	for (int i = 0; i < 4; ++i) adj.push_back(i);
	std::random_shuffle(adj.begin(), adj.end());
	for (int d : adj) {
		int r = player_row + (d < 2 ? d%2 : -d%2);
		int c = player_col + (d < 2 ? 1-d%2 : d%2-1);
		if (r < size && c < size && r >= 0 && c >= 0) {
			if (cave[r][c].has_event()) {
				cave[r][c].get_event()->percept();
				s += cave[r][c].get_event()->abbreviation();
			}
		}
	}
	return s;
}

bool Game::take_turn(bool ai) {
	if (shooting) {
		shoot_arrow(ai);
		shooting = false;
	}
	else {
		cout << CLEAR;
	}
	// if this room contains an event, encounter it
	if (cave[player_row][player_col].has_event()) {
		if (cave[player_row][player_col].get_event()->encounter(*this)) return true;
	}
	if (has_gold && player_row == rope_row && player_col == rope_col) {
		cout << GREEN << BOLD << "YOU WIN!" << RESET << endl;
		return true;
	}
	// search all adjacent rooms, in a random order, and call their percept functions
	string adj = search_adjacent();
	// display board
	display();
	shooting = ai ? ai_get_input(adj) : get_input();
	return false;
}

void Game::move_wumpus() {
	if (rand() % 4 == 0) return;
	int d, r, c, tries = 0;
	do {
		++tries;
		d = rand() % 4;
		r = wumpus_row + (d < 2 ? d%2 : -d%2);
		c = wumpus_col + (d < 2 ? 1-d%2 : d%2-1);
	} while (tries < 8 && (r >= size || c >= size || r < 0 || c < 0 || cave[r][c].has_event() || (r == rope_row && c == rope_col) || (r == player_row && c == player_col)));
	cave[r][c].set_event(cave[wumpus_row][wumpus_col].remove_event());
	wumpus_row = r;
	wumpus_col = c;
}

void Game::play() {
	bool ai = get_input_range("Would you like to watch the AI play? (1-yes, 0-no): ", 0, 1);
	while (true) {
		if (take_turn(ai)) {
			if (!get_input_range("Would you like to play again? (1-yes, 0-no): ", 0, 1)) return;
			ai = get_input_range("Would you like to watch the AI play? (1-yes, 0-no): ", 0, 1);
			if (get_input_range("Would you like to use the same configuration? (1-yes, 0-no): ", 0, 1)) {
				clean_up();
			}
			else {
				int s = get_input_range("Enter the size of the grid (between 4 and 50): ", 4, 50);
				bool dbg = get_input_range("Run in debug mode? (1-yes, 0-no): ", 0, 1);
				cave.clear();
				ai_data.clear();
				initialize(s, dbg);
				place_events();
			}
		}
	}
}

/*
	if (j % 4 == 0) {
		cout << (i % 4 == 0 ? "+" : "|");
	}
	else {
		if (i % 4 == 0) {
			cout << "-";
		}
		else if (j % 2 == 0 && i % 2 == 0) {
			if (i / 4 == player_row && j / 4 == player_col) {
				cout << "*";
			}
			else {
				if (debug) {
					if (cave[i/4][j/4].has_event()) {
						cout << cave[i/4][j/4].get_event()->abbreviation();
					}
					else if (i / 4 == rope_row && j / 4 == rope_col) {
						cout << "R";
					}
					else {
						cout << " ";
					}
				}
				else {
					cout << " ";
				}
			}
		}
		else {
			cout << " ";
		}
	}
*/

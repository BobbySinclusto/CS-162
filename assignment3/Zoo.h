/***************************************************************************
** File: Zoo.h
** Author: Allen Benjamin
** Date: 01/16/2020
** Description: Represents a zoo tycoon game
**************************************************************************/

#ifndef ZOO_H
#define ZOO_H

#include "Animal.h"
#include "Bear.h"
#include "SeaLion.h"
#include "Tiger.h"
#include <iostream>

using namespace std;

class Zoo {
private:
	int funds; // the moneys
	Animal **animals; // animals in the zoo
	int total_animals; // total animals in the zoo
	int num_animals[3]; // total animals of each type, indices correspond to ids of animals: 0-Bear, 1-SeaLion, 2-Tiger
	int num_adults[3]; // total adults of each type, indices correspond to ids of animals: 0-Bear, 1-SeaLion, 2-Tiger
	int month; // current month (months since January 2020)
	int rations; // sick probability out of 2: 1 represents 50%, 2 represents 100%, 4 represents 200%
	int food_cost; // cost of food

/********************************************************
** Function: increase_size()
** Description: allocates memory for and increases the size of the animals array
** Input: none
** Pre-Conditions: none
** Post-Conditions: the size of the array is increased by one, the old data is unaffected
********************************************************/
	void increase_size();

/********************************************************
** Function: remove_animal()
** Description: removes an animal at the given index
** Input: int index
** Pre-Conditions: index is a valid index of the animals array
** Post-Conditions: the animal is removed from the array, count variables are updated
********************************************************/
	void remove_animal(int);

/********************************************************
** Function: take_turn()
** Description: performs actions necessary when taking a turn in zoo tycoon
** Input: user input
** Pre-Conditions: none
** Post-Conditions: progress is displayed, errors in user input are handled, returns whether or not the game is over
********************************************************/
	bool take_turn();

/********************************************************
** Function: update_age()
** Description: calls update functions for each animal in the array
** Input: none
** Pre-Conditions: none
** Post-Conditions: month and count variables are updated
********************************************************/
	void update_age();

/********************************************************
** Function: collect_income()
** Description: adds income from animals to the user's funds
** Input: none
** Pre-Conditions: none
** Post-Conditions: calculates income for each animal, adds it to funds
********************************************************/
	void collect_income(bool);

/********************************************************
** Function: special_event()
** Description: chooses a special event to make happen, then makes it happen
** Input: reference to bonus boolean
** Pre-Conditions: none
** Post-Conditions: bonus represents whether or not the bonus event occurred, function returns whether or not the game is over
********************************************************/
	bool special_event(bool &);

/********************************************************
** Function: get_sick()
** Description: chooses an animal to get sick, makes the user buy medicine or the animal dies
** Input: none
** Pre-Conditions: none
** Post-Conditions: if the user can afford it, they pay for medicine, otherwise the animal dies. return whether or not the game is over
********************************************************/
	bool get_sick();

/********************************************************
** Function: give_birth()
** Description: chooses an animal that can give birth and adds the babies to the zoo
** Input: none
** Pre-Conditions: none
** Post-Conditions: if possible, one of the animals gives birth to some babies
********************************************************/
	bool give_birth();

/********************************************************
** Function: pay_food()
** Description: calculates food cost for each animal and subtracts it from funds
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns whether or not the game is over
********************************************************/
	bool pay_food();

/********************************************************
** Function: you_lose()
** Description: tells the user that they lost
** Input: none
** Pre-Conditions: none
** Post-Conditions: tells the user that they lost
********************************************************/
	void you_lose();

/********************************************************
** Function: display()
** Description: displays game progress
** Input: none
** Pre-Conditions: none
** Post-Conditions: displays game progress
********************************************************/
	void display();

/********************************************************
** Function: get_input()
** Description: gets user input and updates stuff accordingly
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns whether or not the game is over
********************************************************/
	bool get_input();

/********************************************************
** Function: add_animal()
** Description: adds an animal to the zoo
** Input: none
** Pre-Conditions: none
** Post-Conditions: the animal is added to the zoo
********************************************************/
	void add_animal(Animal *);

/********************************************************
** Function: buy_animal()
** Description: gets user input for what type/how many animals and processes the choices
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns whether or not the game is over
********************************************************/
	bool buy_animal();
	
public:

/********************************************************
** Function: Zoo default constructor
** Description: constructs a Zoo object
** Input: none
** Pre-Conditions: none
** Post-Conditions: member variables are initialized, age is 0
********************************************************/
	Zoo();

/********************************************************
** Function: Zoo copy constructor
** Description: constructs a Zoo object
** Input: reference to zoo object to make a copy of
** Pre-Conditions: none
** Post-Conditions: member variables are initialized
********************************************************/
	Zoo(const Zoo &);

/********************************************************
** Function: Zoo assignment operator overload
** Description: performs a deep copy of the zoo object
** Input: reference to zoo object on right side
** Pre-Conditions: none
** Post-Conditions: a deep copy is performed
********************************************************/
	Zoo& operator=(const Zoo &);

/********************************************************
** Function: Zoo destructor
** Description: frees dynamic memory allocated for animals array
** Input: none
** Pre-Conditions: none
** Post-Conditions: all dynamic memory is freed
********************************************************/
	~Zoo();

/********************************************************
** Function: play()
** Description: plays a game of zoo tycoon
** Input: none
** Pre-Conditions: none
** Post-Conditions: the game is over
********************************************************/
	void play();
};

#endif
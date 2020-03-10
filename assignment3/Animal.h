/***************************************************************************
** File: Animal.h
** Author: Allen Benjamin
** Date: 01/16/2020
** Description: Represents a generic animal
**************************************************************************/

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
using namespace std;

class Animal {
private:
	int cost; // cost in $
	int food_cost_multiplier; // how many times more expensive the food for this animal is than normal.
	int id; // animal id (used for determining what type of animal this is)
protected:
	int age; // age in months
	int num_babies; // number of babies this animal can have at a time
public:
/********************************************************
** Function: Animal constructor
** Description: constructs a generic animal object
** Input: cost, food cost multiplier, number of babies, id, age
** Pre-Conditions: none
** Post-Conditions: member variables get initialized
********************************************************/
	Animal(int cost = 0, int food_cost_multiplier = 1, int num_babies = 0, int id = -1, int age = 0);

/********************************************************
** Function: get_id()
** Description: gets id
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns id
********************************************************/
	int get_id();

/********************************************************
** Function: get_cost()
** Description: gets cost
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns cost
********************************************************/
	int get_cost();

/********************************************************
** Function: get_food_cost_multiplier()
** Description: gets food cost multiplier
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns food cost multiplier
********************************************************/
	int get_food_cost_multiplier();

/********************************************************
** Function: get_age()
** Description: gets age
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns age
********************************************************/
	int get_age();

/********************************************************
** Function: get_num_babies()
** Description: gets num_babies
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns num_babies
********************************************************/
	int get_num_babies();

/********************************************************
** Function: increment_age()
** Description: increments the age
** Input: none
** Pre-Conditions: none
** Post-Conditions: age is incremented
********************************************************/
	void increment_age();

/********************************************************
** Function: calculate_revenue()
** Description: calculates revenue
** Input: bool bonus represents whether or not sea lions generate bonus revenue
** Pre-Conditions: none
** Post-Conditions: returns calculated revenue
********************************************************/
	virtual int calculate_revenue(bool bonus);

/********************************************************
** Function: calculate_sick_cost()
** Description: calculates sick cost
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns calculated sick cost
********************************************************/
	int calculate_sick_cost();

/********************************************************
** Function: give_birth()
** Description: returns an animal pointer that points to a new animal
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns an animal pointer that points to a new animal
********************************************************/
	virtual Animal* give_birth() = 0;
};

#endif
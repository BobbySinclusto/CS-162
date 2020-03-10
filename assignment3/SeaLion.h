/***************************************************************************
** File: SeaLion.h
** Author: Allen Benjamin
** Date: 01/16/2020
** Description: Represents a sea lion
**************************************************************************/

#ifndef SEA_LION_H
#define SEA_LION_H

#include "Animal.h"
#include <iostream>
using namespace std;

class SeaLion : public Animal {
public:

/********************************************************
** Function: SeaLion default constructor
** Description: constructs a SeaLion object
** Input: none
** Pre-Conditions: none
** Post-Conditions: member variables are initialized, age is 0
********************************************************/
	SeaLion();

/********************************************************
** Function: SeaLion alternate constructor
** Description: constructs a SeaLion object
** Input: int age
** Pre-Conditions: none
** Post-Conditions: member variables are initialized, age is whatever the input was
********************************************************/
	SeaLion(int);

/********************************************************
** Function: give_birth()
** Description: returns a pointer to a new SeaLion object
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns a pointer to a new SeaLion object
********************************************************/
	Animal* give_birth() override;

/********************************************************
** Function: calculate_revenue()
** Description: calculates revenue, adds sea lion bonus if necessary
** Input: bool bonus
** Pre-Conditions: none
** Post-Conditions: returns calculated revenue
********************************************************/
	int calculate_revenue(bool bonus = 0) override;
};

#endif
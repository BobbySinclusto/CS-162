/***************************************************************************
** File: Bear.h
** Author: Allen Benjamin
** Date: 01/16/2020
** Description: Represents a bear
**************************************************************************/

#ifndef BEAR_H
#define BEAR_H

#include "Animal.h"
#include <iostream>
using namespace std;

class Bear : public Animal {
public:

/********************************************************
** Function: Bear default constructor
** Description: constructs a Bear object
** Input: none
** Pre-Conditions: none
** Post-Conditions: member variables are initialized, age is 0
********************************************************/
	Bear();

/********************************************************
** Function: Bear alternate constructor
** Description: constructs a Bear object
** Input: int age
** Pre-Conditions: none
** Post-Conditions: member variables are initialized, age is whatever the input was
********************************************************/
	Bear(int);

/********************************************************
** Function: give_birth()
** Description: returns a pointer to a new Bear object
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns a pointer to a new Bear object
********************************************************/
	Animal* give_birth() override;
};

#endif
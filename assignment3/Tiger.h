/***************************************************************************
** File: Tiger.h
** Author: Allen Benjamin
** Date: 01/16/2020
** Description: Represents a Tiger
**************************************************************************/

#ifndef TIGER_H
#define TIGER_H

#include "Animal.h"
#include <iostream>
using namespace std;

class Tiger : public Animal {
public:

/********************************************************
** Function: Tiger default constructor
** Description: constructs a Tiger object
** Input: none
** Pre-Conditions: none
** Post-Conditions: member variables are initialized, age is 0
********************************************************/
	Tiger();

/********************************************************
** Function: Tiger alternate constructor
** Description: constructs a Tiger object
** Input: int age
** Pre-Conditions: none
** Post-Conditions: member variables are initialized, age is whatever the input was
********************************************************/
	Tiger(int);

/********************************************************
** Function: give_birth()
** Description: returns a pointer to a new Tiger object
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns a pointer to a new Tiger object
********************************************************/
	Animal* give_birth() override;
};

#endif
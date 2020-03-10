/***************************************************************************
** File: Bear.cpp
** Author: Allen Benjamin
** Date: 01/16/2020
** Description: Represents a bear
**************************************************************************/

#include "Animal.h"
#include "Bear.h"
#include <iostream>

using namespace std;

Bear::Bear() : Animal(5000, 3, 2, 0) {}

Bear::Bear(int age) : Animal(5000, 3, 2, 0, age) {}

Animal* Bear::give_birth() {
	return new Bear();
}
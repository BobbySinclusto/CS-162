/***************************************************************************
** File: Tiger.cpp
** Author: Allen Benjamin
** Date: 01/16/2020
** Description: Represents a tiger
**************************************************************************/

#include "Animal.h"
#include "Tiger.h"
#include <iostream>

using namespace std;

Tiger::Tiger() : Animal(12000, 5, 3, 2) {}

Tiger::Tiger(int age) : Animal(12000, 5, 3, 2, age) {}

Animal* Tiger::give_birth() {
	return new Tiger;
}
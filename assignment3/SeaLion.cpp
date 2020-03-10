/***************************************************************************
** File: SeaLion.cpp
** Author: Allen Benjamin
** Date: 01/16/2020
** Description: Represents a sea lion
**************************************************************************/

#include "Animal.h"
#include "SeaLion.h"
#include <iostream>
#include <cstdlib>

using namespace std;

SeaLion::SeaLion() : Animal(700, 1, 1, 1) {}

SeaLion::SeaLion(int age) : Animal(700, 1, 1, 1, age) {}

Animal* SeaLion::give_birth() {
	return new SeaLion;
}

int SeaLion::calculate_revenue(bool bonus) {
	int res = 2 * Animal::calculate_revenue(bonus);
	if (bonus) {
		res += rand() % 251 + 150;
	}
	return res;
}
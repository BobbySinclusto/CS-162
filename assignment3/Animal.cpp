/***************************************************************************
** File: Animal.cpp
** Author: Allen Benjamin
** Date: 01/16/2020
** Description: Represents a generic animal
**************************************************************************/

#include "Animal.h"
#include <iostream>

using namespace std;

Animal::Animal(int cost, int food_cost_multiplier, int num_babies, int id, int age) {
	this->cost = cost;
	this->food_cost_multiplier = food_cost_multiplier;
	this->num_babies = num_babies;
	this->id = id;
	this->age = age;
}

int Animal::get_id() {
	return id;
}

int Animal::get_cost() {
	return cost;
}

int Animal::get_food_cost_multiplier() {
	return food_cost_multiplier;
}

int Animal::get_age() {
	return age;
}

int Animal::get_num_babies() {
	return num_babies;
}

void Animal::increment_age() {
	++age;
}

int Animal::calculate_revenue(bool bonus) {
	if (age < 6) {
		return 2 * cost / 10;
	}
	return cost / 10;
}

int Animal::calculate_sick_cost() {
	if (age < 6) {
		return cost;
	}
	return cost / 2;
}


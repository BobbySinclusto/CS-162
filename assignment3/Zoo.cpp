/***************************************************************************
** File: Zoo.cpp
** Author: Allen Benjamin
** Date: 01/16/2020
** Description: Represents a zoo
**************************************************************************/

#include "Zoo.h"
#include "helper_functions.h"
#include <iostream>

#define RESET "\u001b[0m"
#define RED "\u001b[31m"
#define GREEN "\u001b[32m"
#define YELLOW "\u001b[33m"
#define BLUE "\u001b[34m"
#define BOLD "\u001b[1m"
#define CLEAR "\u001b[2J"

using namespace std;

Zoo::Zoo() {
	funds = 100000;
	total_animals = 0;
	rations = 2;
	food_cost = 80;
	animals = new Animal*[0];
	for (int i = 0; i < 3; ++i) {
		num_animals[i] = 0;
		num_adults[i] = 0;
	}
	month = 0;
}

Zoo::Zoo(const Zoo &z) {
	funds = z.funds;
	total_animals = z.total_animals;
	rations = z.rations;
	food_cost = z.food_cost;
	for (int i = 0; i < 3; ++i) {
		num_animals[i] = z.num_animals[i];
		num_adults[i] = z.num_adults[i];
	}
	animals = new Animal*[total_animals];
	for (int i = 0; i < total_animals; ++i) {
		*(animals[i]) = *(z.animals[i]);
	}
	month = z.month;
}

Zoo& Zoo::operator=(const Zoo &z) {
	if (&z != this) {
		for (int i = 0; i < total_animals; ++i) {
			delete animals[i];
		}
		delete [] animals;
		funds = z.funds;
		total_animals = z.total_animals;
		rations = z.rations;
		food_cost = z.food_cost;
		for (int i = 0; i < 3; ++i) {
			num_animals[i] = z.num_animals[i];
			num_adults[i] = z.num_adults[i];
		}
		animals = new Animal*[total_animals];
		for (int i = 0; i < total_animals; ++i) {
			*(animals[i]) = *(z.animals[i]);
		}
		month = z.month;
	}
	return *this;
}

Zoo::~Zoo() {
	for (int i = 0; i < total_animals; ++i) {
		delete animals[i];
	}
	delete [] animals;
}

void Zoo::increase_size() {
	++total_animals;
	Animal **tmp = new Animal*[total_animals];
	for (int i = 0; i < total_animals - 1; ++i) {
		tmp[i] = animals[i];
	}
	delete [] animals;
	animals = tmp;
}

void Zoo::add_animal(Animal *a) {
	increase_size();
	animals[total_animals-1] = a;
}

void Zoo::remove_animal(int index) {
	--total_animals;
	--num_animals[animals[index]->get_id()];
	if (animals[index]->get_age() >= 48) {
		--num_adults[animals[index]->get_id()];
	}
	delete animals[index];
	Animal **tmp = new Animal*[total_animals];
	for (int i = 0; i < index; ++i) {
		tmp[i] = animals[i];
	}
	for (int i = index; i < total_animals; ++i) {
		tmp[i] = animals[i + 1];
	}
	delete [] animals;
	animals = tmp;
}

bool Zoo::take_turn() {
	update_age();
	bool bonus = false;
	if (special_event(bonus)) {
		return true;
	}
	collect_income(bonus);
	if (get_input()) {
		return true;
	}
	if (pay_food()) {
		return true;
	}
	return funds <= 0;
}

void Zoo::update_age() {
	++month;
	for (int i = 0; i < total_animals; ++i) {
		animals[i]->increment_age();
		if (animals[i]->get_age() == 48) {
			// update adult count
			++num_adults[animals[i]->get_id()];
		}
	}
}

bool Zoo::special_event(bool &bonus) {
	int choice = rand() % 24; // use 24 because it is the least common denominator of 8 and 12
	if (choice < rations*3) {
		return get_sick();
	}
	else if (choice < 8 + 2 * rations) {  // These calculations adjust the boundaries
		return give_birth();              // based on which food type the user chooses
	}
	else if (choice < 16 + rations) {
		cout << GREEN "A boom in zoo attendance occured! Sea Lions generate extra revenue!" << RESET << endl;
		bonus = true;
	}
	return false; // we know that the user didn't go bankrupt because they didn't lose any money
}

bool Zoo::get_sick() {
	if (total_animals == 0) {
		return false;
	}
	int index = rand() % total_animals;
	string animal_names[] = {"Bear", "Sea Lion", "Tiger"};
	cout << YELLOW << "A " << animal_names[animals[index]->get_id()] << " got sick!" << RESET << endl;
	int cost = animals[index]->calculate_sick_cost();
	if (cost >= funds) {
		cout << RED << "You couldn't afford medicine, so it died. :-(" << RESET << endl;
		remove_animal(index);
		return false;
	}
	else{
		funds -= cost;
		if (funds == 0) {
			return true;
		}
	}
	return false;
}

bool Zoo::give_birth() {
	bool possible[] = {false, false, false};
	for (int i = 0; i < 3; ++i) {
		if (num_animals[i] >= 2) {
			possible[i] = true;
		}
	}
	if (!possible[0] && !possible[1] && !possible[2]) {
		return false;
	}
	int index;
	do {
		index = rand() % total_animals;
	} while (!possible[animals[index]->get_id()]);
	string animal_names[] = {"Bear", "Sea Lion", "Tiger"};
	for (int i = 0; i < animals[index]->get_num_babies(); ++i) {
		add_animal(animals[index]->give_birth());
		++num_animals[animals[index]->get_id()];
	}
	cout << GREEN << "A " << animal_names[animals[index]->get_id()] << " gave birth to " << animals[index]->get_num_babies() << (animals[index]->get_num_babies() > 1 ? " babies!" : " baby!") << RESET << endl;
	return false;
}

void Zoo::collect_income(bool bonus) {
	for (int i = 0; i < total_animals; ++i) {
		funds += animals[i]->calculate_revenue(bonus);
	}
}

bool Zoo::pay_food() {
	for (int i = 0; i < total_animals; ++i) {
		funds -= animals[i]->get_food_cost_multiplier() * food_cost * rations / 2; // calculate food cost for each animal and subtract it from funds
	}
	// update base food cost
	int mult = rand() % 41 + 80;
	food_cost = food_cost * mult / 100;
	return funds <= 0;
}

void Zoo::you_lose() {
	cout << CLEAR << RED << "Your zoo went bankrupt. You managed to last " << month << " months." << RESET << endl;
}

void Zoo::display() {
	string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	cout << BLUE << months[month % 12] << ", " << month / 12 + 2020 << RESET << endl;
	cout << GREEN << "You have " << BOLD << "$" << funds << RESET << endl;
	string foodtypes[] = {"\u001b[32mFamously Fabulous Food\u001b[0m", "\u001b[33mMostly Mediocre Mash\u001b[0m", "\u001b[31mStale Sawdust Soup\u001b[0m"};
	cout << "Current food type: " << foodtypes[rations / 2] << RED << " ($" << food_cost * rations / 2 << ")" << RESET << endl;
	cout << "You have " << num_animals[0] << " Bears and " << num_animals[0] - num_adults[0] << (num_animals[0] - num_adults[0] == 1 ? " is a baby." : " are babies.") << endl;
	cout << "You have " << num_animals[1] << " Sea Lions and " << num_animals[1] - num_adults[1] << (num_animals[1] - num_adults[1] == 1 ? " is a baby." : " are babies.") << endl;
	cout << "You have " << num_animals[2] << " Tigers and " << num_animals[2] - num_adults[2] << (num_animals[2] - num_adults[2] == 1 ? " is a baby." : " are babies.") << endl;
	cout << BLUE << "  1. Continue\n  2. Buy animals\n  3. Change food type\n  4. Quit game" << RESET << endl;
}

bool Zoo::buy_animal() {
	cout << CLEAR << "Which type of animal do you want to buy more of?\n  1. Bears ($5000 each)\n  2. Sea Lions ($12000 each)\n  3. Tigers ($700 each)" << endl;
	int index = get_input_range("Enter an option (1-3): ", 1, 3) - 1;
	int num = get_input_range("How many? (1-2): ", 1, 2);
	for (int i = 0; i < num; ++i) {
		if (index == 0) {
			funds -= 5000;
			add_animal(new Bear(48));
		}
		else if (index == 1) {
			funds -= 12000;
			add_animal(new SeaLion(48));
		}
		else if (index == 2) {
			funds -= 700;
			add_animal(new Tiger(48));
		}
		++num_animals[index];
		++num_adults[index];
	}
	cout << CLEAR;
	return funds <= 0;
}

bool Zoo::get_input() {
	display();
	int choice = get_input_range("Enter an option (1-4): ", 1, 4);
	if (choice == 2) {
		if (buy_animal())
			return true;
	}
	else if (choice == 3) {
		cout << CLEAR << "Choose a food type:\n  1. " << GREEN << "Famously Fabulous Food" << RESET << " (base cost $" << food_cost * 2 << ")";
		cout << "\n  2. " << YELLOW << "Mostly Mediocre Mash" << RESET << " (base cost $" << food_cost << ")";
		cout << "\n  3. " << RED << "Stale Sawdust Soup" << RESET << " (base cost $" << food_cost / 2 << ")" << endl;
		int r = get_input_range("Enter an option (1-3): ", 1, 3);
		rations = (r == 3 ? 4 : (r));
	}
	else if (choice == 4) {
		return true;
	}
	cout << CLEAR;
	return false;
}

void Zoo::play() {
	if (get_input()) {
		return;
	}
	while(!take_turn());
	if (funds <= 0) {
		you_lose();
	}
}

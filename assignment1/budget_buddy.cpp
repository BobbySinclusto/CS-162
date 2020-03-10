/***************************************************************************
** File: budget_buddy.cpp
** Author: Allen Benjamin
** Date: 01/11/2020
** Description: A budget manager for multiple users
** Input: Command line arguments for users file and budgets file
** Output: Sorted transaction history
**************************************************************************/

#include "./budget_buddy.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void check_arguments(int argc, char *argv[], string &userfile, string &budgetfile) {
	if (argc == 3) {
		userfile = argv[1];
		budgetfile = argv[2];
	}
	else {
		if (argc < 3) {
			cout << "Not enough arguments.";
		}
		else {
			cout << "Too many arguments.";
		}
		cout << " Next time, use\n./budget_buddy [user_file] [budget_file]\n" << endl;
		cout << "Enter the filename for the user information file: ";
		getline(cin, userfile);
		cout << "Enter the filename for the budget information file: ";
		getline(cin, budgetfile);
	}
	validate_filenames(userfile, budgetfile);
}

void validate_filenames(string &userfile, string &budgetfile) {
	ifstream testfile(userfile);
	while (!testfile.is_open()) {
		cout << "The user information file you entered couldn't be opened.\nEnter the filename for the user information file: ";
		getline(cin, userfile);
		testfile.open(userfile);
	}
	testfile.close();
	testfile.open(budgetfile);
	while (!testfile.is_open() || userfile == budgetfile) {
		cout << "The budget information file you entered couldn't be opened.\nEnter the filename for the budget information file: ";
		getline(cin, budgetfile);
		testfile.open(budgetfile);
	}
	testfile.close();
}

bool login(user *users, int num_users) {
	int current_user = get_user_index(users, num_users);
	string input;
	for (int i = 0; i < 3; i++) {
		cout << "Enter your password: ";
		getline(cin, input);
		if (input == users[current_user].password) {
			cout << "\nWelcome, " << users[current_user].name << " (ID " << users[current_user].id << ")" << endl;
			return true;
		}
		cout << "Incorrect password. " << 2-i << " attempts remaining." << endl;
	}
	cout << "Congratulations! You successfully entered three incorrect passwords!" << endl;
	return false;
}

float calculate_balance(budget *budgets, int num_buds) {
	float total_balance = 0;
	for (int i = 0; i < num_buds; i++) {
		total_balance += budgets[i].balance;
		for (int j = 0; j < budgets[i].num_transactions; j++) {
			total_balance -= budgets[i].t[j].amount;
		}
	}
	return total_balance;
}

int category_to_value(string category) {
		if (category == "Housing")
			return 1;
		else if (category == "Food")
			return 2;
		else if (category == "Entertainment")
			return 3;
		else if (category == "Personal_Care")
			return 4;
		else if (category == "Miscellaneous")
			return 5;
		return 0;
}

bool compare_transactions(transaction t1, transaction t2, int category) {
	string t1_date;
	string t2_date;
	switch (category) {
		case 1:
			return category_to_value(t1.category) <= category_to_value(t2.category);
		case 2:
			t1_date = t1.date.substr(6,4);
			t1_date += t1.date.substr(0,2);
			t1_date += t1.date.substr(3,2);
			t2_date = t2.date.substr(6,4);
			t2_date += t2.date.substr(0,2);
			t2_date += t2.date.substr(3,2);
			return t1_date >= t2_date;
		case 3:
			return t1.amount >= t2.amount;
		return true;
	}
}

void swap(transaction &t1, transaction &t2) {
	float amount = t1.amount;
	string date = t1.date;
	string category = t1.category;
	string description = t1.description;

	t1.amount = t2.amount;
	t1.date = t2.date;
	t1.category = t2.category;
	t1.description = t2.description;

	t2.amount = amount;
	t2.date = date;
	t2.category = category;
	t2.description = description;
}

bool is_ordered(transaction *trans, int size, int category) {
	for (int i = 1; i < size; i++) {
		if (!compare_transactions(trans[i-1], trans[i], category)) {
			return false;
		}
	}
	return true;
}

void sort_transactions(transaction *trans, int size, int category) {
	while (!is_ordered(trans, size, category)) {
		for (int i = 1; i < size; i++) {
			if(!compare_transactions(trans[i-1], trans[i], category)) {
				swap(trans[i-1], trans[i]);
			}
		}
	}
}

int get_user_index(user *users, int num_users) {
	string input;
	while (true) {
		cout << "Enter your user ID: ";
		getline(cin, input);
		if (input.find_first_not_of("0123456789") == string::npos && input != "") {
			for (int i = 0; i < num_users; i++) {
				if (stoi(input) == users[i].id) {
					return i;
				}
			}
			cout << "That user ID was not recognized. Try again." << endl;
		}
		else {
			cout << "The user ID can only contain integers. Try again." << endl;
		}
	}
}

int get_num_transactions(budget *budgets, int num_budgets) {
	int total = 0;
	for (int i = 0; i < num_budgets; i++) {
		total += budgets[i].num_transactions;
	}
	return total;
}

budget* create_budgets(int size) {
	return new budget[size];
}

user* create_users(int size) {
	return new user[size];
}

transaction* create_transactions(int size) {
	return new transaction[size];
}

int get_size(ifstream &file) {
	string line;
	getline(file, line);
	return stoi(line);
}

void get_user_data(user *users, int num_users, ifstream &file) {
	string line;
	for (int i = 0; i < num_users; i++) {
		getline(file, line, ' ');
		users[i].name = line;
		getline(file, line, ' ');
		users[i].id = stoi(line);
		getline(file, line);
		users[i].password = line;
	}
	file.close();
}

void get_transaction_data(transaction *trans, int size, ifstream &file) {
	string line;
	for (int i = 0; i < size; i++) {
		getline(file, line, ' ');
		trans[i].date = line;
		getline(file, line, ' ');
		trans[i].amount = stof(line);
		getline(file, line, ' ');
		trans[i].description = line;
		getline(file, line);
		trans[i].category = line;
	}
}

void get_budget_data(budget *buds, int num_buds, ifstream &file) {
	string line;
	for (int i = 0; i < num_buds; i++) {
		getline(file, line, ' ');
		buds[i].id = stoi(line);
		getline(file, line, ' ');
		buds[i].balance = stoi(line);
		getline(file, line);
		buds[i].num_transactions = stoi(line);
		buds[i].t = create_transactions(buds[i].num_transactions);
		get_transaction_data(buds[i].t, buds[i].num_transactions, file);
	}
	file.close();
}

void fill_all_transactions(budget *budgets, int num_buds, transaction *all_trans) {
	int index = 0;
	for (int i = 0; i < num_buds; i++) {
		for (int j = 0; j < budgets[i].num_transactions; j++) {
			all_trans[index].amount = budgets[i].t[j].amount;
			all_trans[index].date = budgets[i].t[j].date;
			all_trans[index].category = budgets[i].t[j].category;
			all_trans[index].description = budgets[i].t[j].description;
			index ++;
		}
	}
}

void output_stuff(transaction *all_trans, int num_transactions, int option) {
	cout << endl;
	if (option == 1) {
		for (int i = 0; i < num_transactions; i++) {
			cout << all_trans[i].amount << "\t";
			cout << all_trans[i].date << "\t";
			cout << all_trans[i].category << "\t";
			cout << all_trans[i].description << "\n";
		}
	}
	else {
		string out_filename;
		cout << "Enter the name of the file to write the information to: ";
		getline(cin, out_filename);
		fstream out_file(out_filename, fstream::in | fstream::out | fstream::trunc);
		for (int i = 0; i < num_transactions; i++) {
			out_file << all_trans[i].amount << " ";
			out_file << all_trans[i].date << " ";
			out_file << all_trans[i].category << " ";
			out_file << all_trans[i].description << "\n";
		}
		out_file.close();
	}
	cout << endl;
}

int choose_stuff() {
	cout << "Choose an option:\n  1. Sort transactions by category\n  2. Sort transactions by date\n  3. Sort transactions by dollar amount\n  4. Quit the program\n" << endl;
	int option = 0;
	do {
		cout << "Enter an option (1-4): ";
		string input;
		getline(cin, input);
		option = stoi(input);
	} while (option < 1 && option > 4);
	return option;
}

void run_stuff(user *users, budget *budgets, int num_buds, transaction *all_trans, int num_transactions) {
	while (true) {
		int option = choose_stuff();
		if (option == 4) {
			delete [] all_trans;
			delete_info(users, budgets, num_buds);
			return;
		}

		sort_transactions(all_trans, num_transactions, option);

		cout << "\nChoose an option:\n  1. Display information to the screen\n  2. Write information to a file\n" << endl;
		do {
			cout << "Enter an option (1-2): ";
			string input;
			getline(cin, input);
			option = stoi(input);
		} while (option < 1 && option > 2);

		output_stuff(all_trans, num_transactions, option);
	}
}

void delete_info(user *users, budget *buds, int num_buds) {
	delete [] users;
	for (int i = 0; i < num_buds; i++) {
		delete [] buds[i].t;
	}
	delete [] buds;
}
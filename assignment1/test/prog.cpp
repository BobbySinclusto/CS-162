/***************************************************************************
** Program: prog.cpp
** Author: Allen Benjamin
** Date: 01/11/2020
** Description: A budget manager for multiple users
** Input: Command line arguments for users file and budgets file
** Output: Sorted transaction history
**************************************************************************/
#include "budget_buddy.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {

	string userfile;
	string budgetfile;
	check_arguments(argc, argv, userfile, budgetfile);

	ifstream file(userfile);
	int num_users = get_size(file);
	user *users = create_users(num_users);
	get_user_data(users, num_users, file);

	if (!login(users, num_users)) {
		return 0;
	}

	file.open(budgetfile);
	int num_buds = get_size(file);
	budget *budgets = create_budgets(num_buds);
	get_budget_data(budgets, num_buds, file);

	cout << "Your updated account balance is: $" << calculate_balance(budgets, num_buds) << endl << endl;

	int num_transactions = get_num_transactions(budgets, num_buds);
	transaction *all_trans = new transaction[num_transactions];
	fill_all_transactions(budgets, num_buds, all_trans);

	run_stuff(users, budgets, num_buds, all_trans, num_transactions);

	return 0;
}
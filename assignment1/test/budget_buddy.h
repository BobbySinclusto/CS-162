/***************************************************************************
** File: budget_buddy.h
** Author: Allen Benjamin
** Date: 01/11/2020
** Description: A budget manager for multiple users
** Input: Command line arguments for users file and budgets file
** Output: Sorted transaction history
**************************************************************************/

#ifndef BUDGET_BUDDY_H
#define BUDGET_BUDDY_H

#include <iostream>

using namespace std;

// =================Required Structs=====================
struct user {
	string name;
	int id;
	string password;
};

struct transaction {
	float amount;
	string date;
	string category;
	string description;
};

struct budget {
	int id;
	float balance;
	int num_transactions;
	transaction *t;
};

// ==================Required functions===================

/********************************************************
** Function: create_budgets
** Description: Dynamically allocates an array of budgets
** Input: Size of array
** Pre-Conditions: None
** Post-Conditions: returns a budget array of size size
********************************************************/
budget* create_budgets(int);

/********************************************************
** Function: get_budget_data
** Description: Parses the budgets file and populates the array
** Input: budgets array, num_users, file to read
** Pre-Conditions: The file is formatted correctly, the users array is the right length
** Post-Conditions: The budgets array is populated and the file is closed
********************************************************/
void get_budget_data(budget *, int, ifstream &);

/********************************************************
** Function: create_transactions
** Description: Dynamically allocates an array of transactions
** Input: Size of array
** Pre-Conditions: None
** Post-Conditions: returns a transaction array of size size
********************************************************/
transaction* create_transactions(int);

/********************************************************
** Function: get_transaction_data
** Description: Parses the transactions in the budgets file and populates the array
** Input: transactions array, num_users, file to read
** Pre-Conditions: The file is formatted correctly, the users array is the right length
** Post-Conditions: The transactions array is populated and the file is closed
********************************************************/
void get_transaction_data(transaction *, int, ifstream &);

/********************************************************
** Function: delete_info
** Description: Frees memory
** Input: users array, budgets array, num_buds
** Pre-Conditions: num_buds is how may budgets are in the budgets array
** Post-Conditions: Memory is freed
********************************************************/
void delete_info(user *, budget *, int);


// ==================Additional functions=================

/********************************************************
** Function: fill_all_transactions
** Description: Gets all transactions from the budgets array and stores them in transactions array
** Input: budgets array, size of budgets array, transactions array
** Pre-Conditions: None
** Post-Conditions: All transactions from the budgets array are stored in transactions array
********************************************************/
void fill_all_transactions(budget *, int, transaction *);

/********************************************************
** Function: create_users
** Description: Dynamically allocates an array of users
** Input: Size of array
** Pre-Conditions: None
** Post-Conditions: returns a user array of size size
********************************************************/
user* create_users(int);

/********************************************************
** Function: get_size
** Description: Gets the size by reading the first line of the file
** Input: file to be read
** Pre-Conditions: The file is formatted correctly
** Post-Conditions: returns the size indicated by the file
********************************************************/
int get_size(ifstream &);

/********************************************************
** Function: get_user_data
** Description: Parses the users file and populates the array
** Input: users array, num_users, file to read
** Pre-Conditions: The file is formatted correctly, the users array is the right length
** Post-Conditions: The users array is populated and the file is closed
********************************************************/
void get_user_data(user *, int, ifstream &);

/********************************************************
** Function: check_arguments
** Description: checks the arguments and recovers from bad inputs.
** Input: int argc, char *argv[], string &userfile, string &budgetfile
** Pre-Conditions: argc is the size of argv
** Post-Conditions: both filenames are different, valid files.
********************************************************/
void check_arguments(int, char *[], string &, string &);

/********************************************************
** Function: validate_filenames
** Description: Checks whether the specified files exist, recovers if the files don't exist.
** Input: string &userfile, string &budgetfile
** Pre-Conditions: None
** Post-Conditions: both filenames are different, valid files.
********************************************************/
void validate_filenames(string &, string &);

/********************************************************
** Function: login
** Description: Prompts user for credentials and logs them in if the credentials are valid
** Input: user id and password from user, the users array, the number of users in the array
** Pre-Conditions: None
** Post-Conditions: True if successful, false otherwise.
********************************************************/
bool login(user *, int);

/********************************************************
** Function: get_user_index
** Description: Prompts user for their ID until they input something valid
** Input: user array, number of users in the array, input from user
** Pre-Conditions: None
** Post-Conditions: Returns the user index for the user with the id that the user inputs
********************************************************/
int get_user_index(user *, int);

/********************************************************
** Function: calculate_balance
** Description: Calculates the balance from all stored transactions
** Input: budgets array, size of budgets array
** Pre-Conditions: None
** Post-Conditions: Returns the total balance
********************************************************/
float calculate_balance(budget *, int);

/********************************************************
** Function: category_to_value
** Description: Turns a category into something useful for comparison purposes
** Input: category
** Pre-Conditions: category stores a valid category
** Post-Conditions: Returns 1 for Housing, 2 for Food, 3 for Entertainment, 4 for Personal_Care, 5 for Miscellaneous
********************************************************/
int category_to_value(string);

/********************************************************
** Function: compare_transactions
** Description: Compares two transactions based on the specified category
** Input: transaction 1, transaction 2, category
** Pre-Conditions: category stores a valid category
** Post-Conditions: Returns whether the first transaction should precede the second in the sorted list
********************************************************/
bool compare_transactions(transaction, transaction, int);

/********************************************************
** Function: swap
** Description: swaps two transactions
** Input: transaction 1, transaction 2
** Pre-Conditions: none
** Post-Conditions: transactions are swapped
********************************************************/
void swap(transaction &, transaction &);

/********************************************************
** Function: is_ordered
** Description: Returns whether the transaction list is in the right order
** Input: transaction array, num_transactions, category
** Pre-Conditions: category stores a valid category
** Post-Conditions: Returns whether the transaction list is in the right order
********************************************************/
bool is_ordered(transaction *, int, int);

/********************************************************
** Function: sort_transactions
** Description: Sorts transactions based on the specified category
** Input: transactions array, num_transactions, category
** Pre-Conditions: category stores a valid category
** Post-Conditions: The transactions array is sorted
********************************************************/
void sort_transactions(transaction *, int, int);

/********************************************************
** Function: get_num_transactions
** Description: gets the total number of transactions
** Input: budgets array, size of budgets array
** Pre-Conditions: size stores the size of the budgets array
** Post-Conditions: Returns the total number of transactions
********************************************************/
int get_num_transactions(budget *, int);

/********************************************************
** Function: run_stuff
** Description: runs stuff and gets inputs and stuff
** Input: choices from the user
** Pre-Conditions: sizes of respective things are accurate
** Post-Conditions: stuff runs
********************************************************/
void run_stuff(user *, budget *, int, transaction *, int);

/********************************************************
** Function: output_stuff
** Description: outputs stuff, depending on how the user wants stuff to output
** Input: budgets transaction array, size, option
** Pre-Conditions: size stores the size of the transaction array
** Post-Conditions: stuff is outputted
********************************************************/
void output_stuff(transaction *, int, int);

/********************************************************
** Function: choose_stuff
** Description: gets choice from user
** Input: nothin'
** Pre-Conditions: none
** Post-Conditions: choice from user is returned
********************************************************/
int choose_stuff();


#endif
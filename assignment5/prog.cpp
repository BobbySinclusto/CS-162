/***************************************************************************
** File: prog.cpp
** Author: Allen Benjamin
** Date: 03/14/2020
** Description: Shows off my epic linked list implementation
**************************************************************************/

#include "Linked_List.hpp"
#include "helper_functions.h"

/********************************************************
** Function: test_signed()
** Description: gets input from the user, tests the list
** Input: none
** Pre-Conditions: none
** Post-Conditions: the list is tested, results are displayed
********************************************************/
void test_signed();

/********************************************************
** Function: test_unsigned()
** Description: gets input from the user, tests the list
** Input: list of unsigned integers to test
** Pre-Conditions: none
** Post-Conditions: the list is tested, results are displayed
********************************************************/
void test_unsigned();

/********************************************************
** Function: main()
** Description: gets user input, creates a list, displays results
** Input: none
** Pre-Conditions: none
** Post-Conditions: results are displayed
********************************************************/
int main() {
    do {
        if (get_input_dichotomy("Would you like to create a list of signed or unsigned integers? (s/u): ", 's', 'u')) {
            test_signed();
        }
        else {
            test_unsigned();
        }
    } while (get_input_dichotomy("Would you like to do this again? (y/n): ", 'y', 'n'));
    
    return 0;
}

void test_unsigned() {
    Linked_List<unsigned int> l;
    do {
        l.push_back(get_unsigned_int("Enter a positive number: "));
    } while (get_input_dichotomy("Would you like to add another number? (y/n): ", 'y', 'n'));
    if (get_input_dichotomy("Sort ascending or descending? (a/d): ", 'a', 'd')) {
        l.sort_ascending();
    }
    else {
        l.sort_descending();
    }
    cout << "Your linked list is: ";
    l.print();
    unsigned int primes = l.count_primes();
    cout << "You have " << primes << " prime number" << (primes == 1 ? "" : "s") << " in your list." << endl;
}

void test_signed() {
    Linked_List<int> l;
    do {
        l.push_back(get_int("Enter a number: "));
    } while (get_input_dichotomy("Would you like to add another number? (y/n): ", 'y', 'n'));
    if (get_input_dichotomy("Sort ascending or descending? (a/d): ", 'a', 'd')) {
        l.sort_ascending();
    }
    else {
        l.sort_descending();
    }
    cout << "Your linked list is: ";
    l.print();
    unsigned int primes = l.count_primes();
    cout << "You have " << primes << " prime number" << (primes == 1 ? "" : "s") << " in your list." << endl;
}
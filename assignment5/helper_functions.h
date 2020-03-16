/***************************************************************************
** File: helper_functions.h
** Author: Allen Benjamin
** Date: 01/16/2020
** Description: Some helpful functions that I used in some of the classes
**************************************************************************/

#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include <iostream>

using namespace std;

/********************************************************
** Function: get_unsigned_int()
** Description: gets an unsigned int from the user, making sure it is valid
** Input: string prompt
** Pre-Conditions: none
** Post-Conditions: returns the unsigned int that the user inputs
********************************************************/
unsigned int get_unsigned_int(string);

/********************************************************
** Function: get_int()
** Description: gets an int from the user, making sure it is valid
** Input: string prompt
** Pre-Conditions: none
** Post-Conditions: returns the int that the user inputs
********************************************************/
int get_int(string);

/********************************************************
** Function: get_input_dichotomy()
** Description: gets input from the user, making sure it is one of two provided characters
** Input: prompt
** Pre-Conditions: none
** Post-Conditions: returns the choice that the user chooses as a bool
********************************************************/
bool get_input_dichotomy(string, char, char);

#endif
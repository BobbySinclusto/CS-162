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
** Function: get_input_range()
** Description: gets input from the user, making sure it is in the specified range
** Input: prompt, min, max
** Pre-Conditions: none
** Post-Conditions: returns the choice that the user chooses, an int between min and max
********************************************************/
int get_input_range(string, int, int);

#endif
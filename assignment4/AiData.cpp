/***************************************************************************
** File: AiData.cpp
** Author: Allen Benjamin
** Date: 02/29/2020
** Description: holds data for the AI and does some processing
**************************************************************************/

#include "AiData.h"
#include <string>

using namespace std;

AiData::AiData() {
	seen = false;
	verified = false;
	event = 0;	
}

bool AiData::was_seen() {
	return seen;
}

bool AiData::is_verified() {
	return verified;
}

char AiData::get_event() {
	return event;
}

void AiData::update(int row, int col, string adj) {
	if (verified) return;
	seen = true;
	if (adj == "") {
		verified = true;
		return;
	}
	for (unsigned int i = 0; i < p_rows.size(); ++i) {
		if (p_rows[i] == row && p_cols[i] == col) {
			return;
		}
		for (unsigned int j = 0; j < p_rows.size(); ++j) {
			if (adjacents[i].find(adj.at(j)) != string::npos) {
				verified = true;
				event = adj.at(j);
				return;
			}
		}
	}
	p_rows.push_back(row);
	p_cols.push_back(col);
	adjacents.push_back(adj);
}

void AiData::reset() {
	seen = false;
	verified = false;
	event = 0;
	p_rows.clear();
	p_cols.clear();
	adjacents.clear();
}
/*
Created by: Eli Madi
For: CSC28500 Team Project 02
Submitted: 2021 December 01
Instructor: Dr. Jeevanjee
*/

#include "head.hpp"
using namespace std;

//"inVector" is a funtion that checks if given vertex is in given vector:
bool inVector(const vertex* item, const vector<vertex>* list) {

	//if item is found in list, return true
	for (int i = 0; i < list->size(); i++) {
		if ((*list)[i].name() == item->name()) {
			return true;
		}
	}

	//else, return false
	return false;
}

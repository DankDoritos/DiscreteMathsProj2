/*
Created by: Eli Madi
For: CSC28500 Team Project 02
Submitted: 2021 December 01
Instructor: Dr. Jeevanjee
*/

#include "head.hpp"
using namespace std;

//"inGraph" is a function that checks if given vertex is in given vector and returns a pointer if that vertex is found:
vertex* inGraph(const char itemName, const vector<vertex*>* list) {

	//if item is found in list, return pointer to that vertex
	for (int i = 0; i < list->size(); i++) {
		if ((*list)[i]->name() == itemName) {
			return (*list)[i];
		}
	}

	//else, return NULL
	return NULL;
}

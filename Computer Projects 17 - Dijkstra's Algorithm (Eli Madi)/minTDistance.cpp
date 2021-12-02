/*
Created by: Eli Madi
For: CSC28500 Team Project 02
Submitted: 2021 December 01
Instructor: Dr. Jeevanjee
*/

#include "head.hpp"
using namespace std;

//"minTDistance" is a function that returns the edge pointing to a vertex with the smallest tDistance in a given vector
vertex* minTDistance(vector<vertex*>* vertices) {

	//initialize min vertex pointer
	vertex* minPtr;
	vertex min('Z');
	minPtr = &min;

	//find min tDistance in vector
	for (int i = 0; i < vertices->size(); i++) {
		if (minPtr->tDistance() > (*vertices)[i]->tDistance()) {
			minPtr = (*vertices)[i];
		}
	}

	//return min pointer
	return minPtr;
}

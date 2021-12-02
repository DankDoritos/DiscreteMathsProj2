/*
Created by: Eli Madi
For: CSC28500 Team Project 02
Submitted: 2021 December 01
Instructor: Dr. Jeevanjee
*/

#ifndef _EDGE_HPP_
#define _EDGE_HPP_

#include "head.hpp"

//"Edge" is a class that stores a pointer to a vertex and a weight:
class edge {
private:
	
	//Instance variables:
	//Pointer to vertex
	vertex* _neighbor;
	//Weight
	int _weight;
	
public:
	
	//Constructors:
	edge() : _weight(INT_MAX) { _neighbor = NULL; return; }
	edge(vertex* neighbor, int weight) : _weight(weight) { _neighbor = neighbor; return; }
	
	//Accessors and Modifiers:
	vertex* neighbor() const { return _neighbor; }
	vertex*& neighbor() { return _neighbor; }

	int weight() const { return _weight; }
	int& weight() { return _weight; }
	
};

#endif

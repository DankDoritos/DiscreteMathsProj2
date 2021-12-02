/*
Created by: Eli Madi
For: CSC28500 Team Project 02
Submitted: 2021 December 01
Instructor: Dr. Jeevanjee
*/

#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include "head.hpp"

//"Graph" is a class that stores a vector of pointers to vertices:
class graph {
private:
	//Instance variables:
	//Vector of vertices
	std::vector<vertex*> _vertices;

public:
	//Constructors:
	graph(std::vector<vertex*> newGraph) { _vertices = newGraph;  return; }

	//Accessors and Modifiers:
	std::vector<vertex*> vertices() const { return _vertices; }
	std::vector<vertex*>& vertices() { return _vertices; }

};

#endif

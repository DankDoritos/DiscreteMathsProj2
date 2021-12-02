/*
Created by: Eli Madi
For: CSC28500 Team Project 02
Submitted: 2021 December 01
Instructor: Dr. Jeevanjee
*/

#ifndef _VERTEX_HPP_
#define _VERTEX_HPP_

#include "head.hpp"

//"Vertex" is a class that stores a name, tentative distance from source, and a vector of edges to its neighbors:
class vertex {
private:
	//Instance variables:
	//Name of vertex
	char _name;
	//Tentative distance from source
	int _tDistance;
	//Tentative path from source
	std::vector<vertex> _tPath;

	//Vector of edges to neighbors
	std::vector<edge> _neighbors;

public:
	//Constructors:
	//Initializes all new vertices to have a tentative distance equal to the max integer (any path should have a shorter distance than this)
	vertex(char name) : _name(name) { _tDistance = INT_MAX; return; }

	//Accessors and Modifiers:
	char name() const { return _name; }
	char& name() { return _name; }

	int tDistance() const { return _tDistance; }
	int& tDistance() { return _tDistance; }

	std::vector<vertex> tPath() const { return _tPath; }
	std::vector<vertex>& tPath() { return _tPath; }

	std::vector<edge> neighbors() const { return _neighbors; }
	std::vector<edge>& neighbors() { return _neighbors; }

};

#endif
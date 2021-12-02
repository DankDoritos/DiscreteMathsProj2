/*
Created by: Eli Madi
For: CSC28500 Team Project 02
Submitted: 2021 December 01
Instructor: Dr. Jeevanjee
*/

#include "head.hpp"
using namespace std;

//"dijkstraAlgorithm" is the function that starts running the logic for Dijkstra's Algorithm
void dijkstraAlgorithm(graph* currentGraph, vertex* source, vertex* destination) {

	//Initialize solutionPath and set source distance to 0
	vector<vertex> solutionPath;
	source->tDistance() = 0;

	//Initialize "current" and set as source
	vertex* current = source;

	//Initialize "visited" to keep track of where we've already been
	vector<vertex> visited;

	//Initialize "unvisited" to keep track of where we need to go next
	vector<vertex*>* unvisited = &currentGraph->vertices();

	//Recursive step: for each of current's neighbors, calculate distance from source
	neighborDistances(current, source, destination, &visited, unvisited, &solutionPath);

	return;
}

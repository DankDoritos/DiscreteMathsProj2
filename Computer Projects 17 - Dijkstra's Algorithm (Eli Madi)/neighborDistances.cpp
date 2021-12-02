/*
Created by: Eli Madi
For: CSC28500 Team Project 02
Submitted: 2021 December 01
Instructor: Dr. Jeevanjee
*/

#include "head.hpp"
using namespace std;

//"neighborDistances" is a function for calculating the tentative distances of all neighbors to current
bool neighborDistances(vertex* current, vertex* source, vertex* destination, vector<vertex>* visited, vector<vertex*>* unvisited, vector<vertex>* solution) {

	//Mark current as visited
	visited->push_back(*current);

	//Remove current from unvisited 
	for (int i = 0; i < unvisited->size(); i++) {
		if ((*unvisited)[i]->name() == current->name()) {
			unvisited->erase(unvisited->begin() + i);
		}
	}

	//Add current to solution path (will be removed later if the destination cannot be reached from this vertex)
	solution->push_back(*current);

	//Check if this is the destination (base case):
	if (current == destination) {

		//Add current vertex to the solution path
		current->tPath().push_back(*current);

		cout << "The shortest path from " << source->name() << " to " << destination->name() << " is: ";
		for (int i = 0; i < current->tPath().size(); i++) {
			if (i != 0) {
				cout << " -> ";
			}
			cout << current->tPath()[i].name();
		}
		cout << endl;

		cout << "The total length of this path is: " << current->tDistance() << endl;

		return true;
	}

	//First, we calculate the tDistances for each neighboring vertext through this one:

	//Initialize tentative distance and tentative path
	int tentativeDistance = INT_MAX;
	vector<vertex> tentativePath = current->tPath();
	tentativePath.push_back(*current);

	//for each neighbor in current
	for (int i = 0; i < current->neighbors().size(); i++) {

		//Calculate tentative distance through current node
		tentativeDistance = current->tDistance() + current->neighbors()[i].weight();

		//If tentativeDistance < the existing tDistance in this neighbor
		if (tentativeDistance < current->neighbors()[i].neighbor()->tDistance()) {

			//Assign tentativeDistance as new tDistance for this neighbor
			current->neighbors()[i].neighbor()->tDistance() = tentativeDistance;

			//Assign new tentativePath as new tPath for this neighbor
			current->neighbors()[i].neighbor()->tPath() = tentativePath;
		}
	}


	//Second, we move on to the unvisited vertices, starting with the one with the smallest tDistance:

	//Initialize pointer for next vertex to visit
	vertex* next;

	//Initialize vector for remaining vertices to check
	vector<vertex*> remaining = *unvisited;
	next = minTDistance(&remaining);

	//Recursive calls:
	//for every vertex in unvisited
	while (!remaining.empty()) {

		//Set next to min unvisited tDistance vertex
		next = minTDistance(&remaining);

		//if next is not in visited
		if (!inVector(next, visited)) {

			//Recursive call on next; if the destination is found, return (no need to keep searching)
			if (neighborDistances(next, source, destination, visited, unvisited, solution)) {
				return true;
			}

		}

		//Remove next from remaining 
		for (int i = 0; i < remaining.size(); i++) {
			if (remaining[i]->name() == next->name()) {
				remaining.erase(remaining.begin() + i);
			}
		}
	}

	//Remove current from solution path, as the destination could not be reached from this vertex
	solution->pop_back();

	return false;
}

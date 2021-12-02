/*
Created by: Eli Madi
For: CSC28500 Team Project 02
Submitted: 2021 December 01
Instructor: Dr. Jeevanjee
*/

#include "head.hpp"
using namespace std;

//"initVertex" initializes vertices and adds them to the graph
void initVertex(char newName1, char newName2, int weight, vector<vertex*>* newGraph) {

	//Initialize new vertex pointers
	vertex* newVertex1;
	vertex* newVertex2;

	//if newName1 is not in the graph already, initialize a vector with that name and add it to the graph
	if (!inGraph(newName1, newGraph)) {
		newVertex1 = new vertex(newName1);
		newGraph->push_back(newVertex1);
	}

	//if newName2 is not in the graph already, initialize a vector with that name and add it to the graph
	if (!inGraph(newName2, newGraph)) {
		newVertex2 = new vertex(newName2);
		newGraph->push_back(newVertex2);
	}

	//Find vertices in graph
	newVertex1 = inGraph(newName1, newGraph);
	newVertex2 = inGraph(newName2, newGraph);

	//Create new edges pointing to opposite vertex (1->2, 2->1)
	edge* newEdge1 = new edge(newVertex2, weight);
	edge* newEdge2 = new edge(newVertex1, weight);

	//Add edges to vertices
	newVertex1->neighbors().push_back(*newEdge1);
	newVertex2->neighbors().push_back(*newEdge2);

	return;
}

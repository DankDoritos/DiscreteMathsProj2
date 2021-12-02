/*
Created by: Eli Madi
For: CSC28500 Team Project 02
Submitted: 2021 December 01
Instructor: Dr. Jeevanjee
*/

#include "head.hpp"
using namespace std;

//"promptSD" prompts the user for a source and destination vertex and calls dijkstraAlgorithm if both vertices exist
void promptSD(vector<vertex*>* newGraph) {

	//Initialize source and destination pointers an name variables
	vertex* source;
	vertex* destination;

	char sourceName;
	char destinationName;

	//Prompt user for source
	cout << "Please enter a source vertex: ";
	cin >> sourceName;

	//Check if source exists in graph
	while (!inGraph(sourceName, newGraph)) {
		cout << "Vertex ['" << sourceName << "'] could not be found in this graph. \nPlease enter a source vertex that exists in this graph: ";
		cin >> sourceName;
		cout << endl << endl;
	}

	//Assign source to vertex with source name
	source = inGraph(sourceName, newGraph);
	cout << "Source chosen: " << source->name() << endl << endl;

	//Prompt user for destination
	cout << "Please enter a destination vertex: ";
	cin >> destinationName;

	//Check if source exists in graph
	while (!inGraph(destinationName, newGraph)) {
		cout << "Vertex ['" << destinationName << "'] could not be found in this graph. \nPlease enter a source vertex that exists in this graph: ";
		cin >> destinationName;
		cout << endl << endl;
	}

	//Assign source to vertex with source name
	destination = inGraph(destinationName, newGraph);
	cout << "Destination chosen: " << destination->name() << endl << endl;


	//Initialize graph toSolve
	graph toSolve(*newGraph);

	//Call dijkstraAlgorithm on graph, source, and destination
	dijkstraAlgorithm(&toSolve, source, destination);

	return;
}

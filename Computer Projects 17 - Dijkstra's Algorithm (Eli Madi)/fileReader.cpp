/*
Created by: Eli Madi
For: CSC28500 Team Project 02
Submitted: 2021 December 01
Instructor: Dr. Jeevanjee
*/

#include "head.hpp"
using namespace std;

//"fileReader" uses a file to initialize a new graph and calls dijkstraAlgorithm to solve that graph
void fileReader() {

	//Prompt the user to get the file name
	string filename = prompt();

	//Create file stream
	ifstream file(filename);

	//Initialize vector of vertex pointers that will be used to initialize our graph
	vector<vertex*> newGraph;
	//char for storing vertex names
	char newName1;
	char newName2;
	int weight;

	//while the file stream is not empty
	while (file >> newName1) {
		//Get first line in file and set to respective variables
		file >> newName2;
		file >> weight;

		//Call initialize on these variables, creating the vertices if they do not exist already and edges between them;
		initVertex(newName1, newName2, weight, &newGraph);
	}

	//Feedback to show the user what vertices are in this graph
	cout << "Vertices in this graph: ";
	for (int i = 0; i < newGraph.size(); i++) {
		cout << newGraph[i]->name() << " ";
	}
	cout << endl << endl;

	//Prompt user for source and destination (this function also calls dijkstraAlgorithm)
	promptSD(&newGraph);

	return;
}

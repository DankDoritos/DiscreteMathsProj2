/*
Created by: Eli Madi
For: CSC28500 Team Project 02
Submitted: 2021 December 01
Instructor: Dr. Jeevanjee
*/

//This header file contains prototypes for all of the classes and functions used in this program

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

#include "graph.hpp"
#include "vertex.hpp"
#include "edge.hpp"

//Classes:
class graph;
class vertex;
class edge;

//Functions:
void dijkstraAlgorithm(graph* currentGraph, vertex* source, vertex* destination);
vertex* inGraph(const char itemName, const std::vector<vertex*>* list);
void initVertex(char newName1, char newName2, int weight, std::vector<vertex*>* newGraph);
bool inVector(const vertex* item, const std::vector<vertex>* list);
void fileReader();
vertex* minTDistance(std::vector<vertex*>* vertices);
bool neighborDistances(vertex* current, vertex* source, vertex* destination, std::vector<vertex>* visited, std::vector<vertex*>* unvisited, std::vector<vertex>* solution);
std::string prompt();
void promptSD(std::vector<vertex*>* newGraph);

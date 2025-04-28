// Copyright kh155 2025
// helper functions for network.cc
#ifndef HELPER_FUNCTIONS_H_
#define HELPER_FUNCTIONS_H_

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<queue>
using std::vector;
using std::string;

// reads matrix from file and stores it in a 2D vector
vector<vector<int>> getMatrix();

// writes answer to a new text file
void writeAnswer(string);

// checks whether a graph has loops
bool hasLoops(vector<vector<int>>);

// checks if graph is connected using breadth first search
bool isConnected(vector<vector<int>>);

// all following functions assume graph has no loops and is connected

// checks if graph is fully connected
bool isFullyConnected(vector<vector<int>>);

// checks if graph is a ring
bool isRing(vector<vector<int>>);

// checks if graph is a star
bool isStar(vector<vector<int>>);

#endif  // HELPER_FUNCTIONS_H_

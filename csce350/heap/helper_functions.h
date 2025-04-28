// Copyright kh155
// helper functions for min_heap.cc and max_heap.cc
#ifndef HELPER_FUNCTIONS_H_
#define HELPER_FUNCTIONS_H_

#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<chrono>

using std::vector;
using std::string;

// gets values from file and stores them in a vector
vector<int> getArray();

// constructs a min heap
vector<int> minHeap(vector<int>);

// constructs a max heap
vector<int> maxHeap(vector<int>);

// writes answer to file output.txt
void writeAnswer(vector<int>, std::chrono::duration<double>);

#endif  // HELPER_FUNCTIONS_H_

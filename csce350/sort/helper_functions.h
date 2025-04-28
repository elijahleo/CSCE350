// Copyright kh155 2025
// helper functions for sort.cc
#ifndef HELPER_FUNCTIONS_H_
#define HELPER_FUNCTIONS_H_

#include<chrono>
#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<string>

using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
using std::vector;
using std::string;
using std::floor;

// gets values from file and stores them in a vector
vector<float> getArray();

// handles merging for MergeSort
vector<float> merge(vector<float>, vector<float>);

// implements MergeSort
vector<float> mergeSort(vector<float>);

// swaps two elements in an array
void mySwap(vector<float>*, int, int);

// partitions for QuickSort
int partition(vector<float>*, int, int);

// implements QuickSort
void quickSort(vector<float>*, int, int);

// writes answer to a file
void writeAnswer(vector<float>, vector<float>, std::chrono::duration<double>,
                 std::chrono::duration<double>);

#endif  // HELPER_FUNCTIONS_H_

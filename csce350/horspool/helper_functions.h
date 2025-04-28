// Copyright kh155 2025
// helper functions for horspool.cc

#ifndef HELPER_FUNCTIONS_H_
#define HELPER_FUNCTIONS_H_

#include<vector>
#include<chrono>
#include<iostream>
#include<fstream>
#include<string>

using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
using std::string;
using std::vector;

// generates shift table for a given pattern
vector<int> getShiftTable(string);

// writes answer to output.txt
void writeAnswer(int, std::chrono::duration<double>);

#endif  // HELPER_FUNCTIONS_H_

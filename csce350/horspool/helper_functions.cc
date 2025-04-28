// Copyright kh155 2025
// helper functions for horspool.cc
#include<vector>
#include<chrono>
#include<iostream>
#include<fstream>
#include<string>
#include"helper_functions.h"

using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
using std::string;
using std::vector;

// generates shift table for a given pattern
vector<int> getShiftTable(string pattern) {
  int m = pattern.size();
  vector<int> shift_table;
  for (int i = 0; i < 27; i++) {
    shift_table.push_back(m);
  }
  for (int j = 0; j < m - 1; j++) {
    char val = shift_table[pattern[j]];
    if (val == ' ') {
      shift_table[26] = m - 1 - j;
    } else {
      shift_table[pattern[j] - 'a'] = m - 1 - j;
    }
  }
  return shift_table;
}

// writes answer to output.txt
void writeAnswer(int index, std::chrono::duration<double> t) {
  std::ofstream file;
  file.open("output.txt");
  if (file.is_open()) {
    file << "Index: " << index << std::endl;
    file << "Algorithm time: " << t.count() << " seconds" << std::endl;
    file.close();
  } else {
    // problem opening file
    std::cerr << "Unable to open output.txt" << std::endl;
  }
}

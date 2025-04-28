// Copyright kh155 2025
#include<chrono>
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"helper_functions.h"

using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
using std::string;
using std::vector;

// note: assumes all letters are lowercase
int main() {
  // get pattern and text
  std::ifstream file("input.txt");
  string pattern;
  string text;

  if (file.is_open()) {
    std::getline(file, pattern);
    std::getline(file, text);
  } else {
    // in case error in opening file
    std::cerr << "Error in opening file" << std::endl;
  }

  TimePoint start = std::chrono::high_resolution_clock::now();
  int m = pattern.length();
  int n = text.length();
  vector<int> shift_table = getShiftTable(pattern);
  int index = -1;

  // Horspool's algorithm
  int i = m - 1;
  while (i <= n - 1) {
    int k = 0;
    while (k <= m - 1 && pattern[m - 1 - k] == text[i - k]) {
      k = k + 1;
    }
    if (k == m) {
      index = i - m + 1;
      TimePoint stop = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double> t = stop - start;
      writeAnswer(index, t);
      return 0;
    } else {
      int amount;
      if (text[i] == ' ') {
        amount = shift_table[26];
      } else {
        amount = shift_table[text[i] - 'a'];
      }
      i = i + amount;
    }
  }
  TimePoint stop = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> t = stop - start;

  writeAnswer(index, t);
  return 0;
}

// Copyright kh155 2025
// helper functions for min_heap.cc and max_heap.cc
#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<cmath>
#include<sstream>
#include"helper_functions.h"

using std::vector;
using std::string;
using std::floor;

// gets values from file and stores them in a vector
vector<int> getArray() {
  std::ifstream file("input.txt");
  string line;
  vector<int> array;

  if (file.is_open()) {
    std::getline(file, line);  // skips through first line
    if (std::getline(file, line)) {
      std::stringstream ss(line);
      string token;
      while (ss >> token) {
        array.push_back(std::stoi(token));
      }
    }
    file.close();
  } else {
    // in case error in opening file
    std::cerr << "Error in opening file" << std::endl;
  }
  return array;
}

// constructs a min heap
vector<int> minHeap(vector<int> array) {
  int size = array.size();
  for (int i = std::ceil(size/2) - 1; i >= 0; i--) {
    int k = i;
    int v = array[k];
    bool is_heap = false;
    while (!is_heap && 2*k+1 < size) {
      int j = 2*k+1;
      if (j < size-1) {
        if (array[j] >= array[j+1]) {
          j = j+1;
        }
      }
      if (v <= array[j]) {
        is_heap = true;
      } else {
        array[k] = array[j];
        k = j;
      }
    }
    array[k] = v;
  }
  return array;
}

// constructs a max heap
vector<int> maxHeap(vector<int> array) {
  int size = array.size();
  for (int i = std::ceil(size/2) - 1; i >= 0; i--) {
    int k = i;
    int v = array[k];
    bool is_heap = false;
    while (!is_heap && 2*k+1 < size) {
      int j = 2*k+1;
      if (j < size-1) {
        if (array[j] < array[j+1]) {
          j = j+1;
        }
      }
      if (v >= array[j]) {
        is_heap = true;
      } else {
        array[k] = array[j];
        k = j;
      }
    }
    array[k] = v;
  }
  return array;
}

// writes answer to file output.txt
void writeAnswer(vector<int> array, std::chrono::duration<double> t) {
  std::ofstream file;
  file.open("output.txt");
  if (file.is_open()) {
    int size = array.size();
    file << "Heap:";
    for (int i = 0; i < size; i++) {
      file << " " << array[i];
    }
    file << std::endl;

    file << "HeapBottomUp time: " << t.count() << " seconds" << std::endl;
    file.close();
  } else {
    std::cerr << "Unable to open output.txt" << std::endl;
  }
}

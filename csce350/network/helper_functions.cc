// Copyright kh155 2025
// helper functions for network.cc
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<queue>
#include<sstream>
#include"helper_functions.h"

using std::vector;
using std::string;
using std::queue;

// reads matrix from file and stores it in a 2D vector
vector<vector<int>> getMatrix() {
  std::ifstream file("input.txt");
  string line;
  vector<vector<int>> matrix;

  if (file.is_open()) {
    while (std::getline(file, line)) {
      vector<int> row;
      std::stringstream ss(line);
      string num;
      while (ss >> num) {
        row.push_back(std::stoi(num));
      }
      matrix.push_back(row);
    }
    file.close();
  } else {
    // in case error in opening file
    std::cerr << "Error in opening file" << std::endl;
  }
  return matrix;
}

// checks whether a graph has loops
bool hasLoops(vector<vector<int>> matrix) {
  int n = matrix.size();
  for (int i = 0; i < n; i++) {
    if (matrix[i][i] != 0)
      return true;
  }
  return false;
}

// checks whether a graph is connected
bool isConnected(vector<vector<int>> matrix) {
  int n = matrix.size();
  vector<bool> in_queue;
  for (int i = 0; i < n; i++) {
    in_queue.push_back(false);
  }
  queue<int> to_visit;
  to_visit.push(0);  // starts at node 0
  while (!to_visit.empty()) {
    int node = to_visit.front();
    to_visit.pop();
    in_queue[node] = true;
    for (int i = 0; i < n; i++) {
      // if find a connection to a node that hasn't already been in the queue
      if (matrix[node][i] == 1 && !in_queue[i]) {
        to_visit.push(i);
        in_queue[i] = true;
      }
    }
  }

  // if a node was not visited, return false
  for (int i = 0; i < n; i++) {
    if (!in_queue[i]) {
      return false;
    }
  }
  return true;
}

// all following functions assume graph has no loops and is connected

// checks if a graph is fully connected
bool isFullyConnected(vector<vector<int>> matrix) {
  int n = matrix.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j && matrix[i][j] != 1) {
        return false;
      }
    }
  }
  return true;
}

// checks if a graph is a ring
// since assumes graph is connected & no loops,
// only need to show each row has exactly two 1's
bool isRing(vector<vector<int>> matrix) {
  int n = matrix.size();
  for (int i = 0; i < n; i++) {
    int one_count = 0;
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == 1) {
        one_count++;
      }
    }
    if (one_count != 2) {
      return false;
    }
  }
  return true;
}

// checks if a graph is a star
bool isStar(vector<vector<int>> matrix) {
  int n = matrix.size();

  // scans row 0 first
  int one_count = 0;
  int one_index = -1;
  for (int i = 0; i < n; i++) {
    if (matrix[0][i] == 1) {
      one_count++;
      one_index = i;
    }
  }

  if (one_count == n - 1) {  // node 0 is the center
    for (int i = 1; i < n; i++) {
      if (matrix[i][0] != 1) {
        return false;
      }
      for (int j = 1; j < n; j++) {
        if (matrix[i][j] != 0) {
          return false;
        }
      }
    }
  } else if (one_count == 1) {  // the node in one_index is the center
    // checks that row one_index has n - 1 ones
    int row_count = 0;
    for (int i = 0; i < n; i++) {
      if (matrix[one_index][i] == 1) {
        row_count++;
      }
    }
    if (row_count != n - 1) {
      return false;
    }
    // checks other rows
    for (int i = 1; i < n; i++) {
      if (i != one_index) {
        for (int j = 0; j < n; j++) {
          if (j == one_index && matrix[i][j] == 0) {
            return false;
          }
          if (j != one_index && matrix[i][j] == 1) {
            return false;
          }
        }
      }
    }
  } else {
    return false;  // if row 0 doesn't have 1 or n - 1 ones
  }
  return true;
}

// writes answer to a file
void writeAnswer(string answer) {
  std::ofstream file;
  file.open("output.txt");
  if (file.is_open()) {
    file << answer;
    file.close();
  } else {
    std::cerr << "Unable to open output.txt" << std::endl;
  }
}

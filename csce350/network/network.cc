// Copyright kh155 2025
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<queue>
#include"helper_functions.h"

using std::vector;
using std::string;

// matrix is size nxn
// text file stored with spaces between number entries
int main() {
  vector<vector<int>> matrix = getMatrix();

  bool is_fully_connected = false;
  bool is_ring = false;
  bool is_star = false;
  bool has_loops = hasLoops(matrix);
  bool is_connected = isConnected(matrix);

  // if graph is connected and has no loops
  if (is_connected && !has_loops) {
    is_fully_connected = isFullyConnected(matrix);
    is_ring = isRing(matrix);
    is_star = isStar(matrix);
  }

  string answer;
  if (is_fully_connected) {
    answer = "fully connected";
  } else if (is_ring) {
    answer = "ring";
  } else if (is_star) {
    answer = "star";
  } else {
    answer = "none";
  }

  writeAnswer(answer);
  return 0;
}

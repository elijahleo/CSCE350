// Copyright kh155 2025
#include<vector>
#include<limits>
#include<string>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<sstream>

using std::string;
using std::vector;

// file has non-edges represented as "inf"
int main() {
  float inf = std::numeric_limits<float>::infinity();

  std::ifstream file("input.txt");
  string line;
  vector<vector<float>> matrix;
  if (file.is_open()) {
    while (std::getline(file, line)) {
      std::stringstream ss(line);
      std::string value;
      vector<float> row;
      while (ss >> value) {
        if (value == "inf") {
          row.push_back(inf);
        } else {
	  row.push_back(std::stof(value));
        }
      }
      matrix.push_back(row);
    }
  file.close();
  } else {
    // in case error in opening file
    std::cerr << "Error in opening file" << std::endl;
  }

  // Floyd's algorithm
  vector<vector<float>> D = matrix;
  int n = D.size();

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        float temp = D[i][k] + D[k][j];
        if (D[i][k] == inf || D[k][j] == inf) {
          temp = inf;
        }
        D[i][j] = std::min(D[i][j], temp);
      }
    }
  }

  // writes resulting distance matrix D to output.txt
  std::ofstream file_w("output.txt");
  if (file_w.is_open()) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        float val = D[i][j];
        if (val == inf) {
          file_w << "inf" << " ";
        } else {
        file_w << val << " ";
        }
      }
      file_w << std::endl;
    }
  } else {
    // if problem opening file
    std::cerr << "Unable to open output.txt" << std::endl;
  }
  return 0;
}

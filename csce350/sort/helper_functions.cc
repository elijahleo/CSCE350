// Copyright kh155 2025
// helper functions for sort.cc
#include"helper_functions.h"
#include<chrono>
#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<sstream>

using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
using std::vector;
using std::string;
using std::floor;

// gets values from file and stores them in a vector
vector<float> getArray() {
  std::ifstream file("input.txt");
  string line;
  vector<float> array;

  if (file.is_open()) {
    while (std::getline(file, line)) {
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

// handles merging for MergeSort
vector<float> merge(vector<float> B, vector<float> C) {
  int p = B.size();
  int q = C.size();
  int i = 0;
  int j = 0;

  vector<float> sorted;

  while (i < p && j < q) {
    if (B[i] <= C[j]) {
      sorted.push_back(B[i]);
      i++;
    } else {
      sorted.push_back(C[j]);
      j++;
    }
  }
  if (i == p) {
    while (j < q) {
      sorted.push_back(C[j]);
      j++;
    }
  } else {
    while (i < p) {
      sorted.push_back(B[i]);
      i++;
    }
  }
  return sorted;
}

// implements MergeSort
vector<float> mergeSort(vector<float> A) {
  int n = A.size();
  if (n == 1) {
    return A;
  }

  vector<float> B;
  vector<float> C;
  int div = floor(n/2);
  for (int i = 0; i < n; i++) {
    if (i < div) {
      B.push_back(A[i]);
    } else {
      C.push_back(A[i]);
    }
  }

  B = mergeSort(B);
  C = mergeSort(C);
  A = merge(B, C);

  return A;
}

// swaps two elements in an array
void mySwap(vector<float>* A, int i, int j) {
  vector<float>& A_ = *A;
  float temp = A_[i];
  A_[i] = A_[j];
  A_[j] = temp;
}

// partitions for QuickSort
int partition(vector<float>* A, int l, int r) {
  vector<float>& A_ = *A;
  int p = A_[l];
  int i = l+1;
  int j = r;

  while (i <= j) {
    while (A_[i] < p && i < r) {
      i++;
    }
    while (A_[j] > p && j > l) {
      j--;
    }
    mySwap(A, i, j);
  }
  mySwap(A, i, j);
  mySwap(A, l, j);
  return j;
}

// implements QuickSort
void quickSort(vector<float>* A, int l, int r) {
  if (l < r) {
    int s = partition(A, l, r);
    quickSort(A, l, s-1);
    quickSort(A, s+1, r);
  }
}

// writes answer to a file
void writeAnswer(vector<float> arr1, vector<float> arr2,
                std::chrono::duration<double> t1,
                std::chrono::duration<double> t2) {
  std::ofstream file;
  file.open("output.txt");
  if (file.is_open()) {
    int n = arr1.size();
    file << "Merge sort:";
    for (int i = 0; i < n; i++) {
      file << " " << arr1[i];
    }
    file << std::endl;

    file << "Merge sort time: " << t1.count() << " seconds" << std::endl;
    file << "Quick sort:";
    for (int i = 0; i < n; i++) {
      file << " " << arr2[i];
    }
    file << std::endl;

    file << "Quick sort time: " << t2.count() << " seconds" << std::endl;
    file.close();
  } else {
    std::cerr << "Unable to open output.txt" << std::endl;
  }
}

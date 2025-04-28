// Copyright kh155 2025
// implements HeapBottomUp for a min heap
#include<vector>
#include<chrono>
#include<iostream>
#include<fstream>
#include"helper_functions.h"

using std::vector;
using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;

int main() {
  vector<int> array = getArray();

  TimePoint start = std::chrono::high_resolution_clock::now();
  vector<int> heap = minHeap(array);
  TimePoint stop = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> t = stop - start;

  writeAnswer(heap, t);
  return 0;
}

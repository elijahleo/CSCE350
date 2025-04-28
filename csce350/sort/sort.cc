// Copyright kh155 2025
#include<chrono>
#include<iostream>
#include<fstream>
#include<vector>
#include"helper_functions.h"

using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
using std::string;
using std::vector;

int main() {
  vector<float> array1 = getArray();
  vector<float> array2 = array1;

  TimePoint start1 = std::chrono::high_resolution_clock::now();
  array1 = mergeSort(array1);
  TimePoint stop1 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> t1 = stop1 - start1;

  TimePoint start2 = std::chrono::high_resolution_clock::now();
  quickSort(&array2, 0, static_cast<int>(array2.size())-1);
  TimePoint stop2 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> t2 = stop2 - start2;

  writeAnswer(array1, array2, t1, t2);
  return 0;
}

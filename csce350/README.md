<!--
To compile each program, go into the corresponding folder and run "make all"
"input.txt" file should be placed in the corresponding problem's folder
For example, if testing Problem 1, "input.txt" should be in the "network" folder
When writing input, do not include spaces at the ends of lines or extra lines after the input
PROBLEM-SPECIFIC DIRECTIONS

Problem 1
* Code is in "network" folder
* Write input boolean matrix in "input.txt", with a single space between each
  array element
* Matrix is assumed to be square and symmetrical
* Call program with command "./network"
* Output (either "ring", "star", "fully connected", or "none")
  will be written to "output.txt"
* Example input:
0 1 1 1
1 0 1 1
1 1 0 1
1 1 1 0

Problem 2
* Code is in "sort" folder
* Write input float numbers in "input.txt" as a single line with a single
  space between each number
* Call program with command "./sort"
* This command will perform both MergeSort and QuickSort
* The result of sorting the numbers by MergeSort and QuickSort will be written
  in "output.txt", along with the time taken by each sorting algorithm
* Example input:
5 3 1 9 8 2 4 7

Problem 3
* Code is in "heap" folder
* Write input in "input.txt"; the first line should have a single number
  that is the total number of keys, and the second line contains the
  key values, separated by a space
* To create a max heap, run "./max_heap"
* To create a min heap, run "./min_heap"
* The output (a heap in array form) along with the runtime of the algorithm,
  will be written to "output.txt"
* Example input:
6
2 9 7 6 5 8

Problem 4
* Code is in "horspool" folder
* Write input in "input.txt"; first line should contain pattern and
  second line should contain text in which to search for the pattern
* Code assumes pattern and text will only contain spaces (' ') and the
  26 lowercase letters of the English alphabet
* Call program with "./horspool"
* Output (the index starting at which the pattern is found for the first time,
  or -1 if the pattern is not found, and the runtime of the algorithm) is written
  to "output.txt"
* Example input:
elephant
abcdefgeait no elephant

Problem 5
* Code is in "floyd" folder
* Write input in "input.txt"; input should be a distance matrix containing
  non-negative floats. If two edges are not directly connected, the corresponding
  entry should be "inf". Entries should be separated by a space (' ')
* Assumes matrix is square
* Call program with "./floyd"
* Output: distance matrix with shortest path between any two points
* Example input:
0.1 inf 3.9 inf
2.433 0 inf inf
inf 7.8102 0 1
6.86 inf inf 0
--!>

# Project Directory Structure
csce350/
+-- floyd/
| +-- floyd.cc
| +-- Makefile
|
+-- heap/
| +-- helper_functions.cc
| +-- helper_functions.h
| +-- Makefile
| +-- max_heap.cc
| +-- min_heap.cc
|
+-- horspool/
| +-- helper_functions.cc
| +-- helper_functions.h
| +-- horspool.cc
| +-- Makefile
|
+-- network/
| +-- helper_functions.cc
| +-- helper_functions.h
| +-- Makefile
| +-- network.cc
|
+-- sort/
| +-- helper_functions.cc
| +-- helper_functions.h
| +-- Makefile
| +-- sort.cc
|
+-- README.md  # This file

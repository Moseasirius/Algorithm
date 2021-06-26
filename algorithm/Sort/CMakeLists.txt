cmake_minimum_required(VERSION 3.19)
project(Sort)

set(CMAKE_CXX_STANDARD 14)

add_executable(Sort main.cpp BubbleSort.h InsertionSort.h SelectionSort.h ShellSort.h MergeSort.h QuickSort.h HeapSort.h SortTestHelper.h test.h test.cpp)
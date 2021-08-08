cmake_minimum_required(VERSION 3.19)
project(TimeComplexity)

set(CMAKE_CXX_STANDARD 14)

add_executable(TimeComplexity main.cpp TimeComplexity.h CommonCodeForTimeComplexity.h MyAlgorithmTester.h MyUtil.h TimeComplexityExperiments.h RecursionTimeComplexity.h MyVector.h MyVector.cpp test.h)
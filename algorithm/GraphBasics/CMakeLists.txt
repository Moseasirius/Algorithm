cmake_minimum_required(VERSION 3.19)
project(GraphBasics)

set(CMAKE_CXX_STANDARD 14)

add_executable(GraphBasics main.cpp DenseGraph.h SparseGraph.h test.h ReadGraph.h Component.h Path.h ShortestPath.h)
cmake_minimum_required(VERSION 3.19)
project(ShortestPath)

set(CMAKE_CXX_STANDARD 14)

add_executable(ShortestPath main.cpp Edge.h DenseGraph.h SparseGraph.h IndexMinHeap.h ReadGraph.h Dijkstra.h test.h BellmanFord.h)
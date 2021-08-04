cmake_minimum_required(VERSION 3.19)
project(MinimumSpanTrees)

set(CMAKE_CXX_STANDARD 14)

add_executable(MinimumSpanTrees main.cpp DenseGraph.h Edge.h ReadGraph.h test.h SparseGraph.h MinHeap.h LazyPrimMST.h IndexMinHeap.h PrimMST.h KruskalMST.h UF.h)
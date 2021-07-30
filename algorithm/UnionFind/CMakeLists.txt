cmake_minimum_required(VERSION 3.19)
project(UnionFind)

set(CMAKE_CXX_STANDARD 14)

add_executable(UnionFind main.cpp UnionFind.h test.h UnionFindTestHelper.h)
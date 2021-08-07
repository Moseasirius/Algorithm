cmake_minimum_required(VERSION 3.19)
project(STLUsageTest)

set(CMAKE_CXX_STANDARD 14)

add_executable(STLUsageTest main.cpp testVector.h testDeque.h testString.h testList.h testMap.h testSet.h testQueque.h testStack.h testPriority_queue.h testAll.h)
cmake_minimum_required(VERSION 3.19)
project(TextIO)

set(CMAKE_CXX_STANDARD 14)

add_executable(TextIO main.cpp TextFileIO.h BinaryOutput.h Student.h Student.cpp SimpleFileIO.h TextFile.h RandomAccessFile.h UpdateFile.h)
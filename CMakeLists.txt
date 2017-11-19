cmake_minimum_required(VERSION 3.6)
project(reWriteDataStructure)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Heap.h MaxHeap.cpp sortTestHelper.h)
add_executable(reWriteDataStructure ${SOURCE_FILES})
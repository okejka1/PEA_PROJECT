cmake_minimum_required(VERSION 3.24)
project(PEA)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_BUILD_TYPE "Release")

set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-static")

add_executable(PEA main.cpp utils/Timer.cpp utils/Timer.h utils/Timer.h structures/Graph.cpp structures/Graph.h structures/Graph.h algorithms/BruteForce.cpp algorithms/BruteForce.h algorithms/BruteForce.h testers/AutomaticTester.cpp testers/AutomaticTester.h testers/AutomaticTester.cpp utils/FileRandomizer.cpp utils/FileRandomizer.h algorithms/BB.cpp algorithms/BB.h)

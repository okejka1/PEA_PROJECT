cmake_minimum_required(VERSION 3.24)
project(PEA)

set(CMAKE_CXX_STANDARD 20)

add_executable(PEA main.cpp utils/Timer.cpp utils/Timer.h utils/Timer.h structures/Graph.cpp structures/Graph.h structures/Graph.h algorithm/TPS.cpp algorithm/TPS.h algorithm/TPS.h Menu.cpp Menu.h Menu.h testers/AutomaticTester.cpp testers/AutomaticTester.h testers/Tester.cpp testers/Tester.h testers/Tester.h testers/AutomaticTester.cpp)

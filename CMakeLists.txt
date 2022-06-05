cmake_minimum_required(VERSION 3.21.1)
project(Diploma)

set(CMAKE_CXX_STANDARD 20)

add_executable(Diploma main.cpp src/Data/Vertex.hpp src/Data/Vertex.cpp src/Data/Edge.cpp src/Data/Edge.hpp src/Data/MetroMap.cpp src/Data/MetroMap.hpp src/Algorithms/GeneticAlgorithm.hpp src/Algorithms/GeneticAlgorithm.cpp src/Algorithms/LittleAlgorithm.cpp src/Algorithms/LittleAlgorithm.hpp src/matrix.hpp src/Data/Prima.cpp src/Data/Prima.hpp)

target_link_libraries(Diploma pthread)
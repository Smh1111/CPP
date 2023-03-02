
cmake_minimum_required(VERSION 3.10)

project(MyProject)


# Include the header files directory
include_directories(D:/KMITL\ University/1st\ year\ 2nd\ sem/OOP/3/Hw/No3)

# Create a library target for the utility functions
add_library(points STATIC D:/KMITL\ University/1st\ year\ 2nd\ sem/OOP/3/Hw/No3/points.cpp)

# Create an executable target for No3
add_executable(No3 D:/KMITL\ University/1st\ year\ 2nd\ sem/OOP/3/Hw/No3/No3.cpp)
target_link_libraries(No3 points)


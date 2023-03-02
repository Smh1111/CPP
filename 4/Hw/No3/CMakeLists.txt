cmake_minimum_required(VERSION 3.10)

project(MyProject)

# Include the header files directory
include_directories(D:/KMITL\ University/1st\ year\ 2nd\ sem/OOP/4/Hw/No3)

# Create a library target for the utility functions
add_library(pairs STATIC D:/KMITL\ University/1st\ year\ 2nd\ sem/OOP/4/Hw/No3/pair.cpp)

# Create an executable target for No2_1
add_executable(No3 D:/KMITL\ University/1st\ year\ 2nd\ sem/OOP/4/Hw/No3/No3.cpp)
target_link_libraries(No3 pairs)

cmake_minimum_required(VERSION 3.10)

project(MyProject)

# Include the header files directory
include_directories(D:/KMITL\ University/1st\ year\ 2nd\ sem/OOP/5/HW/No1)

# Create a library target for the utility functions
add_library(cmds STATIC D:/KMITL\ University/1st\ year\ 2nd\ sem/OOP/5/HW/No1/cmd.cpp)

# Create an executable target for No1
add_executable(No1 D:/KMITL\ University/1st\ year\ 2nd\ sem/OOP/5/HW/No1/No1.cpp)
target_link_libraries(No1 cmds)

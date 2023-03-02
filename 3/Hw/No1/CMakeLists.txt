cmake_minimum_required(VERSION 3.10)

project(MyProject)

# Include the header files directory
include_directories(D:/KMITL\ University/1st\ year\ 2nd\ sem/OOP/3/Hw/No1)

# Create a library target for the utility functions
add_library(unstylize STATIC D:/KMITL\ University/1st\ year\ 2nd\ sem/OOP/3/Hw/No1/unstylize.cpp)

# Create an executable target for unstylize
add_executable(No1_1 D:/KMITL\ University/1st\ year\ 2nd\ sem/OOP/3/Hw/No1/No1_1.cpp)
target_link_libraries(No1_1 unstylize)

# Create an executable target for No1_2
add_executable(No1_2 D:/KMITL\ University/1st\ year\ 2nd\ sem/OOP/3/Hw/No1/No1_2.cpp)
target_link_libraries(No1_2 unstylize)

# Create an executable target for No1_3
add_executable(No1_3 D:/KMITL\ University/1st\ year\ 2nd\ sem/OOP/3/Hw/No1/No1_3.cpp)
target_link_libraries(No1_3 unstylize)





cmake_minimum_required(VERSION 3.10)

project(MyProject)


# Include the header files directory
include_directories(D:/KMITL\ University/1st\ year\ 2nd\ sem/OOP/3/Hw/No2)

# Create a library target for the utility functions
add_library(scores STATIC D:/KMITL\ University/1st\ year\ 2nd\ sem/OOP/3/Hw/No2/scores.cpp)

# Create an executable target for No2_1
add_executable(No2_1 D:/KMITL\ University/1st\ year\ 2nd\ sem/OOP/3/Hw/No2/No2_1.cpp)
target_link_libraries(No2_1 scores)

# Create an executable target for No2_2
add_executable(No2_2 D:/KMITL\ University/1st\ year\ 2nd\ sem/OOP/3/Hw/No2/No2_2.cpp)
target_link_libraries(No2_2 scores)

# Create an executable target for No2_3
add_executable(No2_3 D:/KMITL\ University/1st\ year\ 2nd\ sem/OOP/3/Hw/No2/No2_3.cpp)
target_link_libraries(No2_3 scores)

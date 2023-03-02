cmake_minimum_required(VERSION 3.10)

project(acpp_ch03)

add_executable(avg avg.cpp)
add_executable(med med.cpp)

set(TARGETS avg med)

set_target_properties(
    ${TARGETS}
    PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO)

foreach(T ${TARGETS})
    if (MSVC)
        target_compile_options(${T} PRIVATE /Wall /WX)
    else()
        target_compile_options(${T} PRIVATE -Wall -Wextra)
    endif()
endforeach()

add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/single_grade
  COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/single_grade
    ${CMAKE_CURRENT_BINARY_DIR}/single_grade
  DEPENDS single_grade)

add_custom_target(
  data ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/single_grade)
